#include <iostream>
#include <climits>   // for INT_MIN, INT_MAX, etc.
using namespace std;
/*
C++ DATA TYPES
Tells the compiler what KIND of value a variable holds, how much MEMORY
to reserve for it, and what OPERATIONS are valid on it.
Three broad categories:
1. PRIMITIVE (built-in)   -> int, float, double, char, bool, void
2. DERIVED                -> array, pointer, reference, function
3. USER-DEFINED           -> struct, class, enum, union
*/

int main() {
    /*
    PRIMITIVE TYPES
    */
    int age = 21;                 // whole numbers
    float height = 5.9f;          // decimal, ~7 digit precision, 'f' suffix needed
    double salary = 45000.75;     // decimal, ~15 digit precision (more accurate than float)
    char grade = 'A';             // single character, stored as 1 byte
    bool passed = true;           // true/false only
    void* ptr = nullptr;          // void = "no type" -- used for generic pointers / no return

    cout << age << " " << height << " " << salary << " " << grade << " " << passed << endl;
    // Output: 21 5.9 45000.8 A 1
    // Note: bool prints as 1/0, not true/false, unless you use cout << boolalpha;

    /*
    SIZE OF EACH TYPE (in bytes) -- use sizeof() to check on YOUR machine.
    Sizes are compiler/platform dependent, but these are the typical values
    on most modern 64-bit systems (what you'll see if you run this):
    */
    cout << "int: "    << sizeof(int)    << " bytes" << endl;
    cout << "float: "  << sizeof(float)  << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "char: "   << sizeof(char)   << " bytes" << endl;
    cout << "bool: "   << sizeof(bool)   << " bytes" << endl;
    // Output: int: 4 bytes
    //         float: 4 bytes
    //         double: 8 bytes
    //         char: 1 bytes
    //         bool: 1 bytes

    /*
    MODIFIERS: adjust the size/range or sign behavior of a base type.
    short   -> smaller range, less memory
    long    -> larger range, more memory
    signed  -> can hold negative AND positive (default for int)
    unsigned-> only non-negative, but doubles the positive range
    */
    short s = 100;
    long l = 100000L;
    long long ll = 10000000000LL;      // for very large integers
    unsigned int u = 4000000000U;       // no negative values allowed

    cout << "short: " << sizeof(short) << " bytes, long: " << sizeof(long)
         << " bytes, long long: " << sizeof(long long) << " bytes" << endl;
    // Output: short: 2 bytes, long: 8 bytes, long long: 8 bytes

    /*
    RANGE MATTERS: exceeding a type's range causes OVERFLOW (wraps around
    silently, no error/warning) -- a common source of subtle bugs.
    */
    unsigned int uMax = 4294967295U;   // max value for unsigned int (2^32 - 1)
    uMax = uMax + 1;                    // overflow: wraps back around
    cout << uMax << endl;
    // Output: 0

    /*
    FINDING A TYPE'S EXACT RANGE (instead of guessing):
    <climits> and <cfloat> give the min/max a type can hold on your system.
    */
    cout << "int range: " << INT_MIN << " to " << INT_MAX << endl;
    // Output: int range: -2147483648 to 2147483647

    /*
    TYPE CONVERSION
    */
    // Implicit (automatic, done by compiler) -- "type promotion"
    int a = 5;
    double b = a;          // int -> double, safe, no data lost
    cout << b << endl;
    // Output: 5

    // Implicit NARROWING (dangerous -- data loss, no error/warning)
    double pi = 3.14;
    int truncated = pi;    // double -> int, decimal part silently dropped
    cout << truncated << endl;
    // Output: 3

    // Explicit (you deliberately request it) -- "type casting"
    double x = 9.99;
    int y = (int)x;             // C-style cast
    int z = static_cast<int>(x); // C++ style cast -- preferred, safer/clearer intent
    cout << y << " " << z << endl;
    // Output: 9 9

    /*
    DERIVED TYPES
    */
    int arr[3] = {10, 20, 30};    // ARRAY: fixed-size collection of same type
    int *p = &age;                // POINTER: stores an address
    int &ref = age;                // REFERENCE: alias for an existing variable
    cout << arr[0] << " " << *p << " " << ref << endl;
    // Output: 10 21 21

    /*
    STRING: not a primitive type (it's a class from <string>), but used
    constantly for text. Unlike char, it holds a whole sequence of
    characters and can grow/shrink dynamically.
    */
    string name = "Jane";
    cout << name << endl;
    // Output: Jane

    /*
    AUTO: lets the compiler DEDUCE the type from the assigned value.
    Useful for long/complex types, but use sparingly where it hurts
    readability (e.g. plain int/double is clearer written explicitly).
    */
    auto count = 10;         // deduced as int
    auto price = 9.99;       // deduced as double
    cout << count << " " << price << endl;
    // Output: 10 9.99

    return 0;
}

/*
USER-DEFINED TYPES (declared outside main, shown separately below)

struct Point {
    int x, y;              // groups related variables together
};

enum Color { RED, GREEN, BLUE };   // named set of integer constants (RED=0, GREEN=1, BLUE=2)

class Car {                 // like struct, but members are PRIVATE by default
    public:
        string model;
};

SUMMARY

PRIMITIVE TYPES:
int      -> whole numbers                 (~4 bytes)
float    -> decimals, less precision       (~4 bytes)
double   -> decimals, more precision       (~8 bytes)
char     -> single character               (1 byte)
bool     -> true/false                     (1 byte)
void     -> "no type" -- generic pointers, functions returning nothing

MODIFIERS:
short / long / long long -> adjust size & range
signed / unsigned          -> allow/disallow negative values

TYPE CONVERSION:
Implicit -> compiler does it automatically (widening = safe, narrowing = data loss)
Explicit -> you request it: static_cast<Type>(value)  (preferred over C-style casts)

DERIVED TYPES:
array     -> fixed-size same-type collection
pointer   -> stores a memory address
reference -> alias for an existing variable
function  -> a named, reusable block of code

USER-DEFINED TYPES:
struct -> groups variables, members public by default
class  -> groups variables + functions, members private by default
enum   -> named integer constants
union  -> like struct, but all members SHARE the same memory (one at a time)

COMMON PITFALLS:
1. Overflow: exceeding a type's range wraps around silently -- no warning.
2. Narrowing conversions lose data silently unless using {} initialization,
   which raises a compile-time error instead.
3. float has limited precision -- avoid using it for money/exact decimals;
   prefer double or fixed-point/integer-based representations.
4. Forgetting 'f' suffix on a float literal (5.9 vs 5.9f) makes it a
   double by default, then implicitly narrowed when assigned to float.
*/
