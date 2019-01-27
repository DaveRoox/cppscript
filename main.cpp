#include <iostream>
#include "jsvalue/jsvalue.h"

using namespace std;

int main() {

    let u; // Creating an undefined variable

    constlet uu;

    jsarray aaa = {"1", 1, true};
    cout << aaa.length << endl;

    cout << uu.toString() << endl;

    cout << u.toString() << endl;

    let n = 99; // Creating a 'number' variable

    let b = false; // Creating a 'boolean' variable

    cout << b.toString() << endl;

    let s = "hello, world!"; // Creating a 'string' variable

    s[0] = 'H';

    let c = 'm'; // Creating a 'string' variable

    let ae = jsarray{}; // Creating an empty 'array' variable

    let ai = {u, n, b, s, c}; // Creating an inizialized 'array' variable

    ai[3][0] = 'h';

    cout << s << endl;

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

    ao[0]["myArray"][3][0] = 's';
    cout << s << endl;

    cout << ao << endl;
    return 0;
}