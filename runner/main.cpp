//
// Created by Borchers, Henry Samuel on 6/24/17.
//

#include <iostream>
#include <fstream>
#include "DublinCore.h"

using namespace std;

int main() {
    Printer p;
    Root root;
    Element element_contributor;
    ofstream file;

    element_contributor.setKey("title");
    element_contributor.setValue("Henry");
    element_contributor.setAttribute("Sex", "Male");
    root.setElement(element_contributor);
    root.setName("Person");

    root.setElement("date", "January 19, 1985");
    const std::string xml = p.print(root);
    file.open("sample.xml");
    file << xml;
    file.close();
    cout << xml << endl;






}