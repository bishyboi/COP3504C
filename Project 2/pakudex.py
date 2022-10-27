from pakuri import Pakuri


class Pakudex():
    pakuris = []

    def __init__(self):
        pass

    def get_species_list(self):
        if self.pakuris:
            species_list = []
            for pakuri in self.pakuris:
                species_list.append(pakuri.get_species())

            return species_list

        else:
            return None

    def get_stats(self, species: str):
        if len(self.pakuris) == 0:
            return None
        else:
            stats_list = []
            for pakuri in self.pakuris:
                if pakuri.get_species() == species:
                    stats_list.append(pakuri.level)
                    stats_list.append(pakuri.cp)
                    stats_list.append(pakuri.hp)
                    return stats_list

    def sort_pakuri(self):
        self.pakuris.sort()
        return self.pakuris

    def add_pakuri(self, species: str, level: int):

        self.pakuris.append(Pakuri(species, level))
        return True

    def remove_pakuri(self, species: str):
        for i in range(len(self.pakuris)):
            if self.pakuris[i].get_species() == species:
                self.pakuris.pop(i)
                return True

        return False

    def evolve_species(self, species: str):
        for i in range(len(self.pakuris)):
            if self.pakuris[i].get_species() == species:
                self.pakuris[i].level = self.pakuris[i].level * 2
                self.pakuris[i].set_attack(self.pakuris[i].get_attack() + 1)
                return True

        return False


def menu(pakudex: Pakudex):
    print()
    print("Pakudex Main Menu")
    print("-"*17)
    print("1. List Pakuri")
    print("2. Show Pakuri")
    print("3. Add Pakuri")
    print("4. Remove Pakuri")
    print("5. Evolve Pakuri")
    print("6. Sort Pakuri")
    print("7. Exit")
    print()

    try:
        selection = int(input("What would you like to do? "))
    except ValueError:
        print("Unrecognized menu selection!")
        return True

    if selection == 1:
        species_list = pakudex.get_species_list()
        if species_list != None:
            print("Pakuri in Pakudex")
            for i in range(len(species_list)):
                print(f"{i+1}. {species_list[i]}")
        else:
            print("No Pakuri currently in the Pakudex!")

    elif selection == 2:
        species = input("Enter the name of the species to display: ")

        pakuri_info = pakudex.get_stats(species)

        if pakuri_info == None:
            print("Error: No such Pakuri!")
        else:
            print()
            print(f"Species: {species}")
            print(f"Level: {pakuri_info[0]}")
            print(f"CP: {pakuri_info[1]}")
            print(f"HP: {pakuri_info[2]}")

    elif selection == 3:
        species = input("Species: ")
        level = input("Level: ")

        while ((not isinstance(level, int)) or level < 0):
            if not isinstance(level, int):
                try:
                    level = int(level)

                    if level < 0:
                        raise Exception
                except ValueError:
                    print("Invalid Level!")
                    level = input("Level: ")
                    continue
                except Exception:
                    print("Level cannot be negative")
                    level = input("Level: ")
                    continue

        pakudex.add_pakuri(species, level)
        print(f"Pakuri species {species} (level {level}) added!")
    elif selection == 4:
        species = input("Enter the name of the Pakuri to remove: ")
        if (pakudex.remove_pakuri(species)):
            print(f"Pakuri {species} removed.")
        else:
            print("Error: No such Pakuri!")

    elif selection == 5:
        species = input("Enter the name of the species to evolve: ")
        if (pakudex.evolve_species(species)):
            print(f"{species} has evolved!")
        else:
            print("Error: No such Pakuri!")

    elif selection == 6:
        pakudex.sort_pakuri()
        print("Pakuri have been sorted!")
    elif selection == 7:
        print("Thanks for using Pakudex! Bye!")
        return False

    return True


def main():
    pakudex = Pakudex()
    print("Welcome to Pakudex: Tracker Extraordinaire!")

    run = True
    while (run):
        run = menu(pakudex)


if __name__ == "__main__":
    main()
