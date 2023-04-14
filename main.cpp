#include "knight2.h"

unsigned knidcount = 0;

int main(int argc, char ** argv) {
    string file_armyknights, file_events;
    if (argc == 1) {
        file_armyknights = "tc1_armyknights"; // hard-code
        file_events = "tc1_events";
    }
    else if (argc == 3) {
        file_armyknights = argv[1];
        file_events = argv[2];
    }
    else {
        cout << "Error number of arguments" << endl;
        exit(1);
    }
    
    // BEBGIN
    // Don't alloc to heap if ya don't need to;
    KnightAdventure knightAdventure{};
    knightAdventure.loadArmyKnights(file_armyknights);
    std::cout << "okay2" << std::endl;
    knightAdventure.loadEvents(file_events);
    std::cout << "okay3" << std::endl;
    knightAdventure.run();

    return 0;
}