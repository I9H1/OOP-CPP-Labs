#include "Controller.h"
#include <iostream>

using namespace std;

int main() {
    const string input_filename = "../in.txt";
    const string output_filename = "../out.csv";
    Controller controller(input_filename, output_filename);
    if (!controller.open_files()) {
        cout << "can not open files";
        return 0;
    }
    while(!controller.are_words_over()) {
        controller.handle_new_words();
    }
    controller.write_data(controller.get_data());
    controller.close_files();
    return 0;
}
