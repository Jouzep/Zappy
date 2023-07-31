from player import Player
from macro import *
import socket
from items import Items
from utils import count_player, rcvFromatter
from level import level

def drop_obj(inventory:dict, obj_list:dict, objectives:list, client_socket:socket) -> None:
    """drop stone of the objectif list for the incantation

    Args:
        inventory (dict): Player inventory
        obj_list (dict): Objectif list
        objectives (list): Objectif list of the player
        client_socket (socket): Client socket
    """
    items:Items = Items(client_socket)
    tmp = obj_list.copy()
    del tmp[PLAYER]

    for key, value in tmp.items():
        if inventory[key] == tmp[key]:
            items.setItem(key, objectives)

def split_lvl(return_value:str, actual_lvl:int) -> int:
    """parse the return value from the incantation

    Args:
        return_value (str): return value from incantation
        actual_lvl (int): actual level of the player

    Returns:
        int: level of the player
    """
    tmp = return_value.split(" ")
    print(tmp)
    if len(tmp) == 3:
        return int(tmp[2][0])
    return actual_lvl

def get_return_value(return_value:str, player:Player):
    """set the return value of an incantation to the player info

    Args:
        return_value (str): return value from incantation
        player (Player): player info
    """
    # if return_value == "Elevation underway\n":
    player.attitude = NORMAL
    player.level = split_lvl(return_value, player.level)
    player.obj_list = player.lvl_instance.setObj(player.level)
    player.set_item_needed()
    player.ask = False

def levelUp(player:Player, client_socket:socket) -> None:
    """Launche the incantation if he can

    Args:
        player (Player): player info
        client_socket (socket): client socket
    """
    player_needed = count_player(player.sight[0])
    # print(player.inventory)
    if len(player.item_needed) == 0 and player_needed == player.obj_list[PLAYER]:
        drop_obj(player.inventory, player.obj_list, player.item_needed, client_socket)
        client_socket.send(("Incantation\n").encode())
        elevation_ko = rcvFromatter(client_socket, INCANTATION)
        print(f"elevation = {elevation_ko}")
        if elevation_ko != "ko\n":
            get_return_value(elevation_ko, player)
