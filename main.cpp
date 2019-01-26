#include <iostream>
#include "jsvalue/jsvalue.h"

using namespace std;

int main() {

    let u; // Creating an undefined variable

    let n = 99; // Creating a 'number' variable

    let b = false; // Creating a 'boolean' variable

    let s = "hello, world!"; // Creating a 'string' variable

    let c = 'm'; // Creating a 'string' variable

    let ae = jsarray{}; // Creating an empty 'array' variable

    let ai = {u, n, b, s, c}; // Creating an inizialized 'array' variable

    let oe = jsobject{}; // Creating an empty 'object' variable

    let oi = jsobject{ // Creating an inizialized 'object' variable
            {"myArray", ai},
            {"myNumber", n}
    };

    let ao = { // Creating an inizialized array of objects
            oi,
            jsobject{
                    {"myBool", b},
                    {"myString", s}
            }
    };

    cout << ao << endl;
    return 0;
}