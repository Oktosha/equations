//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_MONOMIAL_H
#define EQUATIONS_MONOMIAL_H


#include <string>
#include <map>
#include "Variable.h"

class Monomial {
  public:
    Monomial(): _multipliers() {}
    Monomial(Variable x): _multipliers({{x, 1}}) {}
    Monomial(Variable x, int degree): _multipliers({{x, degree}}) {}
    Monomial(const Monomial& p) : _multipliers(p._multipliers) {}
    Monomial& operator = (Monomial p) {
        p.swap(*this);
        return *this;
    }
    void swap(Monomial& p) {
        std::swap(_multipliers, p._multipliers);
    }
    bool operator == (const Monomial& p) const;
    Monomial operator * (const Monomial& p) const;
    friend std::ostream& operator << (std::ostream& os, const Monomial& p);
  private:
    std::map<Variable, int> _multipliers;
};

Monomial operator * (const Variable& x, const Monomial& p);
Monomial operator * (const Variable& x, const Variable& y);
Monomial operator * (const Monomial& p, const Variable& x);
Monomial pow(const Variable& x, int degree);

#endif //EQUATIONS_MONOMIAL_H
