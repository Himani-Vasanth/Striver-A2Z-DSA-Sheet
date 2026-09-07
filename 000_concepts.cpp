#include <iostream>
#include <climits>   // INT_MIN, INT_MAX, UINT_MAX, etc.
#include <cfloat>    // FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX, etc.
#include <string>    // std::string

using namespace std;


/*
============================================================
                    C++ DATA TYPES
============================================================

A DATA TYPE tells the compiler:

1. WHAT kind of value a variable stores
2. HOW MUCH memory is needed
3. WHAT operations can be performed on that value

Main categories:

1. PRIMITIVE / BUILT-IN
   -> int, float, double, char, bool, void

2. DERIVED
   -> array, pointer, reference, function

3. USER-DEFINED
   -> struct, class, enum, union

------------------------------------------------------------
IMPORTANT:
The exact size of some data types depends on the compiler
and system. Use sizeof() to check the actual size.
============================================================
*/


/*
============================================================
                    FUNCTION PROTOTYPES
============================================================

A FUNCTION DECLARATION / PROTOTYPE tells the compiler about
a function BEFORE it is called.

Syntax:

    returnType functionName(parameters);

The actual function definitions are written AFTER main().
============================================================
*/

int add(int a, int b);
int multiply(int a, int b);
void greet();


int main()
{
    /*
    ========================================================
                    1. PRIMITIVE TYPES
    ========================================================

    Primitive types are the basic data types provided by C++.
    */


    // ------------------------------------------------------
    // INTEGER (int)
    // ------------------------------------------------------

    int age = 20;

    /*
    int stores WHOLE NUMBERS.

    Examples:
    -10, 0, 25, 1000

    It does NOT store decimal values.
    */

    cout << "Age: " << age << endl;

    // Output:
    // Age: 20


    // ------------------------------------------------------
    // FLOAT
    // ------------------------------------------------------

    float height = 5.8f;

    /*
    float stores DECIMAL / REAL numbers.

    The 'f' suffix tells C++ that 5.8 is a float literal.

    Without f:
        5.8 is treated as a double by default.
    */

    cout << "Height: " << height << endl;

    // Output:
    // Height: 5.8


    // ------------------------------------------------------
    // DOUBLE
    // ------------------------------------------------------

    double salary = 55000.75;

    /*
    double also stores decimal numbers.

    It generally provides MORE PRECISION than float.

    Approximate typical precision:
    float  -> ~7 decimal digits of precision
    double -> ~15 decimal digits of precision
    */

    cout << "Salary: " << salary << endl;

    // Output:
    // Salary: 55000.75


    // ------------------------------------------------------
    // CHAR
    // ------------------------------------------------------

    char grade = 'A';

    /*
    char stores ONE character.

    Character must be written inside SINGLE quotes.

    Correct:
        'A'
        '7'
        '#'

    Wrong:
        "A"    // This is a string
    */

    cout << "Grade: " << grade << endl;

    // Output:
    // Grade: A


    // ------------------------------------------------------
    // BOOL
    // ------------------------------------------------------

    bool passed = true;

    /*
    bool stores only:

        true
        false

    When printed using cout:
        true  -> 1
        false -> 0

    boolalpha can be used to display true/false as words.
    */

    cout << "Passed: " << passed << endl;

    // Output:
    // Passed: 1

    cout << boolalpha;
    cout << "Passed: " << passed << endl;

    // Output:
    // Passed: true

    cout << noboolalpha;


    // ------------------------------------------------------
    // VOID
    // ------------------------------------------------------

    /*
    void represents the ABSENCE of a value.

    Common use:
        void function()

    This means the function does NOT return a value.

    void cannot normally be used to create a variable:

        void x;   // ERROR

    void* is different:
        It is a generic pointer that can store the address
        of an object of any type.

        void* ptr = nullptr;
    */

    void* ptr = nullptr;

    cout << "Void pointer: " << ptr << endl;

    // Output:
    // Void pointer: 0

    /*
    nullptr means the pointer currently points to nothing.

    IMPORTANT:
    Do not dereference a nullptr.
    */


    /*
    ========================================================
                    2. sizeof() OPERATOR
    ========================================================

    sizeof() tells us the memory size occupied by a type
    or variable, in BYTES.

    Example:
        sizeof(int)
        sizeof(age)

    The exact sizes can depend on the system/compiler.
    */

    cout << "\n--- Size of Data Types ---" << endl;

    cout << "char:      " << sizeof(char) << " byte(s)" << endl;
    cout << "bool:      " << sizeof(bool) << " byte(s)" << endl;
    cout << "int:       " << sizeof(int) << " byte(s)" << endl;
    cout << "float:     " << sizeof(float) << " byte(s)" << endl;
    cout << "double:    " << sizeof(double) << " byte(s)" << endl;
    cout << "long:      " << sizeof(long) << " byte(s)" << endl;
    cout << "long long: " << sizeof(long long) << " byte(s)" << endl;

    /*
    Common values on many systems:

    char       -> 1 byte
    bool       -> commonly 1 byte
    int        -> commonly 4 bytes
    float      -> commonly 4 bytes
    double     -> commonly 8 bytes
    long       -> depends on platform
    long long  -> commonly 8 bytes

    Do NOT assume every system has exactly these sizes.
    */


    /*
    ========================================================
                    3. TYPE MODIFIERS
    ========================================================

    Type modifiers change the range/representation of
    integer types.

    Common modifiers:

        signed
        unsigned
        short
        long
        long long
    */

    short smallNumber = 100;
    long largeNumber = 100000L;
    long long veryLargeNumber = 9000000000LL;

    unsigned int positiveNumber = 4000000000U;

    cout << "\n--- Type Modifiers ---" << endl;

    cout << "short: " << smallNumber << endl;
    cout << "long: " << largeNumber << endl;
    cout << "long long: " << veryLargeNumber << endl;
    cout << "unsigned int: " << positiveNumber << endl;


    /*
    --------------------------------------------------------
                    SIGNED vs UNSIGNED
    --------------------------------------------------------

    signed:
        Can store both NEGATIVE and POSITIVE values.

    unsigned:
        Can store only ZERO and POSITIVE values.

    Because unsigned does not need to represent negative
    numbers, it can represent a larger maximum positive value
    using the same number of bits.

    Example for a typical 32-bit int:

    signed int:
        -2,147,483,648 to 2,147,483,647

    unsigned int:
         0 to 4,294,967,295
    */


    /*
    --------------------------------------------------------
                    RANGE USING <climits>
    --------------------------------------------------------

    <climits> provides limits for integer types.
    */

    cout << "\n--- Integer Limits ---" << endl;

    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "UINT_MAX: " << UINT_MAX << endl;

    /*
    Example output on a typical 32-bit int system:

    INT_MIN: -2147483648
    INT_MAX: 2147483647
    UINT_MAX: 4294967295
    */


    /*
    --------------------------------------------------------
                FLOATING-POINT LIMITS
    --------------------------------------------------------

    <cfloat> provides limits for floating-point types.

    Examples:

        FLT_MIN
        FLT_MAX
        DBL_MIN
        DBL_MAX

    Note:
    Floating-point values have limitations in precision.
    They should not be treated as perfectly exact decimal
    numbers.
    */

    cout << "\n--- Floating Point Limits ---" << endl;

    cout << "FLT_MAX: " << FLT_MAX << endl;
    cout << "DBL_MAX: " << DBL_MAX << endl;


    /*
    ========================================================
                    4. INTEGER OVERFLOW
    ========================================================

    Overflow happens when a value goes beyond the range that
    the type can represent.

    IMPORTANT DIFFERENCE:

    UNSIGNED INTEGER:
        Overflow is well-defined and wraps around.

    SIGNED INTEGER:
        Overflow causes UNDEFINED BEHAVIOR.
        Do NOT rely on wrapping.
    */

    unsigned int uMax = UINT_MAX;

    cout << "\nBefore unsigned overflow: " << uMax << endl;

    uMax = uMax + 1;

    cout << "After unsigned overflow: " << uMax << endl;

    /*
    Typical output:

    Before unsigned overflow: 4294967295
    After unsigned overflow: 0

    This wrapping behavior is defined for unsigned integers.
    */


    /*
    ========================================================
                    5. TYPE CONVERSION
    ========================================================

    Type conversion means changing a value from one type
    to another.

    Two major forms:

    1. IMPLICIT conversion
    2. EXPLICIT conversion
    */


    // ------------------------------------------------------
    // IMPLICIT CONVERSION
    // ------------------------------------------------------

    int num = 10;
    double decimal = num;

    /*
    int -> double

    This is an implicit conversion.

    C++ automatically converts the int value to double.

    This is generally safe because double can represent the
    value of a normal int without losing the integer value.
    */

    cout << "\nImplicit conversion: " << decimal << endl;

    // Output:
    // Implicit conversion: 10


    // ------------------------------------------------------
    // IMPLICIT NARROWING
    // ------------------------------------------------------

    double price = 99.99;
    int wholePrice = price;

    /*
    double -> int

    The decimal portion is removed.

    99.99 -> 99

    This can cause LOSS OF INFORMATION.
    */

    cout << "Narrowing conversion: " << wholePrice << endl;

    // Output:
    // Narrowing conversion: 99


    // ------------------------------------------------------
    // EXPLICIT CONVERSION
    // ------------------------------------------------------

    double marks = 87.75;

    int marks1 = (int)marks;

    /*
    C-style cast:

        (int)marks

    It explicitly tells the compiler to convert the value.
    */

    cout << "C-style cast: " << marks1 << endl;

    // Output:
    // C-style cast: 87


    // ------------------------------------------------------
    // static_cast
    // ------------------------------------------------------

    int marks2 = static_cast<int>(marks);

    /*
    static_cast is the preferred C++ style of explicit casting.

    It is clearer and safer than using a C-style cast in
    many situations.
    */

    cout << "static_cast: " << marks2 << endl;

    // Output:
    // static_cast: 87


    /*
    ========================================================
                    6. CONST
    ========================================================

    const means the value CANNOT be changed after
    initialization.
    */

    const int DAYS_IN_WEEK = 7;

    cout << "\nDays in a week: " << DAYS_IN_WEEK << endl;

    // DAYS_IN_WEEK = 8;   // ERROR

    /*
    Use const for values that should remain unchanged.

    Examples:
        const int MAX_USERS = 100;
        const double PI = 3.14159;
    */


    /*
    ========================================================
                    7. DERIVED DATA TYPES
    ========================================================

    Derived types are created from existing data types.

    Important derived types:

    1. Array
    2. Pointer
    3. Reference
    4. Function
    */


    // ------------------------------------------------------
    // ARRAY
    // ------------------------------------------------------

    int arr[3] = {10, 20, 30};

    /*
    An ARRAY stores multiple values of the SAME type
    in a fixed-size sequence.

    Syntax:

        dataType arrayName[size];

    Example:

        int arr[3];

    Indexing starts from 0:

        arr[0] -> 10
        arr[1] -> 20
        arr[2] -> 30
    */

    cout << "\n--- Array ---" << endl;

    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    // Output:
    // arr[0]: 10
    // arr[1]: 20
    // arr[2]: 30


    // Changing an array element

    arr[1] = 50;

    cout << "After changing arr[1]: " << arr[1] << endl;

    // Output:
    // After changing arr[1]: 50


    // Loop through array

    cout << "Array elements: ";

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Output:
    // Array elements: 10 50 30


    /*
    IMPORTANT:

    Array size is fixed after declaration.

        int arr[3];

    cannot later become:

        int arr[10];

    If you need a dynamically sized container, C++ provides
    things such as vector (covered separately).
    */


    // ------------------------------------------------------
    // POINTER
    // ------------------------------------------------------

    int value = 25;
    int* p = &value;

    /*
    A POINTER stores the MEMORY ADDRESS of another variable.

        &value
            -> address of value

        p
            -> stores that address

        *p
            -> value stored at that address
    */

    cout << "\n--- Pointer ---" << endl;

    cout << "Value: " << value << endl;
    cout << "Address stored in p: " << p << endl;
    cout << "Value through p: " << *p << endl;

    /*
    Typical output:

    Value: 25
    Address stored in p: 0x7...
    Value through p: 25

    The actual address will be different on different runs.
    */


    // Changing value through pointer

    *p = 40;

    cout << "After *p = 40, value: " << value << endl;

    // Output:
    // After *p = 40, value: 40


    /*
    nullptr:

        int* p = nullptr;

    means p currently points to nothing.

    Always check pointers before dereferencing when necessary.

        if (p != nullptr)
        {
            cout << *p;
        }
    */


    // ------------------------------------------------------
    // REFERENCE
    // ------------------------------------------------------

    int original = 100;
    int& ref = original;

    /*
    A REFERENCE is another name / ALIAS for an existing variable.

        int& ref = original;

    ref and original refer to the SAME variable.

    Changing ref changes original.
    */

    cout << "\n--- Reference ---" << endl;

    cout << "Original: " << original << endl;
    cout << "Reference: " << ref << endl;

    ref = 200;

    cout << "After changing ref: " << original << endl;

    // Output:
    // Original: 100
    // Reference: 100
    // After changing ref: 200


    /*
    POINTER vs REFERENCE

    POINTER:
        - Stores an address
        - Can be nullptr
        - Can point to a different variable later
        - Uses * to dereference

    REFERENCE:
        - Acts as an alias
        - Must be initialized
        - Normally cannot be reseated
        - No separate dereference operation is needed

    Example:

        int a = 10;
        int b = 20;

        int* p = &a;
        p = &b;       // allowed

        int& r = a;
        // r = b;     // does NOT make r refer to b
                      // it assigns b's value to a
    */


    /*
    --------------------------------------------------------
                    ARRAY vs POINTER
    --------------------------------------------------------

    They are related, but NOT the same thing.

    Array:
        int arr[3] = {1, 2, 3};

        - stores multiple elements
        - fixed size
        - memory is allocated for the elements

    Pointer:
        int* p = arr;

        - stores an address
        - can point somewhere else
    */

    int numbers[3] = {1, 2, 3};
    int* numberPtr = numbers;

    cout << "\nFirst array element: " << numbers[0] << endl;
    cout << "First element through pointer: " << *numberPtr << endl;

    // Output:
    // First array element: 1
    // First element through pointer: 1


    /*
    --------------------------------------------------------
                    FUNCTION TYPE
    --------------------------------------------------------

    Functions are also considered a derived type in this
    classification.

    A function can:

        - receive parameters
        - perform operations
        - return a value

    Example:

        int add(int a, int b)

    Parameters:
        a and b

    Arguments:
        actual values passed during the function call

        add(10, 20)

        10 and 20 are arguments.
    */

    cout << "\n--- Functions ---" << endl;

    cout << "10 + 20 = " << add(10, 20) << endl;

    // Output:
    // 10 + 20 = 30

    cout << "10 * 20 = " << multiply(10, 20) << endl;

    // Output:
    // 10 * 20 = 200

    greet();

    // Output:
    // Hello from the function!


    /*
    ========================================================
                    8. STRING
    ========================================================

    string is NOT a primitive data type.

    std::string is a CLASS provided by the C++ Standard
    Library.

    It is used to store a sequence of characters.

    Unlike a single char, a string can contain many characters
    and can grow/shrink dynamically.

    Example:

        char letter = 'A';

        string name = "Jane";
    */

    string name = "Jane";

    cout << "\n--- String ---" << endl;
    cout << "Name: " << name << endl;

    // Output:
    // Name: Jane


    /*
    char vs string:

        char:
            stores ONE character

            char grade = 'A';

        string:
            stores a sequence of characters

            string name = "Jane";
    */


    /*
    ========================================================
                    9. AUTO
    ========================================================

    auto allows the compiler to DEDUCE the variable's type
    from the value used to initialize it.

    Type deduction happens at COMPILE TIME.
    */

    auto count = 10;       // int
    auto price2 = 99.99;   // double
    auto letter2 = 'A';    // char
    auto passed2 = true;   // bool

    cout << "\n--- Auto ---" << endl;

    cout << "count: " << count << endl;
    cout << "price: " << price2 << endl;
    cout << "letter: " << letter2 << endl;
    cout << "passed: " << passed2 << endl;

    /*
    auto is especially useful for long or complicated types.

    However, use it carefully.

    For simple types:

        int age = 20;

    may be clearer than:

        auto age = 20;

    Use auto when it improves readability rather than
    hiding an obvious type.
    */


    /*
    ========================================================
                    10. TYPE ALIAS
    ========================================================

    'using' can create another name for an existing type.

    Syntax:

        using NewName = ExistingType;
    */

    using Age = int;

    Age studentAge = 21;

    cout << "\nStudent age: " << studentAge << endl;

    // Output:
    // Student age: 21

    /*
    Type aliases do NOT create a completely new data type.

        using Age = int;

    simply gives int another name: Age.
    */


    /*
    ========================================================
                    11. USER-DEFINED TYPES
    ========================================================

    User-defined types are types created by the programmer.

    Important examples:

        struct
        class
        enum
        enum class
        union
    */


    // ------------------------------------------------------
    // STRUCT
    // ------------------------------------------------------

    /*
    struct groups related variables together.

    Example:

        struct Point
        {
            int x;
            int y;
        };

    Then:

        Point p1;
        p1.x = 10;
        p1.y = 20;
    */


    // ------------------------------------------------------
    // CLASS
    // ------------------------------------------------------

    /*
    class is used to create objects and supports
    Object-Oriented Programming.

    Example:

        class Car
        {
        public:
            string model;
        };

    Then:

        Car car1;
        car1.model = "BMW";
    */


    // ------------------------------------------------------
    // ENUM
    // ------------------------------------------------------

    /*
    enum represents a set of named constants.

        enum Color
        {
            RED,
            GREEN,
            BLUE
        };

    By default:

        RED   -> 0
        GREEN -> 1
        BLUE  -> 2
    */


    // ------------------------------------------------------
    // ENUM CLASS
    // ------------------------------------------------------

    /*
    Modern C++ also provides enum class.

        enum class Color
        {
            RED,
            GREEN,
            BLUE
        };

    enum class is safer because its values are scoped.

    Access:

        Color::RED

    It avoids accidentally mixing enum values with integers
    or values from unrelated enums.
    */


    // ------------------------------------------------------
    // UNION
    // ------------------------------------------------------

    /*
    A union allows different members to SHARE the same
    memory location.

    Example:

        union Data
        {
            int i;
            float f;
            char c;
        };

    Only one member should generally be treated as the active
    value at a time.

    Union is mainly useful when memory efficiency or
    low-level representation matters.
    */


    /*
    ========================================================
                    QUICK COMPARISON
    ========================================================

    TYPE        PURPOSE

    int         Whole numbers
    float       Decimal numbers, lower precision
    double      Decimal numbers, higher precision
    char        One character
    bool        true / false
    void        Represents absence of a value
    array       Multiple same-type values, fixed size
    pointer     Stores an address
    reference   Alias for another variable
    function    Performs a reusable operation
    string      Sequence of characters; class type
    struct      Groups related data
    class       Creates objects / OOP
    enum        Named constants
    enum class   Scoped named constants
    union       Members share memory
    */


    /*
    ========================================================
                        SUMMARY
    ========================================================

    1. PRIMITIVE / BUILT-IN TYPES
       -> int
       -> float
       -> double
       -> char
       -> bool
       -> void

    2. TYPE MODIFIERS
       -> signed
       -> unsigned
       -> short
       -> long
       -> long long

    3. TYPE CONVERSION
       -> implicit conversion
       -> explicit conversion
       -> static_cast

    4. DERIVED TYPES
       -> array
       -> pointer
       -> reference
       -> function

    5. OTHER IMPORTANT C++ TYPES / FEATURES
       -> string
       -> auto
       -> const
       -> type aliases

    6. USER-DEFINED TYPES
       -> struct
       -> class
       -> enum
       -> enum class
       -> union

    7. MEMORY / RANGE
       -> sizeof()
       -> <climits>
       -> <cfloat>
    */


    /*
    ========================================================
                    COMMON PITFALLS
    ========================================================

    1. INTEGER OVERFLOW

       Unsigned overflow wraps around.

       Signed integer overflow is UNDEFINED BEHAVIOR.

    --------------------------------------------------------

    2. NARROWING CONVERSION

       double x = 99.99;
       int y = x;

       y becomes 99.

       Information is lost.

    --------------------------------------------------------

    3. FLOAT PRECISION

       float and double cannot represent every decimal value
       exactly.

       Avoid using floating-point values when exact decimal
       precision is required, such as financial calculations.

    --------------------------------------------------------

    4. FLOAT SUFFIX

       5.8  -> double
       5.8f -> float

    --------------------------------------------------------

    5. CHAR vs STRING

       char:
           'A'

       string:
           "Apple"

    --------------------------------------------------------

    6. POINTER vs REFERENCE

       Pointer stores an address.

       Reference is an alias for an existing variable.

    --------------------------------------------------------

    7. NULL POINTER

       Use:

           nullptr

       instead of the old C-style:

           NULL

       Do not dereference a nullptr.

    --------------------------------------------------------

    8. CONST

       const variables cannot be modified after initialization.

    --------------------------------------------------------

    9. sizeof()

       Do not assume every data type has the same size on
       every operating system/compiler.

    --------------------------------------------------------

    10. ARRAY BOUNDS

        If:

            int arr[3];

        Valid indexes are:

            0, 1, 2

        arr[3] is OUT OF BOUNDS.

    --------------------------------------------------------

    11. FUNCTION DECLARATION vs DEFINITION

        Declaration / prototype:

            int add(int a, int b);

        Definition:

            int add(int a, int b)
            {
                return a + b;
            }

        The prototype tells the compiler that the function
        exists and what its signature is.

        The definition provides the actual function body.
    */

    return 0;
}


/*
============================================================
                    FUNCTION DEFINITIONS
============================================================

Functions are defined OUTSIDE main().

The prototypes at the top allow main() to call these
functions before their definitions appear.
============================================================
*/


// Function with parameters and return value

int add(int a, int b)
{
    return a + b;
}


// Another function with parameters and return value

int multiply(int a, int b)
{
    return a * b;
}


// Function with no parameters and no return value

void greet()
{
    cout << "Hello from the function!" << endl;
}
