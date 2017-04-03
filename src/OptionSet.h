//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_OPTIONSSET_H
#define ARGS_KATA_OPTIONSSET_H

#include <map>
#include "Schema.h"
class OptionSet {
public:
    virtual void add(Option);
    virtual void setFlag(std::string name);
    virtual void setParameter(std::string name, std::string value);
    virtual bool getFlag(std::string name) const;
    virtual std::string getParameter(std::string name) const;

protected:
    std::map<std::string,Option> options;
};

#endif //ARGS_KATA_OPTIONSSET_H
