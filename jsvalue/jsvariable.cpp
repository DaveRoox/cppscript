//
// Created by Davide Russo on 2019-01-25.
//

#include "jsvariable.h"
#include "jsvalue.h"
#include <stdexcept>

const jsvariable jsvariable::undefined;

jsvariable::jsvariable() :
        value{nullptr}, _type{constructor_t::Undefined}, constructor{_type} {}

jsvariable::jsvariable(const jsvariable &other) :
        value{other.value}, constructor{other.constructor} {}

jsvariable::jsvariable(jsnumber _value) :
        value{std::make_shared<jsnumber>(std::move(_value))}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(long double _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(short _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(int _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(float _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(double _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(long _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(long long _value) :
        value{std::make_shared<jsnumber>(_value)}, _type{constructor_t::Number}, constructor{_type} {}

jsvariable::jsvariable(jsstring _value) :
        value{std::make_shared<jsstring>(std::move(_value))}, _type{constructor_t::String}, constructor{_type} {}

jsvariable::jsvariable(std::string _value) :
        value{std::make_shared<jsstring>(_value)}, _type{constructor_t::String}, constructor{_type} {}

jsvariable::jsvariable(const char *_value) :
        value{std::make_shared<jsstring>(_value)}, _type{constructor_t::String}, constructor{_type} {}

jsvariable::jsvariable(char _value) :
        value{std::make_shared<jsstring>(_value)}, _type{constructor_t::String}, constructor{_type} {}

jsvariable::jsvariable(jsboolean _value) :
        value{std::make_shared<jsboolean>(std::move(_value))}, _type{constructor_t::Boolean}, constructor{_type} {}

jsvariable::jsvariable(bool _value) :
        value{std::make_shared<jsboolean>(_value)}, _type{constructor_t::Boolean}, constructor{_type} {}

jsvariable::jsvariable(jsarray _values) :
        value{std::make_shared<jsarray>(std::move(_values))}, _type{constructor_t::Array}, constructor{_type} {}

jsvariable::jsvariable(std::initializer_list<jsvariable> _values) :
        value{std::make_shared<jsarray>(_values)}, _type{constructor_t::Array}, constructor{_type} {}

jsvariable::jsvariable(jsobject _value) :
        value{std::make_shared<jsobject>(std::move(_value))}, _type{constructor_t::Object}, constructor{_type} {}

jsvariable::jsvariable(std::initializer_list<std::pair<const std::string, jsvariable>> _values) :
        value{std::make_shared<jsobject>(_values)}, _type{constructor_t::Object}, constructor{_type} {}

std::string jsvariable::toString() const {
    return *this ? value->toString() : "undefined";
}

jsvariable &jsvariable::operator[](const std::string &property_name) noexcept(false) {
    if (auto d = dynamic_cast<jsobject *>(&*value))
        return d->operator[](property_name);
    throw std::runtime_error{"Unsupported operator [string] for non-jsobject type"};
}

const jsvariable &jsvariable::operator[](const std::string &property_name) const noexcept(false) {
    if (auto d = dynamic_cast<const jsobject *>(&*value))
        return d->operator[](property_name);
    throw std::runtime_error{"Unsupported operator [string] for non-jsobject type"};
}

jsuvariable jsvariable::operator[](unsigned long index) noexcept(false) {
    if (jsvalue *d = dynamic_cast<jsarray *>(&*value))
        return ((jsarray *) d)->operator[](index);
    else if (d = dynamic_cast<jsstring *>(&*value); d)
        return ((jsstring *) d)->operator[](index);
    throw std::runtime_error{"Unsupported operator [integer] for non-sequence type"};
}

const jsuvariable jsvariable::operator[](unsigned long index) const noexcept(false) {
    if (jsvalue *d = dynamic_cast<jsarray *>(&*value))
        return ((jsarray *) d)->operator[](index);
    else if (d = dynamic_cast<jsstring *>(&*value); d)
        return ((jsstring *) d)->operator[](index);
    throw std::runtime_error{"Unsupported operator [integer] for non-sequence type"};
}

jsvariable::operator bool() const {
    return this != &undefined and value != nullptr;
}

jsvariable::operator jsarray() const {
    return *dynamic_cast<jsarray *>(&*value);
}

jsvariable &jsvariable::operator=(const jsvariable &other) {
    value = other.value;
    _type = other._type;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const jsvariable &v) {
    return out << v.toString();
}

std::ostream &operator<<(std::ostream &out, const jsuvariable &v) {
    return out << v.str();
}

std::string jsuvariable::str() const {
    return std::move(v ? v->toString() : std::string{*c});
}

jsvariable &jsuvariable::operator=(jsvariable &&_v) {
    c = nullptr;
    return *v = std::move(_v);
}

jsvariable &jsuvariable::operator=(const jsvariable &_v) {
    c = nullptr;
    return *v = _v;
}

char &jsuvariable::operator=(char &&_c) {
    v = nullptr;
    return *c = _c;
}

char &jsuvariable::operator=(const char &_c) {
    v = nullptr;
    return *c = _c;
}

const jsvariable &jsuvariable::operator[](const std::string &property_name) const noexcept(false) {
    if (v)
        return v->operator[](property_name);
    throw std::runtime_error{"Unsupported operator [string] for non-jsobject type"};
}

jsvariable &jsuvariable::operator[](const std::string &property_name) noexcept(false) {
    if (v)
        return v->operator[](property_name);
    throw std::runtime_error{"Unsupported operator [string] for non-jsobject type"};
}

const jsuvariable jsuvariable::operator[](unsigned long index) const noexcept(false) {
    if (v)
        return v->operator[](index);
    throw std::runtime_error{"Unsupported operator [integer] for non-sequence type"};
}

jsuvariable jsuvariable::operator[](unsigned long index) noexcept(false) {
    if (v)
        return v->operator[](index);
    throw std::runtime_error{"Unsupported operator [integer] for non-sequence type"};
}

jsuvariable::operator bool() const {
    return v ? bool(*v) : bool(c);
}
