//
// Created by Gabe Blandin on 2/10/2023.
// This is the main entry point for this hello_world project
// This is based on the guide found here: https://developers.google.com/edu/c++/getting-started
//
#include <iomanip>
#include <limits>
#include <iostream>
using namespace std;

void basic_hello_world();
void looping_hello_world();
void looping_hello_world_left_aligned();
void input_test();
void input_error_handling();

int main() {
    cout << "Starting Main" << endl;
    cout << "*****************************************" << endl;
    basic_hello_world();
    cout << "*****************************************" << endl;
    looping_hello_world();
    cout << "*****************************************" << endl;
    looping_hello_world_left_aligned();
    cout << "*****************************************" << endl;
    input_test();
    cout << "*****************************************" << endl;
    cout << "Done with Main" << endl;
    return 0;
}

void basic_hello_world() {
    cout << "Basic Hello World" << endl << endl;
    cout << "Hello World!" << endl;
}

void looping_hello_world() {
    cout << "Looping Hello World" << endl << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(17) << "Hello World!";
        }
        cout << endl;
    }
}

void looping_hello_world_left_aligned() {
    cout << "Looping Hello World Left Align" << endl << endl;
    cout << std::setiosflags(ios::left);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(17) << "Hello World!";
        }
        cout << endl;
    }
    // Reset
    cout << std::setiosflags(ios::right);
}

void input_test() {
    int input_var = 0;
    // Enter the do while loop and stay there until either
    // a non-numeric is entered, or -1 is entered. Note that
    // cin will accept any integer, 4, 40, 400, etc.
    do {
        cout << "Enter a number (-1 = quit): ";
        // The following line accepts input from the keyboard into
        // variable input_var.
        // cin returns false if an input operation fails, that is, if
        // something other than an int (the type of input_var) is entered.
        if (!(cin >> input_var)) {
            // Original
//            cout << "You entered a non-numeric. Exiting..." << endl;
//            break;
//            // exit the do while loop
            // Recovery
            input_error_handling();
        }
        if (input_var != -1) {
            cout << "You entered " << input_var << endl;
        }
    } while (input_var != -1);
    cout << "All done." << endl;
}

void input_error_handling() {
    cout << "You entered a non-numeric. Please only use numbers. Continuing..." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
