//
// Created by Дарья Колодзей on 17.10.15.
//

#ifndef EQUATIONS_OPERATION_H
#define EQUATIONS_OPERATION_H

#include <vector>
template <class Value>
class Operation {
  public:
    Operation() = delete;
    Operation(const Operation&) = delete;
    Operation& operator = (const Operation&) = delete;
    virtual size_t getArity() = 0;
    virtual Value getValue(const std::vector<Value>& args) = 0;
    virtual ~Operation() {}
};


#endif //EQUATIONS_OPERATION_H
