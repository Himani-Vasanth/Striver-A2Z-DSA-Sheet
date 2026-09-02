#include <iostream>
#include <bits/stdc++.h>
/*
ARRAY:
- Linear data structure, stores similar (homogeneous) type elements.
- Elements are in contiguous memory locations (one after another).
- Random access via index -> O(1) time, since computer knows exact memory location.
- 0-indexed: simplifies memory computation (address = base + index * size),
  though it adds an (n-1) subtraction step conceptually. Most languages do this.
- Fixed size + fixed type, defined at creation time; memory reserved instantly.
- Cannot store heterogeneous data (no mixing int, string, bool in same array).

Syntax: Data_type array_name [Array_size];
*/
int main() {
    int myArray[8];   // int -> datatype, myArray -> name, [8] -> size (reserved in memory)

    myArray[0] = 10;
    myArray[1] = 20;
    myArray[2] = 30;
    std::cout << myArray[0] << " " << myArray[1] << " " << myArray[2] << "\n";
    // Output: 10 20 30

    /*
    Finding an element in an array (3 ways):
    1. Know the index -> direct access via index, O(1).
    2. Don't know index -> search algorithms (Linear Search, Binary Search).
    3. Need repeated fast lookups -> store in hash-based structure (hash set/map).

    Summary:
    - Memory allocated instantly on creation; array is empty until values assigned.
    - Contiguous elements -> O(1) direct access via index.
    - Insertion at end -> O(1). Insertion at start/middle -> more complex (shifting).
    - Removal at known index -> O(1).
    */

    using namespace std;
    /*
    STRING:
    - A string is a sequence of characters, also 0-indexed.
    - s[0] -> first char, s[1] -> second char, and so on.
    */
    string s = "striver";
    cout << "\n" << s[0] << " " << s[1] << " " << s[2] << "\n";
    // Output: s t r

    // Finding length of a string:
    cout << "Length: " << s.size() << "\n";      // or s.length();
    // Output: Length: 7

    /*
    Passing / Returning / Assigning strings:
    - Assigning one string to another makes a DEEP COPY (new char sequence),
      not a reference. Changing the copy won't affect the original.
    - Passing a string to a function (by value) also copies it;
      changes inside the function don't affect the original outside.
    */
    string a = "hello";
    string b = a;      // deep copy, b is independent of a
    b[0] = 'H';
    cout << a << " " << b << "\n";
    // Output: hello Hello   (a unchanged, only b modified)

    /*
    String Comparison:
    ==  Equality operator   -> true if values are equal
    !=  Inequality operator -> true if values are NOT equal
    Works for whole strings, and also for comparing individual characters.
    */
    string x = "cat", y = "cat", z = "dog";
    cout << (x == y) << " " << (x != z) << " " << (x[0] == y[0]) << "\n";
    // Output: 1 1 1   (true is printed as 1 in C++)
}
