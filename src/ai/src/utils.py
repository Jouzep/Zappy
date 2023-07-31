from macro import *
import socket

def check_sight_value(sight:list, value:str, len:int=0) -> int:
    """Check how much of value are in the player sight

    Args:
        sight (list): Sight list
        value (str): Value we search
        len (int): Len of the sight, define to 0

    Returns:
        int: Number of value in the sigh
    """
    res = 0

    for i in sight[:len]:
        for j in i:
            if j == value:
                res += 1
    return res

def count_player(player_tile:list) -> int:
    """Count the number of player on the same tile

    Args:
        player_tile (list): Tile where are the player

    Returns:
        int: Numbre of player on the tile
    """
    res = 0
    for i in player_tile:
        if i == "player":
            res += 1
    return res


def check_dict(obj_dict: dict, inventory: dict):
    for key, value in obj_dict.items():
        if inventory[key] != inventory[key]:
            return False
    return True

def comp_obj(obj_list: dict, inventory: dict) -> bool:
    """check if the objective list and inventory are enough for an incantation

    Args:
        obj_list (dict): objective list
        inventory (dict): player's inventory

    Returns:
        bool: True if it's enough, False otherwise
    """
    tmp = obj_list.copy()
    del tmp[PLAYER]
    if check_dict(tmp, inventory):
        return True
    return False

def crypt(key:str, message:str) -> str:
    crypt_msg:str = ""
    for i in range(len(message)):
        crypt_msg += chr(ord(message[i]) ^ ord(key[i % len(key)]))
    return crypt_msg

def eventMessages(string:str) -> bool:
    if (len(string.split()) > 1 and string.split()[0] == "message"):
        # logic for catching broadcast
        print("MESSAGE FROM BROADCAST")
        return True
    if (len(string.split()) == 2 and string.split()[0] == "Elevation" and string.split()[1] == "underway"):
        # logic after getting freezed
        print("Get freezed")
        return True
    return False

def rcvFromatter(client_socket:socket, action:int=NORMAL) -> str:
    string:str = client_socket.recv(1024).decode()
    if (eventMessages(string)) or action == INCANTATION:
        string = client_socket.recv(1024).decode()
    return string