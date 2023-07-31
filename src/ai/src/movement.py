import random
import socket
from math import floor
from utils import *
from macro import *

class Movement:
    def __init__(self, client_socket:socket, objectives:list) -> None:
        """Initialize movement object for the player

        Args:
            client_socket (socket): the client socket, to send and receive value.
            objectives (list): The objectives list
        """
        self.cli_socket:socket = client_socket
        self.movementList:list = [FORWARD, FORWARD, RIGHT, LEFT]
        self.preMove:list = []
        self.costList:list = []
        self.objectiveList:list = []
        self.sightIdx:list = []
        self.itemObj:str = None
        for i in range(9):
            for n in range(i):
                self.costList.append((i * 2) + 1 - n)
            self.costList.append(i)
            for n in range(i, 0, -1):
                self.costList.append((i * 2) + 1 - (n - 1))
        self.setObjectivesList(objectives)

    def setObjectivesList(self, objectives:list) -> None:
        """Function that will update the goal variable with new objectives

        Args:
            objectives (list): new list of objectives
        """
        self.objectiveList = objectives

    def handleObjectives(self, objective:int) -> None:
        """Handle the path to the objectives adding Forward or turning value

        Args:
            objective (int): Being the tile the objectives is in, in the player's sight
        """
        tmp:int = 1
        sum:int = tmp
        for i in range(8):
            if objective == 0:
                break
            if sum < objective + 1 <= sum + tmp + 2:
                tmp = tmp + 2
                sum = sum + tmp
                for j in range(i + 1):
                    self.preMove.append(FORWARD)
                var = (objective + 1) - (sum - floor(tmp / 2))
                if var < 0:
                    self.preMove.append(LEFT)
                elif var > 0:
                    self.preMove.append(RIGHT)
                for i in range(abs(var)):
                    self.preMove.append(FORWARD)
                break
            tmp = tmp + 2
            sum = sum + tmp

    def getClosest(self, closeList:list, sight:list, item:list) -> None:
        """Get the closest objectives in the objectives list by doing some math and comparing
        every sight objectives path with the old one to check which is the cheapest one.

        Args:
            closeList (list): Being a list with every index of tile where we can find an objectives item
            sight (list): Sight is the vision array that the server sends us
            item (list): Being the item that the player need to look for, foor or check
            the list of objectives
        """
        tmp:int = min(closeList)
        tmpList:list = []
        tmpObjList:list = []
        for i in range(len(closeList)):
            if closeList[i] == tmp:
                tmpList.append(self.sightIdx[i])
                tmpObjList.append(closeList[i])
        self.sightIdx = tmpList
        tmp = random.choice(self.sightIdx)
        if len(self.preMove) > tmp or len(self.preMove) == 0:
            self.preMove = []
            self.handleObjectives(tmp)
            for i in range(len(item)):
                try:
                    sight[tmp].index(item[i])
                    self.itemObj = item[i]
                    break
                except ValueError:
                    continue

    def getActionCost(self, frequency:list) -> list:
        """Get action cost of every value found in the sight, currently in frequency array

        Args:
            frequency (list): array storing the tile where an objectives has been found in the sight array

        Returns:
            list: return the list of cost of every value in the list
        """
        tmpList:list = []
        for i in range(len(frequency)):
            tmpList.append(self.costList[frequency[i]])
            self.sightIdx.append(frequency[i])
        return tmpList
    
    def itemNotThereAnymore(self, sight:list) -> None:
        """Error handling function checking if the item is still on the tile after turning
        because the item will eventually get out of the AI sight.
        If the item does disappear the preMove list get emptied.

        Args:
            sight (list): Parsed array of the player's sight
        """
        inc:int = 0
        if self.preMove.count(LEFT) == 0 and self.preMove.count(RIGHT) == 0 and len(self.preMove) != 0:
            count:int = self.preMove.count(FORWARD)
            for i in range(1, count + 1):
                inc = inc + (2 * i)
            try:
                sight[inc].index(self.itemObj)
            except (ValueError, IndexError):
                self.itemObj = None
                self.preMove = []
    
    def checkFrequency(self, sight:list, liste:list, items:list) -> None:
        """Check the number of objectives present in the player's vision

        Args:
            sight (list): Parsed array for the vision
            liste (list): List made to save the index where the objective was found
            items (list): List of item the player need to find right now (Food or Objectives list)
        """
        for i in range(len(sight)):
            for j in range(len(items)):
                try:
                    sight[i].index(items[j])
                    liste.append(i)
                except ValueError:
                    continue

    
    def handleMovement(self, sight:list, needs:list) -> None:
        """Main function for handling the player's movement
        Act differenttly if the needs list is empty or not, will look for food or objectives,
        depending on it.

        Args:
            sight (list): The vision array sent by the server, and parsed by us
            needs (list): An array made so the the AI will start looking for food when his food bar is too low
        """
        self.sightIdx = []
        liste:list = []
        items:list = []
        self.itemNotThereAnymore(sight)
        if len(needs) != 0:
            items = ["food"]
        else:
            items = self.objectiveList.copy()
        self.checkFrequency(sight, liste, items)
        if len(liste) != 0 or len(self.preMove) != 0:
            if len(liste) != 0:
                self.getClosest(self.getActionCost(liste), sight, items)
            try:
                tmp:str = self.preMove.pop(0)
            except IndexError:
                self.itemObj = None
                tmp:str = random.choice(self.movementList)
        else:
            self.itemObj = None
            tmp:str = random.choice(self.movementList)
        # print(needs)
        self.lastMove = tmp
        self.cli_socket.send((tmp + "\n").encode())
        var:str = rcvFromatter(self.cli_socket)
        if (var == "ko"):
            self.preMove.insert(0, tmp)