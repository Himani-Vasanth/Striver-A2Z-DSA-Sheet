#include <iostream>
using namespace std;
/*
SWITCH vs IF-ELSE:
- if-else: flexible, handles complex/range conditions, non-equality checks.
- switch: concise, best when ONE variable is compared against multiple exact values.
- They complement each other: if-else for complex logic, switch for clean multi-match.
*/
int main() {
    int day;
    cout << "Enter a number (1-7): ";
    cin >> day;

    switch (day) {
        case 1: cout << "Monday" << endl; break;    // break exits switch after match
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        case 7: cout << "Sunday" << endl; break;
        default: cout << "Invalid" << endl;         // safety net if no case matches
    }
    // Input: 4 -> Output: Thursday
    // Input: 9 -> Output: Invalid

    /*
    KEY RULES:
    1. Expression must evaluate to a CONSTANT value (const, literal, arithmetic on
       constants) -> known at compile time. Cannot switch on a runtime-only value
       like a variable string or a float.
    2. Only works with integer or character types (int, char, enum). NOT float/double,
       NOT string (unlike some other languages).
    */
    const int x = 10, y = 5;
    switch (x + y) {          // constant expression -> 15
        case 15: cout << "Result is 15." << endl; break;
        case 20: cout << "Result is 20." << endl; break;
        default: cout << "No match found." << endl;
    }
    // Output: Result is 15.

    char grade = 'B';
    switch (grade) {          // char works fine
        case 'A': cout << "Excellent!" << endl; break;
        case 'B': cout << "Good!" << endl; break;
        default: cout << "Not specified." << endl;
    }
    // Output: Good!

    /*
    FALL-THROUGH:
    If you omit 'break', execution continues into the NEXT case (even if it
    doesn't match) until a break or the switch ends. This is intentional
    behavior in C++, not a bug -- can be used deliberately to group cases.
    */
    int n = 2;
    switch (n) {
        case 1:
        case 2:
        case 3:
            cout << "1, 2, or 3" << endl;   // multiple cases sharing one block
            break;
        case 4:
            cout << "4" << endl;
        case 5:                             // no break above -> falls through into 5 too
            cout << "4 or fell through from 4" << endl;
            break;
        default:
            cout << "Other" << endl;
    }
    // n = 2 -> Output: 1, 2, or 3
    // n = 4 -> Output: 4
    //                  4 or fell through from 4   (fall-through in action)

    /*
    COMMON PITFALLS:
    1. Forgetting 'break' unintentionally -> unwanted fall-through into next case.
    2. 'default' can be placed anywhere in the switch, but it's best practice to
       put it last for readability.
    3. Can't declare a variable inside a case without braces {} if it's used in
       another case -> wrap the case body in {} to give it its own scope.
       case 1: { int temp = 5; cout << temp; break; }
    4. Switch cannot test ranges (e.g. case 1-10) or non-constant conditions --
       use if-else for that.
    */

    /*
    PERFORMANCE NOTE:
    A long if-else chain checks conditions one by one -> O(n) in the worst case.
    A switch on small/dense integer values is often compiled into a JUMP TABLE
    by the compiler -> can jump directly to the matching case in O(1), instead
    of comparing sequentially. This is why switch is preferred over if-else
    when you have many exact-match cases on the same variable.
    */

    /*
    SWITCH WITH ENUM (very common combo):
    enums give named constants, which switch naturally compares against --
    more readable than raw magic numbers, and compiler can warn you if a
    case is missing.
    */
    enum Color { RED, GREEN, BLUE };
    Color c = GREEN;
    switch (c) {
        case RED:   cout << "Red" << endl;   break;
        case GREEN: cout << "Green" << endl; break;
        case BLUE:  cout << "Blue" << endl;  break;
    }
    // Output: Green

    return 0;
}
