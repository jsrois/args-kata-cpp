//
// Created by Javi on 8/4/17.
//

#include <string>
#include "ArgParser.h"
#include "Splitter.h"
#include "OptionSet.h"

void ArgParser::parse(std::string arguments) {

}

void ArgParser::addSchema(Schema schema) {
    optionSet->initializeFrom(schema);
}

ArgParser::ArgParser() :
    ArgParser(new Splitter, new OptionSet)
{

}

ArgParser::ArgParser(Splitter *splitter, OptionSet *optionSet) :
    splitter(splitter), optionSet(optionSet)
{

}
