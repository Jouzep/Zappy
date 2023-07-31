import socket
from utils import *
class Items:
    def __init__(self, client_socket:socket) -> None:
        """_summary_

        Args:
            client_socket (socket): _description_
        """
        self.client_socket:socket = client_socket

    def needsFood(self, inventory:list, ListFilled:list):
        try:
            if inventory["food"] < 5 and len(ListFilled) < 3:
                for i in range(3):
                    ListFilled.append("food")
        except KeyError:
            return

    def takeItem(self, sight:str, objectives:list, foodList:list, inventory:list) -> None:
        for i in range(len(objectives)):
            try:
                sight[0].index(objectives[i])
                self.client_socket.send(("Take " + objectives[i] + "\n").encode())
                res = rcvFromatter(self.client_socket)
                print(f"take = {res}")
                objectives.pop(i)
                break
            except ValueError:
                continue
        try:
            if inventory["food"] >= 20:
                return
            sight[0].index("food")
            self.client_socket.send(("Take food\n").encode())
            res = rcvFromatter(self.client_socket)
            print(f"take = {res}")
            if (len(foodList) > 0):
                foodList.pop(0)
        except ValueError:
            return
        except KeyError:
            return

    def setItem(self, itemToSet:str, objectives:list) -> str:
        self.client_socket.send(("Set " + itemToSet + "\n").encode())
        objectives.append(itemToSet)
        return_value = rcvFromatter(self.client_socket)
        print(f"set = {return_value}")
        return return_value