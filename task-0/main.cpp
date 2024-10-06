#include "Controller.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    const string input_filename = argv[1];
    const string output_filename = argv[2];
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
