//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#include <sstream>
#include <iostream>
#include "Element.h"
#include "Printer.h"
#include "Root.h"

const std::string Printer::print(const Root &root) {
    std::ostringstream data;
    data << "<" << root.name << ">";
    for(auto const &f: root.elements){
        data << "<" << f.second.getKey();
        for(auto const &atr: f.second.getAttributes()){
            data << " " << atr.first << "=\"" << atr.second << "\"";
        }
        data << ">";
        data << f.second.getValue();
        data << "</" << f.second.getKey() << ">";
    }

    data << "</" << root.name << ">";
    return data.str();
}
