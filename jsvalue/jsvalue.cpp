//
// Created by Davide Russo on 2019-01-25.
//
#include "jsvalue.h"
#include "jsvariable.h"

std::string ctabs(unsigned short tabs) {
    std::stringstream ss;
    while (tabs > 0)
        ss << '\t', --tabs;
    return ss.str();
}

const std::string jsboolean::values[2]{"false", "true"};

std::string jsnumber::toString() const {
    return std::to_string(value);
}

jsstring &jsstring::operator=(jsstring &&other) noexcept {
    value = std::move(other.value);
    return *this;
}

std::string jsstring::toString() const {
    return "\"" + value + "\"";
}

const char &jsstring::operator[](unsigned long index) const noexcept(false) {
    return value.at(index);
}

char &jsstring::operator[](unsigned long index) noexcept(false) {
    return value[index];
}

std::string jsboolean::toString() const {
    return values[value];
}

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

jsarray::jsarray_iterator jsarray::jsarray_iterator::next() const {
    return {key + 1, _array.values.at(key + 1), _array};
}

std::string jsarray::jsarray_iterator::toString() const {
    return "[" + std::to_string(key) + ", " + value.toString() + "]";
}

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

std::ostream &operator<<(std::ostream &out, const jsarray::jsarray_iterators &iterators) {
    return out << iterators.toString();
}
