#include <iostream>
using namespace std;
/*
FOR LOOP:
- Control structure to execute a block of code repeatedly without duplicating it.
- Three components inside for( ; ; ):
  1. Initialization -> runs ONCE at the start (declare/init counter).
  2. Condition      -> checked BEFORE each iteration; loop stops when false.
  3. Update         -> increment/decrement, runs AFTER each iteration's body.
*/
int main() {
    for (int i = 1; i <= 10; i++) {
        cout << "Hey, Striver, this is the " << i << "'th iteration" << endl;
    }
    // Runs 10 times: i = 1,2,...,10. Loop stops when i becomes 11 (condition false).

    /*
    FLOW:
    Start -> Initialize counter -> Check condition
      -> if true: run loop body -> update counter -> go back to condition check
      -> if false: exit loop, continue with rest of program
    */

    /*
    NESTED FOR LOOPS:
    A loop inside another loop -- inner loop completes ALL its iterations for
    each single iteration of the outer loop. Useful for grids, matrices, patterns.
    */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
    // Output: 9 lines total (3 outer * 3 inner), i=0 with j=0,1,2 then i=1 with j=0,1,2...

    /*
    CONDITIONALS INSIDE FOR LOOPS:
    Standard if-else can be used inside the loop body per iteration.
    */
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            cout << i << " is even" << endl;
        } else {
            cout << i << " is odd" << endl;
        }
    }

    /*
    CUSTOM STEP SIZE:
    The update part isn't limited to i++ / i-- ; any expression works.
    */
    for (int i = 1; i <= 25; i += 5) {
        cout << "i = " << i << endl;
    }
    // Output: i = 1, 6, 11, 16, 21   (step of 5 instead of 1)

    /*
    REVERSE LOOP:
    Start high, decrement toward the condition.
    */
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    // Output: 5 4 3 2 1

    /*
    LOOPING OVER AN ARRAY:
    Very common use case -- index-based traversal.
    */
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Output: 10 20 30 40 50

    /*
    break vs continue (loop control keywords):
    - break    -> exits the loop entirely, skips remaining iterations.
    - continue -> skips the REST of the current iteration, moves to next one.
    */
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;   // skip printing 3
        if (i == 5) break;      // stop loop entirely before printing 5
        cout << i << " ";
    }
    cout << endl;
    // Output: 1 2 4      (3 skipped via continue, 5 never reached due to break)

    /*
    INFINITE LOOP:
    Omitting all three parts creates an infinite loop -- must break manually
    from inside, otherwise it never stops. Common in event loops / menus.
    */
    int count = 0;
    for (;;) {
        count++;
        if (count == 3) break;
    }
    cout << "count = " << count << endl;
    // Output: count = 3   (loop ran 3 times, then broke out manually)

    /*
    COMMON PITFALLS:
    1. Off-by-one errors: using <= vs < wrong shifts the loop by one iteration
       (e.g. i < 10 runs 10 times for i=0..9, i <= 10 runs 11 times for i=0..10).
    2. Modifying the loop counter inside the body (e.g. i++ inside, on top of
       the loop's own i++) causes unexpected skipping -- avoid unless intentional.
    3. Infinite loop by mistake: wrong condition direction, e.g.
       for (int i = 10; i >= 0; i++)   // i never decreases -> runs forever
    4. Declaring the loop variable outside when it's only needed inside limits
       readability and can cause naming clashes -- prefer declaring it in the
       initialization part (scoped to the loop) unless you need it after.
    */

    return 0;
}
