#include <bits/stdc++.h>
using namespace std;
/*
IF-ELSE:
- 'if' executes a block only when its condition is true.
- 'else' (optional) executes when the 'if' condition is false.
- Flow: condition true -> run if-block; condition false -> run else-block (if present).
*/
int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are an adult." << endl;
    } else {
        cout << "You are not an adult." << endl;
    }
    // Input: 20   -> Output: You are an adult.
    // Input: 15   -> Output: You are not an adult.

    /*
    ELSE IF:
    - Used to check multiple conditions in sequence instead of nested/independent ifs.
    - Conditions are checked top to bottom; first true one runs, rest are skipped.
    */
    int marks = 54;

    if (marks < 25) {
        cout << "Grade: F" << endl;
    } else if (marks >= 25 && marks <= 44) {
        cout << "Grade: E" << endl;
    } else if (marks >= 45 && marks <= 49) {
        cout << "Grade: D" << endl;
    } else if (marks >= 50 && marks <= 59) {
        cout << "Grade: C" << endl;
    } else if (marks >= 60 && marks <= 69) {
        cout << "Grade: B" << endl;
    } else if (marks >= 70) {
        cout << "Grade: A" << endl;
    } else {
        cout << "Invalid marks entered." << endl;
    }
    // marks = 54 -> Output: Grade: C

    /*
    REFACTOR - drop lower bounds:
    Since conditions are checked in order and only reached if all previous ones
    were false, checking marks <= 44 already implies marks >= 25 was already
    ruled false by earlier checks (or marks < 25 caught it first). So the lower
    bound is redundant -> only the upper bound needs to be checked each time.
    */
    if (marks < 25) {
        cout << "Grade: F" << endl;
    } else if (marks <= 44) {
        cout << "Grade: E" << endl;
    } else if (marks <= 49) {
        cout << "Grade: D" << endl;
    } else if (marks <= 59) {
        cout << "Grade: C" << endl;
    } else if (marks <= 69) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: A" << endl;
    }
    // marks = 54 -> Output: Grade: C   (same result, fewer comparisons)

    /*
    TERNARY OPERATOR (short-hand if-else):
    condition ? value_if_true : value_if_false
    Good for simple one-line assignments, not for complex logic.
    */
    string result = (age >= 18) ? "Adult" : "Minor";
    cout << result << endl;
    // age = 20 -> Output: Adult

    /*
    NESTED IF:
    An if/else inside another if/else -> used when a second condition only
    matters after the first one is satisfied.
    */
    int num = 15;
    if (num > 0) {
        if (num % 2 == 0) {
            cout << "Positive even" << endl;
        } else {
            cout << "Positive odd" << endl;
        }
    } else {
        cout << "Not positive" << endl;
    }
    // num = 15 -> Output: Positive odd

    /*
    SHORT-CIRCUIT EVALUATION:
    && stops evaluating as soon as one operand is false (whole expr is false).
    || stops evaluating as soon as one operand is true (whole expr is true).
    Useful to avoid errors, e.g. checking a pointer/index before using it.
    */
    int arr[3] = {1, 2, 3};
    int idx = 5;
    if (idx < 3 && arr[idx] > 0) {
        cout << "Safe access" << endl;
    } else {
        cout << "Skipped unsafe access" << endl;   // arr[idx] never evaluated, no crash
    }
    // Output: Skipped unsafe access

    /*
    COMMON PITFALLS:
    1. Using '=' instead of '==' inside a condition assigns instead of compares.
       if (age = 18)   -> BUG: always true (assigns 18 to age, non-zero = true)
       if (age == 18)  -> correct comparison

    2. Stray semicolon after if -> the if does nothing, block always runs.
       if (age >= 18);              // <- semicolon ends the if here!
       { cout << "Adult" << endl; } // this runs unconditionally

    3. Comparing floating-point numbers with == is unreliable due to precision.
       Prefer: fabs(a - b) < 1e-9   instead of   a == b

    4. Dangling else: an 'else' always binds to the nearest unmatched 'if'.
       Use braces {} to make intent explicit when nesting ifs.
    */

    return 0;
}
