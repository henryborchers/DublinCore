//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#ifndef DUBLINCORE_ROOT_H
#define DUBLINCORE_ROOT_H

#include <string>
#include <map>

class Printer;
class Element;
class Root {
    std::string name; //!< Name of the root element
    std::map<std::string, Element> elements;
    friend class Printer;
public:
    Root();

    const std::string &getName() const;

    void setName(const std::string &name);

    void setElement(Element element);
    void setElement(const std::string &key, const std::string &value);

    const Element getElement(const std::string &key);
};


#endif //DUBLINCORE_ROOT_H
