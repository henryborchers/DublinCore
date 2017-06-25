//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#include "Element.h"
#include "Root.h"

const std::string &Root::getName() const {
    return name;
}

void Root::setName(const std::string &name) {
    Root::name = name;
}

void Root::setElement(Element element) {
    elements[element.getKey()] = std::move(element);
}

void Root::setElement(const std::string &key, const std::string &value) {
    Element element;
    element.setKey(key);
    element.setValue(value);
    elements[key] = element;
}

Root::Root(): name("root") {
}

const Element Root::getElement(const std::string &key) {
    return elements[key];
}