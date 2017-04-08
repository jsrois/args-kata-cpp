//
// Created by Javi on 8/4/17.
//

#ifndef ARGS_KATA_GENERICVALUE_H
#define ARGS_KATA_GENERICVALUE_H


#include <memory>

struct GenericValue {

    GenericValue() : GenericValue(false) {}

    template<typename ValueType>
    GenericValue(ValueType v) :  value(new Value_<ValueType>(v))
    {
    }

    struct Value {
        virtual ~Value() = default;
    };

    template <typename T>
    bool operator==(const T& t) const {
        auto * ptr = dynamic_cast<Value_<T>*>(value.get());
        return ptr && ptr->value == t;
    }

    template <class ValueType>
    struct Value_ : public Value {
        Value_(ValueType value) {
            this->value = value;
        }

        ValueType value;
    };

    std::shared_ptr<Value> value;

};


#endif //ARGS_KATA_GENERICVALUE_H
