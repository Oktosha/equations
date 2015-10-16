//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_VARIABLE_H
#define EQUATIONS_VARIABLE_H

#include <string>

class Variable {
  public:
    Variable(std::string name): _name(name) {}
    Variable(const Variable& x): _name(x._name) {}
    Variable& operator = (Variable x) {
      x.swap(*this);
      return *this;
    }

    void swap(Variable& x) {
      std::swap(_name, x._name);
    }
    std::string get_name() const {return _name;}

    bool operator == (Variable x) const { return _name == x._name; }

  private:
    std::string _name;
};


#endif //EQUATIONS_VARIABLE_H
