#include "FileReader.h"
#include "Universe.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in_filename = "../Universes/Glider.txt";
    if (argc >= 4) {

    } else if (argc > 1) {
        in_filename = static_cast<string>(argv[1]);
    }
    FileReader file_in(in_filename);
    // Reading from file and creating game object
    file_in.open();
    int size = file_in.getSize();
    string name = file_in.getName();
    vector<int> birth_rule = file_in.getBirthRule();
    vector<int> survival_rule = file_in.getSurvivalRule();
    vector<pair<int, int>> coords = file_in.getCoords();
    Game game(size, name, birth_rule, survival_rule, coords);
    // Game process
    game.is_on = true;
    string command;
    int iterations = 0;
    while (game.is_on) {
        cout << ">>";
        getline(cin, command);
        if (command == "exit") {
            game.is_on = false;
        } else if (command.find("tick") == 0) {
            if (command == "tick") {
                game.tick();
                ++iterations;
            } else {
                for (int j = 0; j < stoi(command.substr(5, command.length() - 5)); ++j) {
                    game.tick();
                    ++iterations;
                }
            }
            game.printUniverse();
            cout << "Iteration: " << iterations << endl;
        } else if (command == "help") {
            game.printHelp();
        } else if (command.find("dump") == 0) {

        } else {
            cout << "No such command. Use 'help' for help\n";
        }
    }
    return 0;
}
