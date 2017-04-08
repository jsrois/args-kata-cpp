//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_ARGPARSER_H
#define ARGS_KATA_ARGPARSER_H


#include <vector>
#include "Splitter.h"
#include "OptionSet.h"
#include "GenericValue.h"

class ArgParser {
public:
    ArgParser();
    ArgParser(Splitter *splitter, OptionSet *optionSet);

    void addSchema(Schema parameterSpecs);
    void parse(std::string arguments);

    GenericValue get(std::string name) {
        return optionSet->get(name);
    }

protected:
    std::unique_ptr<Splitter> splitter;
    std::unique_ptr<OptionSet> optionSet;

};


#endif //ARGS_KATA_ARGPARSER_H
