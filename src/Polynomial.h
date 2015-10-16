//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_POLYNOMIAL_H
#define EQUATIONS_POLYNOMIAL_H


#include "Monomial.h"

template <class Coefficient> class Polynomial {
  public:
    Polynomial() : _summands() {}

    Polynomial(Variable x) : _summands({{Monomial(x), Coefficient(1)}}) {}
    Polynomial(Monomial monomial) : _summands({{monomial, Coefficient(1)}}) {}

    Polynomial(Monomial monomial, Coefficient a) : _summands({{monomial, a}}) {}
    Polynomial(Variable x, Coefficient a) : _summands({{Monomial(x), a}}) {}


    Polynomial(const Polynomial<Coefficient>& polynomial) : _summands(polynomial._summands) {}
    Polynomial<Coefficient>& operator = (Polynomial<Coefficient> polynomial) {
        polynomial.swap(*this);
        return *this;
    }
    void swap(Polynomial<Coefficient>& polynomial) {
        std::swap(_summands, polynomial._summands);
    }

    bool operator == (const Polynomial<Coefficient>&) const;

  private:
    std::map<Monomial, Coefficient>_summands;
};


template <class Coefficient>
bool Polynomial<Coefficient>::operator == (const Polynomial<Coefficient> &polynomial) const {
    if (&polynomial == this)
        return true;
    if (polynomial._summands.size() != _summands.size())
        return false;
    bool ans = true;
    for (auto it = _summands.cbegin(); ans && (it != _summands.cend()); ++it) {
        ans = ans && (polynomial._summands.find(it->first) != polynomial._summands.cend())
              && (polynomial._summands.at(it->first) == it->second);
    }
    return ans;
}

#endif //EQUATIONS_POLYNOMIAL_H
