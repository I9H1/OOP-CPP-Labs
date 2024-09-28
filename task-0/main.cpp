#include "Controller.h"

using namespace std;

int main() {
    const string input_filename = "../in.txt";
    const string output_filename = "../out.csv";
    Controller controller(input_filename, output_filename);
    controller.open_files();
    while(!controller.are_words_over()) {
        controller.get_new_words();
        controller.handle_new_words();
    }
    controller.calc_data();
    controller.write_data(controller.get_data());
    controller.close_files();
    return 0;
}
