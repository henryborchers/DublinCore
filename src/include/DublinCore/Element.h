//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#ifndef DUBLINCORE_ELEMENT_H
#define DUBLINCORE_ELEMENT_H


#include <string>
#include <map>

class Element {
    std::string key;
    std::string value;
    std::map<std::string, std::string> attributes;
public:
    const std::string &getKey() const;

    void setKey(const std::string &key);

    const std::string &getValue() const;

    void setValue(const std::string &value);

    void setAttribute(const std::string &key, const std::string &value);

    const std::map<std::string, std::string> &getAttributes() const;
};


#endif //DUBLINCORE_ELEMENT_H
