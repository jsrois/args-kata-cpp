//
// Created by Javi on 9/4/17.
//

#ifndef ARGS_KATA_ARGPARSER_H
#define ARGS_KATA_ARGPARSER_H


#include <string>
#include "Schema.h"
#include "GenericType.h"

class ArgParser {

public:
    void setSchema(Schema schema);
    void parse(int i, const char **pString);
    GenericType get(std::string name);
};


#endif //ARGS_KATA_ARGPARSER_H
