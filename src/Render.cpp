//
// Created by Borchers, Henry Samuel on 7/15/17.
//

#include <iostream>
#include "Render.h"

using namespace std;


void Renderer::set_source(const Root &root) {
    std::cout << "setting" << endl;
    this->source = make_shared<Root>(root);

}


void Renderer::set_output_format(OutputFormat format) {
    switch (format) {

        case OutputFormat::XML:
            render_strategy = std::make_unique<XMLStrategy>();
            break;
        case OutputFormat::JSON:
            render_strategy = std::make_unique<JSONStrategy>();
            break;
    }

}

std::string Renderer::render() {
    return this->render_strategy->render(source);
}

string JSONStrategy::render(shared_ptr<Root> source) {
    ostringstream oss;
    oss << "{\n";                                               // {
    for (auto const &f: source->getElements()) {
        oss << "    \"" << f.second.getKey() << "\": ";         //     "element": "data"
        oss << "\"" << f.second.getValue() << "\"\n";
    }
    oss << "}\n";                                               // }
    return oss.str();
}

std::string XMLStrategy::render(shared_ptr<Root> source) {
    ostringstream oss;
    oss << "<" << source->getName() << ">";         // <root>
    for (auto const &f: source->getElements()) {
        oss << "<" << f.second.getKey() << ">";     // <element>
        oss << f.second.getValue();                 // data
        oss << "</" << f.second.getKey() << ">";    // </element>
    }
    oss << "</" << source->getName() << ">";  // <root>
    return oss.str();

}