//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_POLYNOMIAL_H
#define EQUATIONS_POLYNOMIAL_H


#include "Monomial.h"
#include <iostream>

template <class Coefficient> class Polynomial;

template<class Coefficient>
std::ostream& operator << (std::ostream& os, const Polynomial<Coefficient>& polynomial) {
    for (auto it = polynomial._summands.cbegin(); it != polynomial._summands.cend(); ++it) {
        if ((it != polynomial._summands.cbegin()) && (it != --polynomial._summands.cend())) {
            os << " + ";
        }
        if (it->second != Coefficient(1)) {
            os << it->second;
        }
        os << it->first;
    }
    return os;
}

template <class Coefficient> class Polynomial {
  public:
    Polynomial() : _summands() {}

    explicit Polynomial(Variable x) : _summands({{Monomial(x), Coefficient(1)}}) {}
    explicit Polynomial(Monomial monomial) : _summands({{monomial, Coefficient(1)}}) {} //revrite constructor for empty monomial

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
    Polynomial operator * (const Coefficient&) const;
    Polynomial operator + (const Polynomial&) const;
    friend std::ostream& operator << <> (std::ostream&, const Polynomial<Coefficient>&);

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

template <class Coefficient>
Polynomial<Coefficient> Polynomial<Coefficient>::operator * (const Coefficient& a) const {
    if (a == Coefficient(0)) {
        return Polynomial();
    }
    Polynomial<Coefficient> ans = Polynomial<Coefficient>();
    for (auto it = _summands.cbegin(); it != _summands.cend(); ++it) {
        ans._summands[it->first] = it->second * a;
    }
    return ans;
}

template <class Coefficient>
Polynomial<Coefficient> operator * (const Coefficient&a, const Polynomial<Coefficient>& polynomial) {
    return polynomial * a;
}

template <class Coefficient>
Polynomial<Coefficient> Polynomial<Coefficient>::operator + (const Polynomial<Coefficient>& p) const {
    std::cout << std::endl << "sum" << "[" << *this << "] + [" << p << "]" << std::endl;
    Polynomial ans = Polynomial();
    std::cout << "empty ans" << std::endl;
    for (auto it = ans._summands.cbegin(); it != ans._summands.cend(); ++it) {
        std::cout << it->second << " : " << it->first << std::endl;
    }
    std::cout << "inserting first " << *this << std::endl;
    for (auto it = _summands.cbegin(); it != _summands.cend(); ++it) {
        ans._summands.insert(*it);
        std::cout << "insert = " << it->first << " : " << it->second << std::endl;
        std::cout << "ans = " << ans << std::endl;
    }
    std::cout << "first copy ans" << std::endl;
    for (auto it = ans._summands.cbegin(); it != ans._summands.cend(); ++it) {
        std::cout << it->second << " : " << it->first << std::endl;
    }
    std::cout << "inserting second " << p << std::endl;
    for (auto it = p._summands.cbegin(); it != p._summands.cend(); ++it) {
        if (!ans._summands.insert(*it).second) {
            ans._summands.at(it->first) += it->second;
            if (ans._summands.at(it->first) == Coefficient(0)) {
                ans._summands.erase(it->first);
            }
        }

        std::cout << "insert = " << it->first << " : " << it->second << std::endl;
        std::cout << "ans = " << ans << std::endl;
    }
    std::cout << "final ans" << std::endl;
    for (auto it = ans._summands.cbegin(); it != ans._summands.cend(); ++it) {
        std::cout << it->second << " : " << it->first << std::endl;
    }
    return ans;
}

#endif //EQUATIONS_POLYNOMIAL_H

