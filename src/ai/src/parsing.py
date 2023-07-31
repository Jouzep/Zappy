import json

INV_LEN = 7

def parseLook(look:str) -> list:
    """Parse the vision array sent by the server

    Args:
        look (str): look being the vision sent by the server

    Returns:
        list: return the parsed vision array
    """
    tmp:str = look.split(',')
    res = [[]]

    for i in range(len(tmp)):
        v = tmp[i].split()
        res.append(v)
    return res[1:]

def parseInventory(inventory:str) -> list:
    """Parse the inventory array sent by the server

    Args:
        inventory (str): array for the inventory sent by the server

    Returns:
        list: return the parsed inventory list
    """
    tmp:str = inventory.split(',')
    res = {}
    if len(tmp) != INV_LEN:
        return res
    for i in range(len(tmp)):
        # print(tmp[i])
        v = tmp[i].split()
        res[v[0]] = int(v[1])
    return res

def parseLevel(filename:str) -> dict:
    """Parse the level file and file a dict

    Args:
        filename (str): filename

    Returns:
        dict: list of objectif for each level
    """
    with open(filename) as file:
        data = json.load(file)
        parsed_list = {}
        for key, value in data.items():
            parsed_list[int(key)] = {k: v for k, v in value.items()}
        return parsed_list
