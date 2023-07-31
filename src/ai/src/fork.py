from player import Player
from macro import *
from utils import check_sight_value

def no_food(sight:list, food:int) -> bool:
    """Check if i have food

    Args:
        sight (list): Sight list
        food (int): Quantity of food in my inventory

    Returns:
        bool: True if i don't have enough or False
    """
    if food < 5 and check_sight_value(sight, FOOD, 3) == 0:
        return True
    return False

def check_nb_player(max_player:int, team_mate:int) -> bool:
    """Check if there is enough player in team to reach the last level

    Args:
        max_player (int): Team max player number
        team_mate (int): Player in team

    Returns:
        bool: True if there is enough player or False
    """
    if max_player == 0 and team_mate < 6:
        return False
    return True

def check_if_need_fork(player:Player, sight:list) -> bool:
    """Check with the 2 previous function if the player need to fork

    Args:
        player (Player): Player info
        sight (list): Player sight

    Returns:
        bool: True if he need or False
    """
    if check_nb_player(player.nb_player, player.team_mate) or no_food(sight, player.inventory["food"]):
        return True
    return False