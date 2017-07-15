#include "Element.h"

const std::string &Element::getKey() const {
    return key;
}

void Element::setKey(const std::string &key) {
    Element::key = key;
}

const std::string &Element::getValue() const {
    return value;
}

void Element::setValue(const std::string &value) {
    Element::value = value;
}

void Element::setAttribute(const std::string &key, const std::string &value) {
    attributes[key] = value;

}

const std::map<std::string, std::string> &Element::getAttributes() const {
    return attributes;
}
