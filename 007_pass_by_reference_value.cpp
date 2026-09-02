#include <iostream>
#include <string>
using namespace std;

/*
PASS BY VALUE vs PASS BY REFERENCE

PASS BY VALUE:
- A copy of the argument is passed to the function.
- The function works on its own copy.
- Changes do NOT affect the original variable.

PASS BY REFERENCE:
- No copy is made.
- The parameter becomes an alias for the original variable.
- Changes DO affect the original variable.
*/

void modifyByValue(int a) {
    a = a + 10;
    cout << "Inside modifyByValue: " << a << endl;
}

void modifyByReference(int &a) {
    a = a + 10;
    cout << "Inside modifyByReference: " << a << endl;
}


/*
SWAP FUNCTION

Pass by reference allows the function to modify
the original variables.

*/

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int main() {

 // ---------- PASS BY VALUE ----------
int x = 5;

modifyByValue(x);

cout << "Original x after pass by value: " << x << endl;
// Output: 5
// The copy was changed inside the function,
// but the original x remains unchanged.


// ---------- PASS BY REFERENCE ----------
int y = 5;

modifyByReference(y);

cout << "Original y after pass by reference: " << y << endl;
// Output: 15
// The original y was changed because the function
// works directly with the original variable.


    /*
    WHY PASS BY REFERENCE IS USEFUL

    If a function needs to modify the original variables,
    pass by reference allows it to do so.

    Example: swapping two numbers.

    The function receives references to the original variables,
    so changes made inside the function affect the originals.
    */

    int a = 10;
    int b = 20;

    swapNumbers(a, b);

    cout << "After swap: a = " << a << ", b = " << b << endl;
    // Output: a = 20, b = 10


    /*
    REFERENCE vs POINTER

    REFERENCE (&):
    - An alias (another name) for an existing variable.
    - Used directly like the original variable.
    - Cannot be nullptr.

    POINTER (*):
    - A variable that stores the address of another variable.
    - * is used to access the value at that address.
    - Can be nullptr.
    */

    int n = 10;

    int &ref = n;    // ref is another name for n
    int *ptr = &n;   // ptr stores the address of n

    ref = 20;        // changes n
    *ptr = 30;       // also changes n

    cout << "Using reference: " << ref << endl;
    cout << "Using pointer: " << *ptr << endl;
    // Output:
    // Using reference: 30
    // Using pointer: 30


    /*
    PASS BY CONST REFERENCE

    const string &s:

    &     -> no copy is made; s refers to the original object.
    const -> the function cannot modify the original object.

    Useful when a function only needs to READ an object.

    const reference = efficient + read-only

    Passing by value:
    void func(string s);
    → creates a copy.

    Passing by const reference:
    void func(const string &s);
    → avoids the copy and prevents modification.
    */

    string name = "Jane";

    const string &refName = name;

    cout << "Const reference: " << refName << endl;
    // Output: Const reference: Jane

    // refName = "John";  // ERROR: const prevents modification


    return 0;
}


/*
SUMMARY

Pass by value      → COPY
Pass by reference  → ALIAS
Pointer            → VARIABLE THAT STORES AN ADDRESS
const reference    → ALIAS + READ ONLY


WHEN TO USE

Pass by value:
→ When the function should work with a separate copy.

Pass by reference:
→ When the function needs to modify the original variable.

Pass by const reference:
→ When the function only needs to read an object
  without making a copy.

Pointer:
→ When you need an address, nullptr, or pointer-specific operations.


& IN C++

Its meaning depends on the context:

1. Reference declaration:
   int &ref = x;
   → ref is another name (alias) for x.

2. Address-of:
   int *p = &x;
   → &x gives the memory address of x.

3. Function parameter:
   void func(int &x)
   → x is passed by reference.

Remember:
& can mean "reference" OR "address of",
depending on where it is used.
*/
