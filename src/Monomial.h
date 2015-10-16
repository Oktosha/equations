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
    Monomial(Variable x): _multipliers({{x.getName(), 1}}) {}
    Monomial(Variable x, int degree): _multipliers({{x.getName(), degree}}) {}
    Monomial(const Monomial& p) : _multipliers(p._multipliers) {}
    Monomial& operator = (Monomial p) {
        p.swap(*this);
        return *this;
    }
    void swap(Monomial& p) {
        std::swap(_multipliers, p._multipliers);
    }
    bool operator == (const Monomial p) const;
    Monomial operator * (const Monomial p) const;
    friend std::ostream& operator << (std::ostream& os, const Monomial& p);
  private:
    std::map<std::string, int> _multipliers;
};


#endif //EQUATIONS_MONOMIAL_H
