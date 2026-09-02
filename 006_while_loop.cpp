#include <iostream>
using namespace std;
/*
WHILE LOOP:
- Executes a block of code repeatedly AS LONG AS a condition remains true.
- Condition is checked BEFORE each iteration (entry-controlled loop).
- If the condition is false from the start, the body NEVER executes -- unlike
  do-while, which always runs at least once.

Flow:
1. Evaluate test expression.
2. If true -> execute loop body.
3. Re-evaluate test expression.
4. Repeat until it becomes false -> loop terminates.
*/
int main() {
    int n = 5;
    int factorial = 1;

    while (n > 0) {
        factorial *= n;   // multiply running product by current n
        n--;               // decrement n toward the stopping condition
    }
    cout << "Factorial of 5 is: " << factorial << endl;
    // Output: Factorial of 5 is: 120

    /*
    WHILE THAT NEVER RUNS (condition false at start):
    */
    int x = 10;
    while (x < 5) {
        cout << "This never prints" << endl;
    }
    cout << "Skipped the loop, x is still " << x << endl;
    // Output: Skipped the loop, x is still 10

    /*
    DO-WHILE (exit-controlled variant):
    Checks the condition AFTER running the body -> guarantees at least ONE
    execution even if the condition is false from the start. Common for
    menus / input validation where you must show something before checking.
    */
    int y = 10;
    do {
        cout << "This runs once regardless: y = " << y << endl;
        y++;
    } while (y < 5);
    // Output: This runs once regardless: y = 10   (then stops, since 11 < 5 is false)

    /*
    while vs for:
    - for loop  -> best when you know the number of iterations in advance
                   (init, condition, update all in one place).
    - while loop -> best when the number of iterations is NOT known upfront,
                     and depends on a condition evaluated dynamically
                     (e.g. reading input until a sentinel value, searching
                     until found).
    */

    /*
    COMMON USE CASE: validating input until it's acceptable.
    */
    int age = -1;
    // Example structure (input omitted here for a static demo):
    // while (age < 0) {
    //     cout << "Enter a valid age: ";
    //     cin >> age;
    // }

    /*
    break and continue work the same way as in for loops:
    - break    -> exits the while loop immediately.
    - continue -> skips to the next condition check, skipping rest of body.
    */
    int i = 0;
    while (i < 10) {
        i++;
        if (i == 3) continue;   // skip printing 3
        if (i == 6) break;      // stop entirely once i hits 6
        cout << i << " ";
    }
    cout << endl;
    // Output: 1 2 4 5

    /*
    COMMON PITFALLS:
    1. Forgetting to update the variable that controls the condition ->
       infinite loop. E.g. forgetting n-- above would loop forever.
    2. Off-by-one in the condition (< vs <=) changes iteration count by one.
    3. Confusing while vs do-while: use do-while only when you deliberately
       need the body to run at least once before the first check.
    4. Condition depending on floating-point equality (while (x != 10.0))
       may never become false due to precision errors -- use a range/tolerance
       or an integer counter instead.
    */

    return 0;
}
