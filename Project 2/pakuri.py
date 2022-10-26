class Pakuri:
    __species:str
    __level: int
    __attack: int
    __defense: int
    __stamina: int
    
    def __init__(self, species: str, level:int):
         self.__species = species
         self.__level = level
         
         self.__attack = (len(species) * 7 + 11) % 16
         self.__defense = (len(species) * 5  + 17) % 16
         self.__stamina = (len(species) * 6 + 13) % 16
         self.hp = (self.__stamina * self.__level)//6
         self.cp = (self.__attack * self.__level * self.__defense**0.5 * self.__stamina**0.5)