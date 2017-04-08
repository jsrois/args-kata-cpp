//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_OPTIONSET_H
#define ARGS_KATA_OPTIONSET_H


#include "Parameter.h"
#include "Splitter.h"
#include "GenericValue.h"
#include <vector>
typedef std::vector<Parameter> Schema;

class OptionSet {
public:
    virtual ~OptionSet() = default;
    virtual void initializeFrom(Schema);
    virtual void updateParameters(ParameterValueMap);

    virtual GenericValue get(string name);

protected:
    Schema schema;
};


#endif //ARGS_KATA_OPTIONSET_H
