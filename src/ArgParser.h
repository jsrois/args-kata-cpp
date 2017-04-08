//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_ARGPARSER_H
#define ARGS_KATA_ARGPARSER_H


#include <vector>
#include "Parameter.h"

typedef std::vector<Parameter> Schema;

class ArgParser {
public:
    void addSchema(std::vector <Parameter> parameterSpecs);
    void parse(std::string arguments);

    template <typename ReturnType>
    ReturnType get(std::string name) {
        return ReturnType();
    }
};


#endif //ARGS_KATA_ARGPARSER_H
