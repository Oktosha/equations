//
// Created by Дарья Колодзей on 17.10.15.
//

#ifndef EQUATIONS_CALCULATERPN_H
#define EQUATIONS_CALCULATERPN_H

#include "Operation.h"

template<class Value>
Value calculateRPN(const std::vector<Operation<Value>>& operations) {
    std::vector<Value> stack;
    for (auto it = operations.cbegin(); it != operations.cend(); ++it) {
        std::vector<Value> args;
        for (int i = 0; i < it->getArity(); ++i) {
            args.push_back(stack.back());
            stack.pop_back();
        }
        stack.push_back(it->getValue(args));
    }
    return stack.back();
}
#endif //EQUATIONS_CALCULATERPN_H
