//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_POLYNOMIAL_H
#define EQUATIONS_POLYNOMIAL_H


#include "Monomial.h"

template <class Coefficient> class Polynomial {
    Polynomial() : _summands() {}

    Polynomial(Variable x) : _summands({Monomial(x), Coefficient(1)}) {}
    Polynomial(Monomial monomial) : _summands({{monomial, Coefficient(1)}}) {}

    Polynomial(Monomial monomial, Coefficient a) : _summands({{monomial, a}}) {}
    Polynomial(Variable x, Coefficient a) : _summands({Monomial(x), a}) {}

    Polynomial(const Polynomial& polynomial) : _summands(polynomial._summands) {}
    Polynomial& operator = (Polynomial polynomial) {
        polynomial.swap(*this);
        return *this;
    }
    void swap(Polynomial& polynomial) {
        std::swap(_summands, polynomial._summands);
    }

    bool operator == (const Polynomial&) const;

  private:
    std::map<Monomial, Coefficient>_summands;
};


#endif //EQUATIONS_POLYNOMIAL_H
