#include <iostream>
using namespace std;
/*
TIME COMPLEXITY
- Measures how the number of operations grows as input size N grows.
- NOT the actual time in seconds -- that depends on the machine (a fast
  laptop and an old PC take different real time for the SAME code).
- Expressed using Big O notation: O(...) describes the GROWTH RATE relative to N.

RULES FOR CALCULATING TIME COMPLEXITY:
1. Always consider the WORST CASE (maximum steps possible).
2. Drop constants:      O(3N)         -> O(N)
3. Drop lower-order terms: O(N^2 + N) -> O(N^2)
   (for large N, the smaller term becomes insignificant)
*/

// ---------- O(1): CONSTANT TIME ----------
// Number of steps does NOT depend on input size.
void constantTime(int arr[]) {
    cout << arr[0] << endl;   // accessing any single index is always 1 step
}

// ---------- O(N): LINEAR TIME ----------
// Steps grow directly proportional to N.
void linearTime(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " ";   // runs exactly n times
    }
}

// ---------- O(N^2): QUADRATIC TIME ----------
// Nested loop over the same N -> N * N steps.
void quadraticTime(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << "," << j << " ";
        }
    }
}

// ---------- O(log N): LOGARITHMIC TIME ----------
// Each step eliminates HALF the remaining elements (e.g. binary search).
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;          // half the array is discarded each time
    }
    return -1;
}

// ---------- O(N log N): "LINEARITHMIC" TIME ----------
// Typical for efficient sorting algorithms (merge sort, heap sort).
// N elements, each processed with a log N operation (e.g. via a heap).

// ---------- O(2^N): EXPONENTIAL TIME ----------
// Doubles with every extra input element -- common in naive recursion
// (e.g. computing Fibonacci recursively without memoization).
int fibonacciSlow(int n) {
    if (n <= 1) return n;
    return fibonacciSlow(n - 1) + fibonacciSlow(n - 2);   // 2 recursive branches each call
}

// ---------- O(N!): FACTORIAL TIME ----------
// Grows even faster than exponential -- typical for generating all
// permutations of N items. Very inefficient, rarely the optimal solution.

/*
BEST CASE vs WORST CASE vs AVERAGE CASE
Example: grading based on marks (if-else ladder)
- Best case:    marks = 10  -> only 1 condition checked, exits immediately.
- Worst case:   marks = 90  -> every condition checked before the last one matches.
- Average case: somewhere in between.
We always report the WORST CASE, because that's what guarantees how the
code behaves under the heaviest possible load.
*/
void grade(int marks) {
    if (marks < 25) cout << "F";
    else if (marks <= 44) cout << "E";
    else if (marks <= 49) cout << "D";
    else if (marks <= 59) cout << "C";
    else if (marks <= 69) cout << "B";
    else cout << "A";                 // worst case: every condition above was checked first
}

// ---------- O(sqrt N): rare but worth knowing ----------
// Example: checking primality -- only need to check divisors up to sqrt(n),
// since factors pair up (if d divides n, so does n/d).
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {   // loop runs ~sqrt(n) times
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    /*
    SPACE COMPLEXITY
    - Measures the memory a program uses while running.
    - Also expressed with Big O, also independent of the machine.
    - Space complexity = INPUT SPACE + AUXILIARY SPACE
        Input space:     memory used to store the given inputs.
        Auxiliary space: EXTRA memory used to actually solve the problem.
    */
    int a = 5, b = 10;
    int c = a + b;         // c is extra/auxiliary space -> O(1) auxiliary space
    cout << c << endl;

    int n = 5;
    int arr[5];             // storing n elements -> O(N) space
    for (int i = 0; i < n; i++) arr[i] = i;

    /*
    GOOD PRACTICE: don't manipulate the given input to save space.
    Example: to "add" a and b, you COULD do b = a + b instead of using a
    new variable c -- this technically saves O(1) space, but it destroys
    the original value of b. In interviews, never modify the given input
    unless the interviewer explicitly says it's fine to do so.
    */

    /*
    ONLINE JUDGE / COMPETITIVE PROGRAMMING RULE OF THUMB:
    Most online judges execute roughly 10^8 operations per second.
    - Time limit 1s -> your algorithm should do about O(10^8) operations.
    - Time limit 2s -> about O(2 * 10^8) operations.
    Use this to sanity-check whether your chosen approach will pass in time,
    based on the given constraints on N.
    */

    /*
    RECURSION AND SPACE COMPLEXITY (commonly missed):
    Every recursive call adds a frame to the CALL STACK, and that frame stays
    in memory until the call returns. So recursive functions have a hidden
    space cost equal to the maximum DEPTH of recursion -- not just whatever
    variables you declare inside.
    fibonacciSlow(n) above -> O(N) space (deepest chain of calls is N deep),
    even though its TIME complexity is O(2^N). Time and space complexity
    are tracked separately and often differ.
    */

    return 0;
}

/*
SUMMARY

COMMON TIME COMPLEXITIES (fastest to slowest):
O(1)         -> constant       : array index access, hash map insert/lookup
O(log N)     -> logarithmic    : binary search, balanced BST search, heap push/pop
O(sqrt N)    -> root           : primality check, finding factors of N
O(N)         -> linear         : single loop, linear search, traversing a list
O(N log N)   -> linearithmic   : efficient sorting (merge sort, heap sort)
O(N^2)       -> quadratic      : nested loops over N, insertion sort
O(2^N)       -> exponential    : naive recursion with 2 branches (e.g. Fibonacci)
O(N!)        -> factorial      : generating all permutations

SPACE COMPLEXITY:
Input space      -> memory to store the inputs themselves.
Auxiliary space  -> extra memory used to solve the problem.
Space complexity = input space + auxiliary space.

WHEN CALCULATING COMPLEXITY:
1. Use the worst case.
2. Drop constants.
3. Drop lower-order (less significant) terms.

Big O (O)     -> describes the UPPER bound / worst case (most commonly used).
Theta (Θ)     -> describes the TIGHT bound (average case behavior).
Omega (Ω)     -> describes the LOWER bound / best case.
(Θ and Ω are less important for interviews -- Big O is what's typically asked.)
*/
