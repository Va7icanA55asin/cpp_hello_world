//
// Created by Gabe Blandin on 2/17/2023.
// This is the secondary main entry point for this hello_world project
// This is based on the docs at https://cplusplus.com/doc/tutorial/
//
#include <iostream>
#include <sstream>

using namespace std;

#define DEFINITION "this is a definition"

// Variable names in prototypes is optional but recommended
void test_function_by_value(string a, int b);
bool test_function_by_reference(string& a, int& b);
inline string concatenate(const string& a, const string& b);
int function_with_default(int a=1, int b=2, int c=3);
// Overloaded
void test_function_by_value(int a, int b, int c);

// Templates
template <class T>
T template_function(T a, T b);

// Namespaces
namespace test_namespace {
    int abc, xyz;
    string get_name() {
        return "test_namespace";
    }
}

// Would probably make more sense to be in test_namespace but this is for demonstration
int add_namespace_values();

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

    // Flow control
    // Normal if else if etc conditions apply
    // Normal while, do while, for, and for each (or range) loops
    // for each works on any type that supports the begin and end functions
    // break and continue also exist and work as expected
    // goto exists (and as expected has few uses in modern day)
    // Note goto ignores nesting levels so should be used with care
    bool has_jumped = false;
test_label:
    if (!has_jumped) {
        has_jumped = true;
        cout << "Jumping" << endl;
        goto test_label;
    }
    cout << "Jumped" << endl;
    // switch also exists and works as expected and has fall through and a default
    // switch conditions MUST be constant expressions

    // Functions
    // Keep in mind by reference and by value
    test_function_by_value("abc", 23);
    string str_reference = "abc";
    int int_reference = 24;
    cout << "The reference values are " << str_reference << " and " << int_reference << endl;
    bool did_update = test_function_by_reference(str_reference, int_reference);
    if (did_update)
        cout << "The updated reference values are " << str_reference << " and " << int_reference << endl;
    else // Shouldn't happen but included for completeness
        cout << "Reference values were not updated" << endl;
    // Inline functions
    cout << "Combined string is: " << concatenate("abc", "def") << endl;
    // Defaults
    int fun_result = function_with_default();
    cout << "Default result " << fun_result << endl;
    fun_result = function_with_default(4);
    cout << "Two defaults result " << fun_result << endl;
    fun_result = function_with_default(4, 8, 6);
    cout << "No defaults result " << fun_result << endl;

    // Overloads and templates
    test_function_by_value(1, 2, 3);
    // Functions cannot be overloaded on return type alone
    // Templates
    string template_result_str = template_function<string>("abc", "def");
    cout << "Template result: " << template_result_str << endl;
    int template_result_int = template_function(2, 2);
    cout << "Template result: " << template_result_int << endl;
    // Templates can contain multiple types (class T, class U, etc.)
    // They can also take in literals <class T, int N> and usage <int, 4> will make T type int and uses of N 4
    // The second argument MUST be a constant expression

    // Name visibility
    // Scope
    // global and local exist and name collisions are not allowed to occur within the same scope
    // local variables can however redefine global variables
    // Namespaces
    // Declaration must be in global scope
    cout << "Test Namespace Name: " << test_namespace::get_name() << endl;
    test_namespace::abc = 26;
    test_namespace::xyz = 27;
    cout << "Namespace values: " << test_namespace::abc << " " << test_namespace::xyz << endl;
    // Note namespaces can be split
    // As in test_namespace values could exist in two files and all values in that namespace would be within that namespace
    // using keyword
    // The using keyword brings a namespaces values into the current scope such as with cout which is actually std::cout
    int namespace_sum = add_namespace_values();
    cout << "Sum of namespace values: " << namespace_sum << endl;
    // This is an interesting example of splitting namespace use into blocks within the same function
    //    int main () {
    //        {
    //            using namespace first;
    //            cout << x << '\n';
    //        }
    //        {
    //            using namespace second;
    //            cout << x << '\n';
    //        }
    //        return 0;
    //    }
    // Namespaces can be aliased using
    namespace new_name = test_namespace;
    cout << "Aliased namespace name function: " << new_name::get_name() << endl;
    // NOTE global variables (or more accurately variables with static storage) that are not explicitly initialized are auto initialized to 0
    // automatic storage variables that are uninitialized have undetermined value

    // Arrays

    return 0;
}

void test_function_by_value(string a, int b) {
    // The parameter wants to be "const string& a" to prevent copying
    // (since string could potentially be large) and mark the value as non-changing
    // We won't do that here just because this function is for by value but that would be ideal in normal use
    cout << "The string A is: " << a << endl;
    cout << "The int B is: " << b << endl;
}

bool test_function_by_reference(string& a, int& b) {
    if (b == 24) {
        a = "def";
        b = 25;
        return true;
    } else { // Shouldn't happen but included for completeness
        return false;
    }
}

// Example taken from the docs
// Referring to the inline keyword
// "This informs the compiler that when concatenate is called, the program prefers the function to be expanded inline,
// instead of performing a regular call. inline is only specified in the function declaration, not when it is called."
// "Note that most compilers already optimize code to generate inline functions when they see an opportunity to improve
// efficiency, even if not explicitly marked with the inline specifier. Therefore, this specifier merely indicates
// the compiler that inline is preferred for this function, although the compiler is free to not inline it, and
// optimize otherwise."
inline string concatenate(const string& a, const string& b) {
    return a + b;
}

int function_with_default(int a, int b, int c) {
    return (a+b) / c;
}

void test_function_by_value(int a, int b, int c) {
    cout << "The int A is: " << a << endl;
    cout << "The int B is: " << b << endl;
    cout << "The int C is: " << c << endl;
}

template <class T>
T template_function(T a, T b) {
    return a + b;
}

int add_namespace_values() {
    // Alternatively, we can specify specific values such as
    // using test_namespace::xyz or using test_namespace::get_name
    // These would only pull xyz or get_name into the scope to be used unqualified
    using namespace test_namespace;
    cout << "Adding namespace values for namespace: " << get_name() << endl;
    return abc + xyz;
}