//
// Created by Davide Russo on 2019-01-25.
//

#ifndef C_SCRIPT_JSVARIABLE_H
#define C_SCRIPT_JSVARIABLE_H

#include <memory>

class jsvalue;

class jsnumber;

class jsstring;

class jsboolean;

class jsarray;

class jsobject;

class jsuvariable;

template<typename Func>
class jsfunction;

enum class constructor_t {
    Object,
    Array,
    Number,
    String,
    Boolean,
    Function,
    Undefined
};

class jsvariable {

private:
    std::shared_ptr<jsvalue> value;
    constructor_t _type;

public:
    explicit jsvariable();

    jsvariable(const jsvariable &);

    jsvariable(jsnumber);

    jsvariable(long double);

    jsvariable(unsigned short);

    jsvariable(signed short);

    jsvariable(unsigned int);

    jsvariable(signed int);

    jsvariable(float);

    jsvariable(double);

    jsvariable(unsigned long);

    jsvariable(signed long);

    jsvariable(unsigned long long);

    jsvariable(signed long long);

    jsvariable(jsstring);

    jsvariable(std::string);

    jsvariable(const char *);

    jsvariable(signed char);

    jsvariable(jsboolean);

    jsvariable(bool);

    jsvariable(jsarray);

    jsvariable(std::initializer_list<jsvariable>);

    jsvariable(jsobject);

    jsvariable(std::initializer_list<std::pair<const std::string, jsvariable>>);

    jsvariable &operator=(const jsvariable &);

    bool operator==(const jsvariable &) const;

    jsuvariable operator[](unsigned long) noexcept(false);

    const jsuvariable operator[](unsigned long) const noexcept(false);

    jsvariable &operator[](const std::string &) noexcept(false);

    const jsvariable &operator[](const std::string &) const noexcept(false);

    std::string toString() const;

    explicit operator bool() const;

    explicit operator jsarray() const;

    explicit operator jsnumber() const;

    const constructor_t &constructor;

    const static jsvariable undefined;

};

class jsuvariable {
private:
    jsvariable *v;
    char *c;
public:
    jsuvariable(jsvariable &_v) : v{&_v}, c{nullptr} {}

    jsuvariable(char &_c) : v{nullptr}, c{&_c} {}

    char &operator=(const char &_c);

    char &operator=(char &&_c);

    jsvariable &operator=(const jsvariable &_v);

    jsvariable &operator=(jsvariable &&_v);

    /**/

    jsuvariable operator[](unsigned long) noexcept(false);

    const jsuvariable operator[](unsigned long) const noexcept(false);

    jsvariable &operator[](const std::string &) noexcept(false);

    const jsvariable &operator[](const std::string &) const noexcept(false);

    explicit operator bool() const;

    /**/

    std::string str() const;

};

std::ostream &operator<<(std::ostream &, const jsvariable &);

std::ostream &operator<<(std::ostream &, const jsuvariable &);

using let = jsvariable;

#endif //C_SCRIPT_JSVARIABLE_H
