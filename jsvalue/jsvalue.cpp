//
// Created by Davide Russo on 2019-01-25.
//
#include "jsvalue.h"
#include "jsvariable.h"

// TODO: Troppe copie, verificare costruttori/assegnazioni/passaggio parametri

std::string ctabs(unsigned short tabs) {
    std::stringstream ss;
    while (tabs > 0)
        ss << '\t', --tabs;
    return ss.str();
}

const std::string jsboolean::values[2]{"false", "true"};

jsnumber::jsnumber(long double _value) :
        value{_value} {}

jsnumber::jsnumber(float _value) :
        value(_value) {}

jsnumber::jsnumber(double _value) :
        value(_value) {}

jsnumber::jsnumber(unsigned short _value) :
        value(_value) {}

jsnumber::jsnumber(unsigned int _value) :
        value(_value) {}

jsnumber::jsnumber(unsigned long int _value) :
        value(_value) {}

jsnumber::jsnumber(unsigned long long int _value) :
        value(_value) {}

jsnumber::jsnumber(signed short _value) :
        value(_value) {}

jsnumber::jsnumber(signed int _value) :
        value(_value) {}

jsnumber::jsnumber(signed long int _value) :
        value(_value) {}

jsnumber::jsnumber(signed long long int _value) :
        value(_value) {}

std::string jsnumber::toString() const {
    return std::to_string(value);
}

bool jsnumber::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsnumber *>(&other))
        return value == d->value;
    return false;
}

bool jsnumber::operator<(long double _value) const {
    return value < _value;
}

bool jsnumber::operator==(long double _value) const {
    return value == _value;
}

bool jsnumber::operator<=(long double _value) const {
    return value <= _value;
}

bool jsnumber::operator>(long double _value) const {
    return value > _value;
}

bool jsnumber::operator!=(long double _value) const {
    return value != _value;
}

bool jsnumber::operator>=(long double _value) const {
    return value >= _value;
}

bool jsnumber::operator<(float _value) const {
    return value < _value;
}

bool jsnumber::operator==(float _value) const {
    return value == _value;
}

bool jsnumber::operator<=(float _value) const {
    return value <= _value;
}

bool jsnumber::operator>(float _value) const {
    return value > _value;
}

bool jsnumber::operator!=(float _value) const {
    return value != _value;
}

bool jsnumber::operator>=(float _value) const {
    return value >= _value;
}

bool jsnumber::operator<(double _value) const {
    return value < _value;
}

bool jsnumber::operator==(double _value) const {
    return value == _value;
}

bool jsnumber::operator<=(double _value) const {
    return value <= _value;
}

bool jsnumber::operator>(double _value) const {
    return value > _value;
}

bool jsnumber::operator!=(double _value) const {
    return value != _value;
}

bool jsnumber::operator>=(double _value) const {
    return value >= _value;
}

bool jsnumber::operator<(unsigned short _value) const {
    return value < _value;
}

bool jsnumber::operator==(unsigned short _value) const {
    return value == _value;
}

bool jsnumber::operator<=(unsigned short _value) const {
    return value <= _value;
}

bool jsnumber::operator>(unsigned short _value) const {
    return value > _value;
}

bool jsnumber::operator!=(unsigned short _value) const {
    return value != _value;
}

bool jsnumber::operator>=(unsigned short _value) const {
    return value >= _value;
}

bool jsnumber::operator<(unsigned int _value) const {
    return value < _value;
}

bool jsnumber::operator==(unsigned int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(unsigned int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(unsigned int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(unsigned int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(unsigned int _value) const {
    return value >= _value;
}

bool jsnumber::operator<(unsigned long int _value) const {
    return value < _value;
}

bool jsnumber::operator==(unsigned long int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(unsigned long int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(unsigned long int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(unsigned long int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(unsigned long int _value) const {
    return value >= _value;
}

bool jsnumber::operator<(unsigned long long int _value) const {
    return value < _value;
}

bool jsnumber::operator==(unsigned long long int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(unsigned long long int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(unsigned long long int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(unsigned long long int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(unsigned long long int _value) const {
    return value >= _value;
}

bool jsnumber::operator<(signed short _value) const {
    return value < _value;
}

bool jsnumber::operator==(signed short _value) const {
    return value == _value;
}

bool jsnumber::operator<=(signed short _value) const {
    return value <= _value;
}

bool jsnumber::operator>(signed short _value) const {
    return value > _value;
}

bool jsnumber::operator!=(signed short _value) const {
    return value != _value;
}

bool jsnumber::operator>=(signed short _value) const {
    return value >= _value;
}

bool jsnumber::operator<(signed int _value) const {
    return value < _value;
}

bool jsnumber::operator==(signed int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(signed int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(signed int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(signed int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(signed int _value) const {
    return value >= _value;
}

bool jsnumber::operator<(signed long int _value) const {
    return value < _value;
}

bool jsnumber::operator==(signed long int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(signed long int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(signed long int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(signed long int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(signed long int _value) const {
    return value >= _value;
}

bool jsnumber::operator<(signed long long int _value) const {
    return value < _value;
}

bool jsnumber::operator==(signed long long int _value) const {
    return value == _value;
}

bool jsnumber::operator<=(signed long long int _value) const {
    return value <= _value;
}

bool jsnumber::operator>(signed long long int _value) const {
    return value > _value;
}

bool jsnumber::operator!=(signed long long int _value) const {
    return value != _value;
}

bool jsnumber::operator>=(signed long long int _value) const {
    return value >= _value;
}

jsstring &jsstring::operator=(jsstring &&other) noexcept {
    value = std::move(other.value);
    return *this;
}

std::string jsstring::toString() const {
    return "\"" + value + "\"";
}

const char &jsstring::operator[](unsigned long int index) const noexcept(false) {
    return value.at(index);
}

char &jsstring::operator[](unsigned long index) noexcept(false) {
    return value[index];
}

bool jsstring::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsstring *>(&other))
        return value == d->value;
    return false;
}

jsstring::jsstring(std::string _value) :
        value{std::move(_value)} {}

jsstring::jsstring(const char *_value) :
        value{_value} {}

jsstring::jsstring(signed char _value) :
        value{_value} {}

jsstring::jsstring(const std::unique_ptr<char *> &_value) :
        value{} { value.push_back(**_value); }

jsstring::jsstring(jsstring &&other) noexcept :
        value{std::move(other.value)} {}

std::string jsboolean::toString() const {
    return values[value];
}

bool jsboolean::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsboolean *>(&other))
        return value == d->value;
    return false;
}

jsboolean::operator bool() const {
    return value;
}

jsboolean::jsboolean(bool _value) :
        value{_value} {}

jsarray::jsarray() :
        values{}, _size{values.size()}, length{_size} {}

jsarray::jsarray(std::initializer_list<jsvariable> _values) :
        values{_values}, _size{values.size()}, length{_size} {}

jsarray::jsarray(const jsarray &other) :
        values{other.values}, _size{values.size()}, length{_size} {}

jsarray::jsarray(jsarray &&other) noexcept :
        values{std::move(other.values)}, _size{values.size()}, length{_size} {}

jsarray &jsarray::operator=(const jsarray &other) {
    values = other.values;
    _size = values.size();
    return *this;
}

jsarray &jsarray::operator=(jsarray &&other) noexcept {
    values = std::move(other.values);
    _size = values.size();
    return *this;
}

jsvariable &jsarray::operator[](unsigned long index) noexcept(false) {
    return values[index];
}

const jsvariable &jsarray::operator[](unsigned long index) const noexcept(false) {
    return values.at(index);
}

std::string jsarray::toString() const {
    std::stringstream ss;
    ss << "[";
    if (!values.empty()) {
        for (const auto &value : values)
            ss << value.toString() << ",";
        ss.seekp(-1, std::ios_base::end);
    }
    ss << "]";
    return ss.str();
}

jsarray jsarray::concat(const jsvariable &value) const {
    jsarray result{*this};
    if (value.constructor == constructor_t::Array) {
        const jsarray &a = (jsarray) value;
        for (unsigned long int i = 0; i < a.length; ++i)
            result.push(a[i]);
    } else
        result.push(value);
    return std::move(result);
}

unsigned long jsarray::push(const jsvariable &value) {
    values.push_back(value);
    return _size = values.size();
}

jsarray jsarray::copyWithin(unsigned long target, unsigned long start, unsigned long end) const {
    if (end > _size)
        end = _size;
    jsarray result{*this};
    unsigned long &limit = target >= start ? target : start;
    while (limit < end)
        result[target++] = values[start++];
    return std::move(result);
}

jsarray jsarray::copyWithin(unsigned long target, unsigned long start) const {
    return std::move(copyWithin(target, start, _size));
}

jsarray jsarray::copyWithin(unsigned long target) const {
    return std::move(copyWithin(target, 0, _size));
}

jsarray::jsarray_iterators jsarray::entries() {
    std::vector<jsarray_iterator> iterators;
    unsigned long key = 0;
    while (key < _size)
        iterators.emplace_back(key, values.at(key), *this), ++key;
    return std::move(iterators);
}

bool jsarray::every(jsfunction<bool(const jsvariable &)> f) const {
    for (const auto &value : values)
        if (!f(value))
            return false;
    return true;
}

bool jsarray::every(jsfunction<bool(const jsvariable &, unsigned long int)> f) const {
    for (unsigned long i = 0; i < values.size(); ++i)
        if (!f(values.at(i), i))
            return false;
    return true;
}

bool
jsarray::every(jsfunction<bool(const jsvariable &, unsigned long, const jsarray &)> f, const jsvariable &_this) const {
    for (unsigned long i = 0; i < values.size(); ++i)
        if (!f(values.at(i), i, _this ? (jsarray) _this : *this))
            return false;
    return true;
}

bool jsarray::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsarray *>(&other)) {
        const auto &other_values = d->values;
        if (values.size() != other_values.size())
            return false;
        for (unsigned long i = 0; i < values.size(); ++i)
            if (!(values.at(i) == other_values.at(i)))
                return false;
        return true;
    }
    return false;
}

jsarray jsarray::fill(const jsvariable &new_value, unsigned long int start, unsigned long int end) const {
    if (end > _size)
        end = _size;
    jsarray result{*this};
    for (unsigned long int i = start; i < end; ++i)
        result[i] = new_value;
    return std::move(result);
}

jsarray jsarray::fill(const jsvariable &new_value, unsigned long int start) const {
    return std::move(fill(new_value, start, values.size()));
}

jsarray jsarray::fill(const jsvariable &new_value) const {
    return std::move(fill(new_value, 0, values.size()));
}

jsobject::jsobject(std::initializer_list<std::pair<const std::string, jsvariable>> _values) :
        values{_values} {}

jsobject::jsobject(const jsobject &other) :
        values{other.values} {}

jsobject::jsobject(jsobject &&other) noexcept :
        values{std::move(other.values)} {}

jsobject &jsobject::operator=(const jsobject &other) {
    values = other.values;
    return *this;
}

jsobject &jsobject::operator=(jsobject &&other) noexcept {
    values = std::move(other.values);
    return *this;
}

std::string jsobject::toString() const {
    std::stringstream ss;
    ss << "{";
    if (!values.empty()) {
        for (const auto &[key, value] : values)
            if (value) // TODO: fare ss.seekp solo se c'è stato almeno un inserimento!
                ss << "\"" << key << "\"" << ":" << value.toString() << ",";
        ss.seekp(-1, std::ios_base::end);
    }
    ss << "}";
    return ss.str();
}

const jsvariable &jsobject::operator[](const std::string &property_name) const {
    return values.find(property_name) != values.end() ? values.at(property_name) : jsvariable::undefined;
}

jsvariable &jsobject::operator[](const std::string &property_name) {
    return values[property_name];
}

bool jsobject::operator==(const jsvalue &other) const {
    if (auto d = dynamic_cast<const jsobject *>(&other)) {
        const auto &other_values = d->values;
        for (const auto &[key, value] : values)
            if (other_values.find(key) == other_values.end() or !(other_values.at(key) == value))
                return false;
        for (const auto &[key, value] : other_values)
            if (values.find(key) == values.end() or !(values.at(key) == value))
                return false;
        return true;
    }
    return false;
}

jsarray::jsarray_iterator jsarray::jsarray_iterator::next() const {
    return {key + 1, _array.values.at(key + 1), _array};
}

std::string jsarray::jsarray_iterator::toString() const {
    return "[" + std::to_string(key) + ", " + value.toString() + "]";
}

jsarray::jsarray_iterator::jsarray_iterator(unsigned long _key, jsvariable &_value, jsarray &__array) :
        value{_value}, _array{__array}, key{_key} {}

jsarray::jsarray_iterator &jsarray::jsarray_iterators::next() noexcept(false) {
    if (index < iterators.size())
        return iterators.at(++index);
    throw std::runtime_error{"Array iterator out of range"};
}

const jsarray::jsarray_iterator &jsarray::jsarray_iterators::next() const {
    if (index < iterators.size())
        return iterators.at(++index);
    throw std::runtime_error{"Array iterator out of range"};
}

bool jsarray::jsarray_iterators::has_next() const {
    return index < iterators.size();
}

std::string jsarray::jsarray_iterators::toString() const {
    std::stringstream ss;
    ss << "[";
    if (!iterators.empty()) {
        for (const auto &iterator : iterators)
            ss << iterator.toString() << ",";
        ss.seekp(-1, std::ios_base::end);
    }
    ss << "]";
    return std::move(ss.str());
}

jsarray::jsarray_iterators::jsarray_iterators(std::vector<jsarray::jsarray_iterator> &&_iterators) :
        iterators{std::move(_iterators)}, index{0ul} {}

std::ostream &operator<<(std::ostream &out, const jsarray::jsarray_iterators &iterators) {
    return out << iterators.toString();
}
