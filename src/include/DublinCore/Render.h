//
// Created by Borchers, Henry Samuel on 7/15/17.
//

#ifndef DUBLINCORE_RENDER_H
#define DUBLINCORE_RENDER_H

#include <sstream>
#include "Root.h"

enum class OutputFormat {
    XML,
    JSON
};


class RenderStrategy{
public:
    virtual std::string render(std::shared_ptr<Root> source) = 0;
};

class XMLStrategy : public RenderStrategy{
public:
    std::string render(std::shared_ptr<Root> source) override;
};

class JSONStrategy : public RenderStrategy{
public:
    std::string render(std::shared_ptr<Root> source) override;
};

class Renderer {
    std::ostringstream oss;
    std::shared_ptr<Root> source;
    std::unique_ptr<RenderStrategy> render_strategy;
public:
    void set_source(const Root &root);
    void set_output_format(OutputFormat format);

    std::string render();
};

#endif //DUBLINCORE_RENDER_H
