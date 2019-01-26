//
// Created by Davide Russo on 2019-01-25.
//

#ifndef C_SCRIPT_JSVALUE_H
#define C_SCRIPT_JSVALUE_H

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "jsvariable.h"

class jsvalue {

public:
    virtual std::string str() const = 0;

    virtual std::string pretty_printed(unsigned short) const = 0;

    virtual ~jsvalue() = default;

};

class jsnumber : public jsvalue {

private:
    long double value;

public:
    jsnumber(long double _value) : value{_value} {}

    jsnumber(short _value) : value(_value) {}

    jsnumber(int _value) : value(_value) {}

    jsnumber(float _value) : value(_value) {}

    jsnumber(double _value) : value(_value) {}

    jsnumber(long _value) : value(_value) {}

    jsnumber(long long _value) : value(_value) {}

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;

};

class jsstring : public jsvalue {

private:
    std::string value;

public:
    jsstring(std::string _value) : value{std::move(_value)} {}

    jsstring(const char *_value) : value{_value} {}

    jsstring(char c) : value{c} {}

    jsstring(jsstring &&other) noexcept : value{std::move(other.value)} {}

    jsstring &operator=(jsstring &&other) noexcept;

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;

};

class jsboolean : public jsvalue {

private:
    static std::string values[2];
    bool value;

public:
    jsboolean(bool _value) : value{_value} {}

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;

};

class jsobject : public jsvalue {

private:
    std::unordered_map<std::string, jsvariable> values;

public:

    jsobject() = default;

    jsobject(std::initializer_list<std::pair<const std::string, jsvariable>>);

    jsobject(const jsobject &);

    jsobject(jsobject &&) noexcept;

    jsobject &operator=(const jsobject &);

    jsobject &operator=(jsobject &&) noexcept;

    jsvariable &operator[](const std::string &) noexcept(false);

    const jsvariable &operator[](const std::string &) const noexcept(false);

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;

};

class jsarray : public jsvalue {

private:
    std::vector<jsvariable> values;

public:

    jsarray() = default;

    jsarray(std::initializer_list<jsvariable>);

    jsarray(const jsarray &);

    jsarray(jsarray &&) noexcept;

    jsarray &operator=(const jsarray &);

    jsarray &operator=(jsarray &&) noexcept;

    const jsvariable &operator[](unsigned long) const noexcept(false);

    jsvariable &operator[](unsigned long) noexcept(false);

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;

};

template<typename Func>
class jsfunction : public jsvalue {
private:
    std::function<Func> value;
public:
    jsfunction() = default;

    std::string str() const override;

    std::string pretty_printed(unsigned short) const override;
};

template<typename Func>
std::string jsfunction<Func>::str() const {
    return std::string{"[Function "} + typeid(Func).name() + "]";
}

#endif //C_SCRIPT_JSVALUE_H