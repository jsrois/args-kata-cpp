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
    auto param = std::find_if(begin(schema), end(schema),[&name](auto elem){
        return elem.name == name;
    });
    if (param == schema.end())
        return GenericValue();
    return param->value;
}
