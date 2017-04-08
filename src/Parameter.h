//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_PARAMETER_H
#define ARGS_KATA_PARAMETER_H

#include <string>

using std::string;



struct Parameter {
    Parameter(string a, string b, bool c, int d, float e)
            : a(a), b(b),c(c),d(d),e(e) {}
    Parameter(string a , string b) : Parameter(a,b,true,0,0){}
    Parameter(string a, string b, int i) : Parameter(a,b,false,i,0){}
    Parameter(string a, string b, float f) : Parameter(a,b,false,0,f) {}

    string a, b;
    bool c;
    int d;
    float e;
    bool operator==(const Parameter& lhs) const {
        // No me gusta!
        return a == lhs.a && b == lhs.b && c == lhs.c && d == lhs.d && e== lhs.e;
    }

};


#endif //ARGS_KATA_PARAMETER_H
