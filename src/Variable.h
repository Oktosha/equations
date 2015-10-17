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
    std::string getName() const {return _name;}

    bool operator == (const Variable& x) const { return _name == x._name; }

    friend std::ostream& operator << (std::ostream& os, const Variable& x);

  private:
    std::string _name;
};


#endif //EQUATIONS_VARIABLE_H
