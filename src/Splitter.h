//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_SPLITTER_H
#define ARGS_KATA_SPLITTER_H


#include <string>
#include <map>

using std::string;

class ParameterValue {
public:
    ParameterValue(bool b, float f, int i) : b(b), f(f), i(i) {}
    ParameterValue(bool b) : ParameterValue(b,0,0) {}
    ParameterValue(float f) : ParameterValue(0,f,0) {}
    ParameterValue(int i) : ParameterValue(0,0,i){}
    bool b;
    float f;
    int i;
};

typedef std::map<string,ParameterValue> ParameterValueMap;

class Splitter {
public:
    virtual ~Splitter() = default;
    virtual ParameterValueMap getParameterValuesFrom(string args){
        return ParameterValueMap();
    }
};


#endif //ARGS_KATA_SPLITTER_H
