#include <iostream>
#include "jsvalue/jsvalue.h"

using namespace std;

void f(const jsvariable &_, const unsigned long i, const jsarray &arr) {
    cout << i << " -> " << jsboolean{(jsnumber) arr[i] >= 35} << endl;
};

int main() {

    let u; // Creating an undefined variable

    jsarray aaa = {"1", 1, true};
    cout << aaa.length << endl;

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
            {"myArray",  ai},
            {"myNumber", n}
    };

    let ao = { // Creating an inizialized array of objects
            oi,
            jsobject{
                    {"myBool",   b},
                    {"myString", s}
            }
    };

    ao[0]["myArray"][3][0] = 's';
    cout << s << endl;

    cout << ao << endl;

    cout << ((jsarray) ao).concat(false, 1, 2.88, "ciao", 'c', jsarray{"key", "value"}) << endl;

    jsarray lol = {"Banana", "Orange", "Apple", "Mango", "Ananas"};
    cout << lol.copyWithin(2, 0, 4) << endl;
    cout << lol.entries() << endl;

    jsarray survey{
            jsobject{{"name",   "Steve"},
                     {"answer", "Yes"}},
            jsobject{{"name",   "Jessica"},
                     {"answer", "Yes"}},
            jsobject{{"name",   "Peter"},
                     {"answer", "Yes"}},
            jsobject{{"name",   "Elaine"},
                     {"answer", "Yes"}}
    };

    jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)> is_same_answer{
            [](const jsvariable &el, unsigned long index, const jsarray &arr) -> bool {
                if (index == 0)
                    return true;
                return el["answer"] == arr[index - 1]["answer"];
            }
    };

    cout << survey.every(is_same_answer) << endl;

    jsarray ages{32, 33, 12, 40};

    cout << ages.every({[](const jsvariable &age) { return (jsnumber) age < 13; }}) << endl;

    jsarray fruits = jsarray{"Banana", "Orange", "Apple", "Mango"};
    cout << fruits.fill(true, 0, 2) << endl;

    cout << ages.filter({[](const jsvariable &age) { return (jsnumber) age >= 88; }}) << endl;

    cout << ages.findIndex({[](const jsvariable &age) { return (jsnumber) age >= 35; }}) << endl;

    cout << ages.find({[](const jsvariable &age) { return (jsnumber) age > 99; }}) << endl;

    ages.forEach<void>({f}, ages.fill(40, 0, 2));

    ages.forEach(
            jsfunction<void(const jsvariable &age, unsigned long index, const jsarray &people)>{
                    [](const jsvariable &age, unsigned long index, const jsarray &people) -> void {
                        cout << people[index] << " is " << age << " years old!\n";
                    }
            },
            {"Marta", "Gennaro", "Pasquale", "Giovanna"}
    );

    return 0;
}