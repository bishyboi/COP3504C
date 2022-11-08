import math


class Pakuri:
    __species: str
    __level: int
    __attack: int
    __defense: int
    __stamina: int

    def __init__(self, species: str, level: int):
        self.__species = species
        self.__level = level

        # Calculating attack based on requirements
        self.__attack = (len(species) * 7 + 11) % 16
        self.__defense = (len(species) * 5 + 17) % 16
        self.__stamina = (len(species) * 6 + 13) % 16

    def get_species(self):
        return self.__species

    def get_attack(self):
        return self.__attack

    def get_defense(self):
        return self.__defense

    def get_stamina(self):
        return self.__stamina

    def set_attack(self, new_attack: int):
        self.__attack = new_attack

    # Overriding the less than operator so that the Pakudex can use Python's built-in sort() method
    def __lt__(self, other):
        # Evaluates equality based on lexicographic equality
        if self.__species < other.get_species():
            return True
        return False

    # See above
    def __gt__(self, other):
        if self.get_species() > other.get_species():
            return True
        return False

    @property
    def cp(self):
        # Using floor to round it down
        return math.floor((self.__attack * self.__level * self.__defense**0.5 * self.__stamina**0.5)/12.5)

    @property
    def hp(self):
        return (self.__stamina * self.__level)//6

    @property
    def level(self):
        return self.__level

    @level.setter
    def level(self, new_level: int):
        self.__level = new_level
