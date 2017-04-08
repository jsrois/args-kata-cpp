//
// Created by Javi on 8/4/17.
//

#include <string>
#include "ArgParser.h"

void ArgParser::parse(std::string arguments) {
    auto parameterValues = splitter->getParameterValuesFrom(arguments);
    optionSet->updateParameters(parameterValues);
}

void ArgParser::addSchema(Schema schema) {
    optionSet->initializeFrom(schema);
}

ArgParser::ArgParser() :
    ArgParser(new Splitter, new OptionSet) {}

ArgParser::ArgParser(Splitter *splitter, OptionSet *optionSet) :
    splitter(splitter), optionSet(optionSet) {}

GenericValue ArgParser::get(std::string name) {
    return optionSet->get(name);
}
