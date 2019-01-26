//
// Created by Davide Russo on 2019-01-25.
//
#include "jsvalue.h"
#include "jsvariable.h"

std::string ctabs(unsigned short tabs) {
    std::stringstream ss;
    while(tabs > 0)
        ss << '\t', --tabs;
    return ss.str();
}

std::string jsboolean::values[2]{"false", "true"};

std::string jsnumber::str() const {
    return std::to_string(value);
}

std::string jsnumber::pretty_printed(unsigned short tabs) const {
    return str();
}

jsstring &jsstring::operator=(jsstring &&other) noexcept {
    value = std::move(other.value);
    return *this;
}

std::string jsstring::str() const {
    return "\"" + value + "\"";
}

std::string jsstring::pretty_printed(unsigned short tabs) const {
    return str();
}

std::string jsboolean::str() const {
    return values[value];
}

std::string jsboolean::pretty_printed(unsigned short tabs) const {
    return str();
}

std::string jsarray::str() const {
    std::stringstream ss;
    ss << "[";
    if (!values.empty()) {
        for (const auto &value : values)
            ss << value.str() << ",";
        ss.seekp(-1, std::ios_base::end);
    }
    ss << "]";
    return ss.str();
}

std::string jsarray::pretty_printed(unsigned short tabs) const {
    const std::string stabs{std::move(ctabs(tabs))};
    const std::string pstabs{std::move(ctabs(tabs + 1))};
    std::stringstream ss;
    ss << "[\n";
    if (!values.empty()) {
        for (const auto &value : values)
            ss << pstabs << value.pretty_printed(tabs + 2) << ",\n";
        //ss.seekp(-1, std::ios_base::end);
    }
    ss << stabs << "]";
    return ss.str();
}

jsarray::jsarray(std::initializer_list<jsvariable> _values) :
        values{_values} {}

jsarray::jsarray(const jsarray &other) :
        values{other.values} {}

jsarray::jsarray(jsarray &&other) noexcept :
        values{std::move(other.values)} {}

jsarray &jsarray::operator=(const jsarray &other) {
    values = other.values;
    return *this;
}

jsarray &jsarray::operator=(jsarray &&other) noexcept {
    values = std::move(other.values);
    return *this;
}

jsvariable &jsarray::operator[](unsigned long index) noexcept(false) {
    return values[index];
}

const jsvariable &jsarray::operator[](unsigned long index) const noexcept(false) {
    return values.at(index);
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

std::string jsobject::str() const {
    std::stringstream ss;
    ss << "{";
    if (!values.empty()) {
        for (const auto &[key, value] : values)
            if (value)
                ss << "\"" << key << "\"" << ":" << value.str() << ",";
        ss.seekp(-1, std::ios_base::end);
    }
    ss << "}";
    return ss.str();
}

std::string jsobject::pretty_printed(unsigned short tabs) const {
    const std::string stabs{std::move(ctabs(tabs))};
    const std::string pstabs{std::move(ctabs(tabs + 1))};
    std::stringstream ss;
    ss << "{\n";
    if (!values.empty()) {
        for (const auto &[key, value] : values)
            if (value)
                ss << pstabs << "\"" << key << "\"" << ": " << value.pretty_printed(tabs + 2) << ",\n";
        //ss.seekp(-1, std::ios_base::end);
    }
    ss << stabs << "}";
    return ss.str();
}

const jsvariable &jsobject::operator[](const std::string &property_name) const {
    return values.find(property_name) != values.end() ? values.at(property_name) : jsvariable::undefined;
}

jsvariable &jsobject::operator[](const std::string &property_name) {
    return values[property_name];
}
