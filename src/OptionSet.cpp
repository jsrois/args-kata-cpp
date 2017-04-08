//
// Created by Javi on 8/4/17.
//

#include "OptionSet.h"

void OptionSet::initializeFrom(Schema schema) {
    this->schema = schema;
}

void OptionSet::updateParameters(ParameterValueMap parameters) {
}

GenericValue OptionSet::get(string name) {
    return GenericValue();
}
