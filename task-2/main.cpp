#include "FileReader.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in_filename = "../Universes/Glider.txt";
    string out_filename = "";
    int offline_iterations = 0;
    // Reading from cmd
    if (argc >= 6) {
        in_filename = static_cast<string>(argv[1]);
        for (int i = 0; i < argc; ++i) {
            if (static_cast<string>(argv[i]) == "-o" and argv[i + 1]) {
                out_filename = static_cast<string>(argv[i + 1]);
            } else if (static_cast<string>(argv[i]) == "-i" and argv[i + 1]) {
                offline_iterations = stoi(argv[i + 1]);
            }
        }
    } else if (argc > 1) {
        in_filename = static_cast<string>(argv[1]);
    }
    // Reading from file and creating game object
    FileReader file_in(in_filename);
    try {
        file_in.open();
    } catch (const char *error) {
        cout << error << endl
             << "Input format for online: <input_filename>" << endl;
        cout << "Input format for offline: <input_filename> -i <iterations> -o <output_filename>";
        return 0;
    }
    if (!file_in.checkFormat()) {
        cout << "Input file format is not 'Life 1.06'";
        file_in.close();
        return 0;
    }
    int size = file_in.getSize();
    string name = file_in.getName();
    if (name == "Nameless") {
        cout << "!Name wasn't specified!" << endl;
    }
    vector<int> birth_rule = file_in.getBirthRule();
    vector<int> survival_rule = file_in.getSurvivalRule();
    vector<pair<int, int>> coords = file_in.getCoords();
    Game game(size, name, birth_rule, survival_rule, coords);
    // Offline game proccess
    if (out_filename != "") {
        for (int i = 0; i < offline_iterations; ++i) {
            game.tick();
        }
        game.dump(out_filename);
        file_in.close();
        cout << "Successful!";
        return 0;
    }
    // Online game process
    game.is_on = true;
    string command;
    int iterations = 0;
    game.printUniverse();
    cout << "Iterations: 0" << endl;
    while (game.is_on) {
        cout << ">> ";
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
            game.dump(command.substr(5, command.length() - 5));
        } else {
            cout << "No such command. Use 'help' for help\n";
        }
    }
    file_in.close();
    return 0;
}
