from parsing import parseLevel

class level:
    def __init__(self):
        self.levels = parseLevel("./src/ai/level.json")

    def setObj(self, level:int) -> dict:
        """Set the objectif list

        Args:
            level (int): level of the player

        Returns:
            dict: list of objectif based on the level
        """
        return self.levels[level]
