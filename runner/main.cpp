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
    Element ElContributor;
    ofstream file;

    ElContributor.setKey("contributor");
    ElContributor.setValue("Henry");
    ElContributor.setAttribute("Sex", "Male");
    root.setElement(ElContributor);
    root.setName("asas");

    root.setElement("date", "January 19, 1985");
    const std::string xml = p.print(root);
    file.open("sample.xml");
    file << xml;
    file.close();
    cout << xml << endl;






}