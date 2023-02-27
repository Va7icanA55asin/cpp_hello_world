//
// Created by Gabe Blandin on 2/17/2023.
// This is the secondary main entry point for this hello_world project
// This is based on the docs at https://cplusplus.com/doc/tutorial/
//
#include <iostream>
#include <sstream>

using namespace std;

#define DEFINITION "this is a definition"

int main() {
    // Data types
    char letter = 'a';
    int num = 1;
    unsigned int unsign_num = 2;
    long long_num = 3;
    long long big_num = 4;
    float decimal = 5.0;
    double precise_decimal = 6.0; // This is default for floating point
    long double big_decimal = 7.0;
    bool boolean = true;
    //void

    // Initializations
    int test = 8; // C-like initialization
    int test_2 (9); // Constructor initialization (introduced by C++)
    int test_3 {10}; // Uniform initialization (introduced by C++11)

    // Type deduction
    int foo = 11;
    auto bar = foo; // Compiler knows this should be an int because foo is
    auto baz = 12; // Same here more or less
    decltype(foo) qux = 13; // Another way the compiler can infer typing

    // Strings
    string hello_world = "Hello World!";
    cout << hello_world << endl;

    // Literals
    int dec = 14;
    int oct = 017; // Decimal 15
    int hex = 0x10; // Decimal 16
    int unsign_2 = 17u;
    int scientific = 1.8e1; // 18
    int float_num = 19.0f;
    string big_string = "this " "is " "a "
                                    "really "
                                    "big "
                                    "string";
    cout << big_string << endl;
    string raw = R"sequence(string with a \backslash)sequence";
    cout << raw << endl;
    int* p = nullptr; // null pointer value

    // Constants
    const int constant = 20;
    // Preprocessor stuff (see the "define" above)
    cout << DEFINITION << endl;

    // Assignment and math
    // This is an interesting example from the tutorial, maybe not useful, but interesting
    int x, y, z;
    y = 2 + (x = 5); // y becomes 7
    x = y = z = 21; // Right to left assignment
    // All the normal math ops, + - * / and %
    // All the normal compound +=, -=, etc. and bitwise stuff >>=, &=, etc.
    // We also have normal increment and decrement ++ -- with pre and post incrementing
    // All the normal comparison stuff == != > < >= <= and logical stuff ! && ||
    // Ternaries exist as expected

    // Comma operator
    // "used to separate two or more expressions that are included where only one expression is expected"
    int a, b;
    a = (b = 3, b + 2); // a becomes 5 and b is 3

    // bitwise stuff as normal & | ^ ~ << >>

    // Type casting
    float cast_float = 22.0;
    int c = (int) cast_float;
    int d = int (cast_float);

    size_t type_size = sizeof (int);

    // Operator Precedence, all are grouping left to r except specified
    // Scope ::
    // Postfix ++ -- () [] . ->
    // Prefix (R to L) ++ -- ~ ! + - & * new delete sizeof (type)
    // Pointer to member .* ->*
    // Math * / %
    // Math + -
    // Bitwise shift << >>
    // Relational < > <= >=
    // Equality == !=
    // And &
    // Exclusive or ^
    // Inclusive or |
    // Conjunction &&
    // Disjunction ||
    // Assignment (R to L) = *= /= %= += -= >>= <<= &= ^= |= ?:
    // Sequencing ,
    // "When an expression has two operators with the same precedence level, grouping determines which one is evaluated first: either left-to-right or right-to-left."

    // Basic IO
    cout << "Basic String " << a << " " << 21 << endl;
    int int_input;
    string str_input;
    // This isn't really proper form since cin will fail silently if expected type != given type
    // Also note, getting a string is whitespace delimited so only a single word will be retrieved
    cout << "Enter a number, then enter a string" << endl;
    cin >> int_input >> str_input;
    cout << "Int given is " << int_input << " string given is " << str_input << endl;
    // To get a full line
    cout << "Enter a full line of text:" << endl;
    cin.ignore(); // Not proper format to use both >> and getline but this is just a test program so using this fix to get around trailing new line
    getline(cin, str_input);
    cout << "Line given is " << str_input << endl;
    // stringstream
    string stream_test ("2048");
    int stream_int;
    stringstream(stream_test) >> stream_int;
    cout << "Stream test: " << stream_int << endl;
    string number_test_str;
    int number_test;
    cout << "Enter number:";
    getline(cin, number_test_str);
    stringstream(number_test_str) >> number_test;
    cout << "Number was: " << number_test << endl;

    return 0;
}
