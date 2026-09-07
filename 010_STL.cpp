#include <bits/stdc++.h>
using namespace std;
/*
C++ STL (STANDARD TEMPLATE LIBRARY)
Pre-built, tested containers and algorithms -- avoids writing data
structures like dynamic arrays, hash maps, heaps, etc. from scratch.
Two main parts: CONTAINERS (store data) and ALGORITHMS (operate on data).
Below covers the most frequently used ones for competitive programming
and interviews.
*/

int main() {
    /*
    PAIR: bundles two values together. Useful as map entries, or storing
    (value, index) / (x, y) style data.
    */
    pair<int, string> p = {1, "apple"};
    cout << p.first << " " << p.second << endl;
    // Output: 1 apple

    /*
    VECTOR: dynamic array -- resizes automatically, contiguous memory.
    Most-used container by far.
    */
    vector<int> v = {5, 2, 8};
    v.push_back(10);          // add to end -> {5, 2, 8, 10}
    v.pop_back();              // remove from end -> {5, 2, 8}
    v.insert(v.begin() + 1, 99); // insert 99 at index 1 -> {5, 99, 2, 8}
    v.erase(v.begin());         // remove index 0 -> {99, 2, 8}
    cout << "size: " << v.size() << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
    // Output: size: 3
    //         99 2 8

    /*
    SET: stores UNIQUE elements, automatically sorted (ordered, tree-based).
    Insert/erase/find are O(log n).
    */
    set<int> s = {5, 1, 3, 1, 5};   // duplicates auto-removed
    s.insert(2);
    for (int x : s) cout << x << " ";
    cout << endl;
    // Output: 1 2 3 5   (sorted, unique)
    cout << (s.find(3) != s.end()) << endl;   // 1 = found
    // Output: 1

    /*
    UNORDERED_SET: same as set (unique elements) but hash-based -- no
    ordering, average O(1) insert/find instead of O(log n). Use this when
    you don't need sorted order and just want fast lookups.
    */
    unordered_set<int> us = {5, 1, 3};
    cout << us.count(1) << endl;   // 1 if present, 0 if not
    // Output: 1

    /*
    MULTISET: like set, but ALLOWS duplicates. Still kept sorted.
    */
    multiset<int> ms = {1, 1, 2, 3};
    ms.erase(ms.find(1));   // erases only ONE occurrence of 1
    for (int x : ms) cout << x << " ";
    cout << endl;
    // Output: 1 2 3

    /*
    MAP: key -> value store, keys are UNIQUE and kept SORTED by key.
    O(log n) operations.
    */
    map<string, int> m;
    m["apple"] = 3;
    m["banana"] = 5;
    m["apple"]++;             // access + modify like a normal variable
    for (auto &[key, val] : m) cout << key << ":" << val << " ";
    cout << endl;
    // Output: apple:4 banana:5   (sorted by key)

    /*
    UNORDERED_MAP: like map, but hash-based -- no order, average O(1)
    operations. The go-to choice for frequency counting / fast lookups
    when order doesn't matter.
    */
    unordered_map<string, int> freq;
    vector<string> words = {"a", "b", "a", "c", "a"};
    for (auto &w : words) freq[w]++;
    for (auto &[key, val] : freq) cout << key << ":" << val << " ";
    cout << endl;
    // Output (order not guaranteed): a:3 b:1 c:1

    /*
    STACK: LIFO (Last In, First Out). push adds to top, pop removes from
    top, top() peeks. No iteration/indexing allowed.
    */
    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << st.top() << endl;   // 3 (last one pushed)
    st.pop();                    // removes 3
    cout << st.top() << endl;   // 2
    // Output: 3
    //         2

    /*
    QUEUE: FIFO (First In, First Out). push adds to back, pop removes
    from front, front()/back() peek either end.
    */
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << q.front() << endl;   // 1 (first one pushed)
    q.pop();                      // removes 1
    cout << q.front() << endl;   // 2
    // Output: 1
    //         2

    /*
    DEQUE (double-ended queue): push/pop from BOTH ends efficiently,
    and unlike stack/queue, still supports random access via [index].
    */
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(0);
    dq.push_back(2);
    for (int x : dq) cout << x << " ";
    cout << endl;
    // Output: 0 1 2

    /*
    PRIORITY_QUEUE: a heap. Default = MAX-HEAP (largest element on top).
    For a MIN-HEAP, pass greater<int> as the comparator.
    */
    priority_queue<int> maxHeap;
    maxHeap.push(3); maxHeap.push(1); maxHeap.push(4);
    cout << maxHeap.top() << endl;   // 4 (largest)
    // Output: 4

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3); minHeap.push(1); minHeap.push(4);
    cout << minHeap.top() << endl;   // 1 (smallest)
    // Output: 1

    /*
    LIST: doubly linked list. O(1) insert/delete anywhere (given an
    iterator), but NO random access (no list[i]). Rarely the first
    choice -- vector/deque usually preferred unless you need frequent
    mid-list insertion/deletion.
    */
    list<int> l = {1, 2, 3};
    l.push_front(0);
    for (int x : l) cout << x << " ";
    cout << endl;
    // Output: 0 1 2 3

    /*
    SORT(): sorts a range in-place, default ascending, O(n log n).
    Pass a custom comparator (lambda) for custom order.
    */
    vector<int> nums = {5, 2, 8, 1};
    sort(nums.begin(), nums.end());              // ascending
    for (int x : nums) cout << x << " ";
    cout << endl;
    // Output: 1 2 5 8

    sort(nums.begin(), nums.end(), greater<int>()); // descending
    for (int x : nums) cout << x << " ";
    cout << endl;
    // Output: 8 5 2 1

    /*
    NEXT_PERMUTATION(): rearranges a range into the NEXT lexicographically
    greater permutation. Returns false (and wraps to sorted order) once
    the last permutation is reached. Must start SORTED to get all
    permutations from the beginning.
    */
    vector<int> perm = {1, 2, 3};
    do {
        for (int x : perm) cout << x << " ";
        cout << "| ";
    } while (next_permutation(perm.begin(), perm.end()));
    cout << endl;
    // Output: 1 2 3 | 1 3 2 | 2 1 3 | 2 3 1 | 3 1 2 | 3 2 1 |

    /*
    __builtin_popcount(): counts the number of SET BITS (1s) in the
    binary representation of an integer. GCC built-in, O(1)-ish, very
    fast -- common in bitmasking problems. Use __builtin_popcountll for
    long long.
    */
    cout << __builtin_popcount(13) << endl;   // 13 = 1101 in binary -> 3 set bits
    // Output: 3

    /*
    MIN_ELEMENT() / MAX_ELEMENT(): return an ITERATOR to the smallest/
    largest element in a range. Dereference (*) to get the actual value.
    */
    vector<int> arr = {4, 2, 9, 1};
    cout << *min_element(arr.begin(), arr.end()) << endl;   // 1
    cout << *max_element(arr.begin(), arr.end()) << endl;   // 9
    // Output: 1
    //         9

    return 0;
}

/*
SUMMARY

CONTAINER QUICK REFERENCE:
vector           -> dynamic array, random access, grows at the end
set               -> unique + sorted, O(log n) ops
unordered_set     -> unique, no order, avg O(1) ops
multiset          -> like set but allows duplicates
map               -> key-value, unique keys, sorted by key, O(log n)
unordered_map     -> key-value, no order, avg O(1) -- best for frequency counts
stack             -> LIFO: push/pop/top
queue             -> FIFO: push/pop/front/back
deque             -> push/pop from BOTH ends + random access
priority_queue    -> heap; max-heap by default, greater<int>() for min-heap
list              -> doubly linked list, O(1) insert/delete, no random access

ALGORITHM QUICK REFERENCE:
sort(begin, end)                  -> O(n log n), pass comparator for custom order
next_permutation(begin, end)      -> generates permutations in lex order
__builtin_popcount(x)             -> count of set bits in x
min_element / max_element         -> returns ITERATOR; dereference with *

CHOOSING A CONTAINER:
Need order preserved + duplicates?      -> vector
Need uniqueness + sorted order?         -> set
Need uniqueness + fastest lookup?       -> unordered_set
Need key-value + sorted by key?         -> map
Need key-value + fastest lookup?        -> unordered_map (e.g. frequency count)
Need LIFO behavior?                     -> stack
Need FIFO behavior?                     -> queue
Need max/min repeatedly extracted?      -> priority_queue
*/
```
