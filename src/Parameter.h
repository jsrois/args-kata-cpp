//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_PARAMETER_H
#define ARGS_KATA_PARAMETER_H

#include <string>
#include "GenericValue.h"

using std::string;



struct Parameter {
    Parameter(string name, string info, GenericValue value = GenericValue(false)) {
        this->name = name;
        this->value = value;
    }

    bool operator==(const Parameter& lhs) const {
        // No me gusta!
        return name == lhs.name &&
                value == lhs.value;
    }

    string name;
    GenericValue value;
};


#endif //ARGS_KATA_PARAMETER_H
