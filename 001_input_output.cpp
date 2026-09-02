#include <iostream> //input output, <stdio.h> for C
#include <cmath> // math, <math.h> for C
#include <bits/stdc++.h> // include I/O

/*
<bits/stdc++.h> Includes almost all standard libraries at once.
Useful in competitive programming.
Not recommended for production (due to compile-time overhead).
*/

int main() {
    std::cout << "Hello World" << "\n";
    std::cout << "World";
    std::cout << "Hi" << std::endl << "learning" << std::endl;
    std::cout << "welcome";

    /*
    Output buffer:
    A temporary storage area where output is kept before being displayed.

    Flushing:
    Sending the stored output from the buffer to the screen immediately.

    \n         -> Moves to a new line (does not force output).
    std::endl -> Moves to a new line and flushes the buffer.

    Example:
        cout << "Loading..." << endl;
        this_thread::sleep_for(chrono::seconds(5));

    Here, "Loading..." appears before the 5-second wait because the buffer is
    flushed immediately.
    */

    using namespace std;

    cout << "\nboat";

    /*
    Writing using namespace std; removes the need to prefix std::. This makes
    code cleaner but can cause naming conflicts in large projects.

    using namespace std; lets you write cout instead of std::cout, but if you
    create your own cout, the compiler won't know whether you mean your cout or
    std::cout, causing a naming conflict.
    */

    char x;
    std::cout << "\n";
    cout << "Enter value of char x ";
    std::cin >> x;
    cout << "Val of x is: " << x << "\n";

    /*
    if input is 34 or fiffhio, prints only first char
    */

    int age = 21;                  // Copy Initialization (=): Most common way to initialize a variable.
    float height(5.7f);            // Direct Initialization (()): Initializes the variable directly using parentheses.
    double salary{45000.50};       // Uniform/List Initialization ({}): Modern C++ style; prevents narrowing conversions by producing a compile-time error.
    char grade = 'A';              // Copy Initialization (=): Initializes a single character.
    bool passed(true);             // Direct Initialization (()): Initializes a boolean value.
    string name{"JaneJohnDoe"};    // Uniform/List Initialization ({}): Modern way to initialize a string.

    /*
    narrowing: converting a value from a larger or more precise type to a smaller or less precise type, causing loss of data.
    int x = 3.5;    // Allowed (x becomes 3)
    int y(3.5);     // Allowed (y becomes 3)
    int z{3.5};     // Error: narrowing conversion
    */
}
