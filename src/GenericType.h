//
// Created by Javi on 9/4/17.
//

#ifndef ARGS_KATA_GENERICTYPE_H
#define ARGS_KATA_GENERICTYPE_H


class GenericType {
public:
    template <typename ReturnType>
    bool operator==(const ReturnType& lhs) {
        return false;
    }
};


#endif //ARGS_KATA_GENERICTYPE_H
