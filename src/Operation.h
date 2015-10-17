//
// Created by Дарья Колодзей on 17.10.15.
//

#ifndef EQUATIONS_OPERATION_H
#define EQUATIONS_OPERATION_H

#include <vector>
#include <functional>

template <class Value>
class Operation {
  public:
    Operation() = delete;
    Operation(const Operation&) = delete;
    Operation& operator = (const Operation&) = delete;

    Operation(size_t arity, std::function<Value(const std::vector<Value>&)> calc) : _arity(arity), _calc(calc) {}
    size_t getArity() const {
        return _arity;
    }

    Value getValue(const std::vector<Value>& args)const {
        if (args.size() != _arity) {
          throw std::invalid_argument(args.size() + " args not match arity " + _arity);
        }
      return _calc(args);
    };

  private:
    std::function<Value(const std::vector<Value>&)> _calc;
    size_t _arity;
};


#endif //EQUATIONS_OPERATION_H
