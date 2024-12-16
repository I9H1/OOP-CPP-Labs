#include "Game.h"
#include "UniverseParser.h"

using namespace std;

bool isNumber(string str);

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
    UniverseParser parser;
    UniverseConfig config;
    try {
        config = parser.parse(in_filename);
    } catch (const char *error) {
        if (error == "Wrong input filename!") {
            cout << error << endl
                 << "Input format for online: <input_filename>" << endl;
            cout << "Input format for offline: <input_filename> -i <iterations> -o <output_filename>";
        } else if (error == "Wrong file format!") {
            cout << "Input file format is not 'Life 1.06'";
        }
        return 0;
    }
    if (config.name == "Nameless") {
        cout << "!Name wasn't specified!" << endl;
    }
    Game game(config);
    // Offline game proccess
    if (out_filename != "") {
        for (int i = 0; i < offline_iterations; ++i) {
            game.tick();
        }
        game.dump(out_filename);
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
        } else if (command == "tick") {
            game.tick();
            ++iterations;
            game.printUniverse();
            cout << "Iteration: " << iterations << endl;
        } else if (command == "dump") {
            game.dump(in_filename);
        } else if (command.find("tick ") == 0 and command.length() > 5) {
            if (!isNumber(command.substr(5, command.length() - 5))) {
                cout << "Invalid ticks amount!" << endl;
            } else {
                for (int j = 0; j < stoi(command.substr(5, command.length() - 5)); ++j) {
                    game.tick();
                    ++iterations;
                }
                game.printUniverse();
                cout << "Iteration: " << iterations << endl;
            }
        } else if (command == "help") {
            game.printHelp();
        } else if (command.find("dump ") == 0 and command.length() > 5) {
            string dump_filename;
            dump_filename = command.substr(5, command.length() - 5);
            game.dump(dump_filename);
        } else {
            cout << "No such command. Use 'help' for help\n";
        }
    }
    return 0;
}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
