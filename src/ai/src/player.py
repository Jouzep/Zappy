from macro import *
from utils import check_sight_value
from level import level
import socket

class Player:
    def __init__(self, nb_player:int , player_level:int, team:str) -> None:
        """Init the player object

        Args:
            nb_player (_type_): _description_
            map_size (_type_): _description_
            player_level (_type_): _description_
        """
        self.team:str = team
        self.nb_player = nb_player
        self.team_mate = 1
        self.count_players = 1
        self.lvl_instance = level()
        self.obj_list = self.lvl_instance.setObj(player_level)
        self.level = player_level
        self.ask:bool = False
        self.inventory:dict
        self.sight:str
        self.attitude:int = NORMAL
        self.item_needed:list = []
        self.needList:list = []
        self.set_item_needed()

    def set_item_needed(self) -> None:
        self.item_needed.clear()
        for i in self.obj_list:
            if (i == "player"):
                continue
            else:
                for j in range(self.obj_list[i]):
                    self.item_needed.append(i)

    def multiplePlayerTile(self) -> bool:
        """check if there is a player on the same tile

        Returns:
            bool: true if there is a player or false if not
        """

        if check_sight_value(self.sight, "player") > 1:
            return True
        return False

    def analyse_sight(self) -> str:
        """Analyse the sight by converting a list to a dict

        Returns:
            str: The stone with the highest rarity and quantity
        """
        res = {item: 0 for item in items_list}
        for item in items_list:
            for i in self.sight:
                for j in i:
                    if j == item:
                        res[item] += 1
        value = check_density(res)
        if value is not None:
            return value
        return None

    def check_necessity(self) -> bool:
        """check if i only need player

        Returns:
            bool: True if i need or False
        """
        if len(self.item_needed) == 1 and check_sight_value(self.sight, PLAYER, len(self.sight)):
            return True
        return False

def check_density(my_dict: dict) -> str:
    """Check if there is a high density in the sight

    Args:
        my_dict (dict): Sight stones and quantity

    Returns:
        str: the stone with the highest quantity and rarity
    """
    freq = [2, 3, 4, 4, 5, 9, 20]
    key_list = list(reversed(my_dict.keys()))

    # for i in range(len(freq)):
        # if my_dict[key_list[i]] >= freq[i]:
            # return key_list[i]
    return None

def push(player:Player, client_socket:socket) -> None:
    """Send the command push if there is a player on the same tile

    Args:
        player (Player): Player info
        client_socket (socket): Socket of the client
    """
    if player.multiplePlayerTile():
        client_socket.send(("push\n").encode())
