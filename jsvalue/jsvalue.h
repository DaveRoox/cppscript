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

    virtual bool operator==(const jsvalue &) const = 0;

    inline virtual bool operator!=(const jsvalue &other) const { return !(*this == other); }

    virtual ~jsvalue() = default;

};

class jsnumber : public jsvalue { // <, <=, ==, !=, >=, >
    // <, == allora:
    //      <= è dato da < OR ==
    //      > è dato dal not(<=)
    //      != è dato dal not(==)
    //      >= è dato dal > OR ==

private:
    long double value;

public:
    jsnumber(long double);

    jsnumber(float);

    jsnumber(double);

    jsnumber(unsigned short);

    jsnumber(unsigned int);

    jsnumber(unsigned long int);

    jsnumber(unsigned long long int);

    jsnumber(signed short);

    jsnumber(signed int);

    jsnumber(signed long int);

    jsnumber(signed long long int);

    bool operator==(const jsvalue &) const override;

    bool operator<(long double) const;

    bool operator==(long double) const;

    bool operator<=(long double) const;

    bool operator>(long double) const;

    bool operator!=(long double) const;

    bool operator>=(long double) const;

    bool operator<(float) const;

    bool operator==(float) const;

    bool operator<=(float) const;

    bool operator>(float) const;

    bool operator!=(float) const;

    bool operator>=(float) const;

    bool operator<(double) const;

    bool operator==(double) const;

    bool operator<=(double) const;

    bool operator>(double) const;

    bool operator!=(double) const;

    bool operator>=(double) const;

    bool operator<(unsigned short) const;

    bool operator==(unsigned short) const;

    bool operator<=(unsigned short) const;

    bool operator>(unsigned short) const;

    bool operator!=(unsigned short) const;

    bool operator>=(unsigned short) const;

    bool operator<(unsigned int) const;

    bool operator==(unsigned int) const;

    bool operator<=(unsigned int) const;

    bool operator>(unsigned int) const;

    bool operator!=(unsigned int) const;

    bool operator>=(unsigned int) const;

    bool operator<(unsigned long int) const;

    bool operator==(unsigned long int) const;

    bool operator<=(unsigned long int) const;

    bool operator>(unsigned long int) const;

    bool operator!=(unsigned long int) const;

    bool operator>=(unsigned long int) const;

    bool operator<(unsigned long long int) const;

    bool operator==(unsigned long long int) const;

    bool operator<=(unsigned long long int) const;

    bool operator>(unsigned long long int) const;

    bool operator!=(unsigned long long int) const;

    bool operator>=(unsigned long long int) const;

    bool operator<(signed short) const;

    bool operator==(signed short) const;

    bool operator<=(signed short) const;

    bool operator>(signed short) const;

    bool operator!=(signed short) const;

    bool operator>=(signed short) const;

    bool operator<(signed int) const;

    bool operator==(signed int) const;

    bool operator<=(signed int) const;

    bool operator>(signed int) const;

    bool operator!=(signed int) const;

    bool operator>=(signed int) const;

    bool operator<(signed long int) const;

    bool operator==(signed long int) const;

    bool operator<=(signed long int) const;

    bool operator>(signed long int) const;

    bool operator!=(signed long int) const;

    bool operator>=(signed long int) const;

    bool operator<(signed long long int) const;

    bool operator==(signed long long int) const;

    bool operator<=(signed long long int) const;

    bool operator>(signed long long int) const;

    bool operator!=(signed long long int) const;

    bool operator>=(signed long long int) const;

    std::string toString() const override;

};

class jsstring : public jsvalue {

private:
    std::string value;

public:
    jsstring(std::string);

    jsstring(const char *);

    jsstring(signed char);

    jsstring(const std::unique_ptr<char *> &);

    jsstring(jsstring &&) noexcept;

    jsstring &operator=(jsstring &&) noexcept;

    const char &operator[](unsigned long int) const noexcept(false);

    char &operator[](unsigned long int) noexcept(false);

    bool operator==(const jsvalue &) const override;

    std::string toString() const override;

};

class jsboolean : public jsvalue {

private:
    static const std::string values[2];
    bool value;

public:
    jsboolean(bool);

    bool operator==(const jsvalue &) const override;

    explicit operator bool() const;

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

    bool operator==(const jsvalue &) const override;

    std::string toString() const override;

};

template<typename Func>
class jsfunction : public jsvalue {
private:
    std::function<Func> value;
public:

    jsfunction() = default;

    jsfunction(std::function<Func> f) : value{std::move(f)} {}

    template<typename ... Args>
    inline auto operator()(Args ... args) { return value(args...); }

    bool operator==(const jsvalue &) const override;

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

        jsarray_iterator(unsigned long _key, jsvariable &, jsarray &);

        jsarray_iterator &operator=(const jsarray_iterator &) = delete;

        jsarray_iterator next() const;

    };

    struct jsarray_iterators {
    private:
        std::vector<jsarray_iterator> iterators;
        mutable unsigned long index;
    public:
        jsarray_iterators(std::vector<jsarray_iterator> &&);

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

    jsarray copyWithin(unsigned long, unsigned long, unsigned long int) const;

    jsarray copyWithin(unsigned long, unsigned long int) const;

    jsarray copyWithin(unsigned long int) const;

    jsarray_iterators entries();

    bool every(jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)>,
               const jsvariable & = jsvariable::undefined) const;

    bool every(jsfunction<bool(const jsvariable &, unsigned long int)>) const;

    bool every(jsfunction<bool(const jsvariable &)>) const;

    jsarray fill(const jsvariable &, unsigned long int, unsigned long int) const;

    jsarray fill(const jsvariable &, unsigned long int) const;

    jsarray fill(const jsvariable &) const;

    jsarray filter(jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)>,
                   const jsvariable & = jsvariable::undefined) const;

    jsarray filter(jsfunction<bool(const jsvariable &, unsigned long int)>) const;

    jsarray filter(jsfunction<bool(const jsvariable &)>) const;

    const jsvariable &find(jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)>,
                           const jsvariable & = jsvariable::undefined) const;

    const jsvariable &find(jsfunction<bool(const jsvariable &, unsigned long int)>) const;

    const jsvariable &find(jsfunction<bool(const jsvariable &)>) const;

    signed long int findIndex(jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)>,
                              const jsvariable & = jsvariable::undefined) const;

    signed long int findIndex(jsfunction<bool(const jsvariable &, unsigned long int)>) const;

    signed long int findIndex(jsfunction<bool(const jsvariable &)>) const;

    template<typename T>
    const jsvariable &forEach(jsfunction<T(const jsvariable &, unsigned long, const jsarray &)> f,
                              const jsvariable &_this) const {
        for (unsigned long int i = 0; i < values.size(); ++i)
            if (const auto &value = values.at(i); value)
                f(value, i, _this ? (jsarray) _this : *this);
        return jsvariable::undefined;
    }

    template<typename T = void>
    const jsvariable &forEach(jsfunction<T(const jsvariable &, unsigned long int)> f) const {
        for (unsigned long int i = 0; i < values.size(); ++i)
            if (const auto &value = values.at(i); value)
                f(value, i);
        return jsvariable::undefined;
    }

    template<typename T = void>
    const jsvariable &forEach(jsfunction<T(const jsvariable &)> f) const {
        for (const auto &value : values)
            if (value)
                f(value);
        return jsvariable::undefined;
    }

    unsigned long push(const jsvariable &);

    jsarray &operator=(const jsarray &);

    jsarray &operator=(jsarray &&) noexcept;

    const jsvariable &operator[](unsigned long int) const noexcept(false);

    jsvariable &operator[](unsigned long int) noexcept(false);

    bool operator==(const jsvalue &) const override;

    std::string toString() const override;

    const unsigned long int &length;

};

template<typename Func>
std::string jsfunction<Func>::toString() const {
    return std::string{"[Function "} + typeid(Func).name() + "]";
}

template<typename Func>
bool jsfunction<Func>::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsfunction *>(&other))
        return value.target_type() == d->value.target_type(); // TODO: Verificarne la correttezza
    return false;
}

std::ostream &operator<<(std::ostream &, const jsarray::jsarray_iterators &);

#endif //C_SCRIPT_JSVALUE_H
