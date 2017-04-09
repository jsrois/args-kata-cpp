//
// Created by Javi on 9/4/17.
//

#ifndef ARGS_KATA_SCHEMA_H
#define ARGS_KATA_SCHEMA_H

#include <string>
#include <vector>

using std::vector;
using std::string;

struct Parameter {
    Parameter(string, string){}
    template <typename PassedType>
    Parameter(string, string, PassedType) {

    }
};

typedef vector<Parameter> Schema;

#endif //ARGS_KATA_SCHEMA_H
