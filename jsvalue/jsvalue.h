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
    virtual std::string toString() const = 0;

    virtual ~jsvalue() = default;

};

class jsnumber : public jsvalue {

private:
    long double value;

public:
    jsnumber(long double _value) : value{_value} {}

    jsnumber(float _value) : value(_value) {}

    jsnumber(double _value) : value(_value) {}

    jsnumber(unsigned short _value) : value(_value) {}

    jsnumber(unsigned int _value) : value(_value) {}

    jsnumber(unsigned long _value) : value(_value) {}

    jsnumber(unsigned long long _value) : value(_value) {}

    jsnumber(signed short _value) : value(_value) {}

    jsnumber(signed int _value) : value(_value) {}

    jsnumber(signed long _value) : value(_value) {}

    jsnumber(signed long long _value) : value(_value) {}

    std::string toString() const override;

};

class jsstring : public jsvalue {

private:
    std::string value;

public:
    jsstring(std::string _value) : value{std::move(_value)} {}

    jsstring(const char *_value) : value{_value} {}

    jsstring(char _value) : value{_value} {}

    jsstring(const std::unique_ptr<char *> &_value) : value{} { value.push_back(**_value); };

    jsstring(jsstring &&other) noexcept : value{std::move(other.value)} {}

    jsstring &operator=(jsstring &&other) noexcept;

    const char &operator[](unsigned long) const noexcept(false);

    char &operator[](unsigned long) noexcept(false);

    std::string toString() const override;

};

class jsboolean : public jsvalue {

private:
    static const std::string values[2];
    bool value;

public:
    jsboolean(bool _value) : value{_value} {}

    std::string toString() const override;

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

    std::string toString() const override;

};

template<typename Func>
class jsfunction : public jsvalue {
private:
    std::function<Func> value;
public:

    jsfunction() = default;

    jsfunction(std::function<Func> f) : value{std::move(f)} {}

    std::string toString() const override;

};

class jsarray : public jsvalue {

    friend struct jsarray_iterator;

private:
    std::vector<jsvariable> values;
    unsigned long _size;

public:

    struct jsarray_iterator {

    private:
        jsarray &_array;

        std::string toString() const;

        friend class jsarray;

    public:
        const unsigned long key;
        jsvariable &value;

        jsarray_iterator(unsigned long _key, jsvariable &_value, jsarray &__array) :
                value{_value}, _array{__array}, key{_key} {}

        jsarray_iterator &operator=(const jsarray_iterator &) = delete;

        jsarray_iterator next() const;

    };

    struct jsarray_iterators {
    private:
        std::vector<jsarray_iterator> iterators;
        mutable unsigned long index;
    public:
        jsarray_iterators(std::vector<jsarray_iterator> &&_iterators) :
                iterators{std::move(_iterators)}, index{0ul} {}

        jsarray_iterator &next();

        const jsarray_iterator &next() const;

        bool has_next() const;

        std::string toString() const;

    };

    jsarray();

    jsarray(std::initializer_list<jsvariable>);

    jsarray(const jsarray &);

    jsarray(jsarray &&) noexcept;

    jsarray concat(const jsvariable &args) const;

    template<typename ... Args>
    inline jsarray concat(const jsvariable &value, Args ... args) const { return concat(value).concat(args...); }

    jsarray copyWithin(unsigned long, unsigned long, unsigned long) const;

    jsarray copyWithin(unsigned long, unsigned long) const;

    jsarray copyWithin(unsigned long) const;

    jsarray_iterators entries();

    unsigned long push(const jsvariable &);

    jsarray &operator=(const jsarray &);

    jsarray &operator=(jsarray &&) noexcept;

    const jsvariable &operator[](unsigned long) const noexcept(false);

    jsvariable &operator[](unsigned long) noexcept(false);

    std::string toString() const override;

    const unsigned long &length;

};

template<typename Func>
std::string jsfunction<Func>::toString() const {
    return std::string{"[Function "} + typeid(Func).name() + "]";
}

std::ostream &operator<<(std::ostream &, const jsarray::jsarray_iterators &);

#endif //C_SCRIPT_JSVALUE_H
