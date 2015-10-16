//
// Created by Дарья Колодзей on 16.10.15.
//

#include "Monomial.h"
#include <iostream>

bool Monomial::operator == (const Monomial& p) const {
    if (&p == this)
        return true;
    if (p._multipliers.size() != _multipliers.size())
        return false;
    bool ans = true;
    for (auto it = _multipliers.cbegin(); ans && (it != _multipliers.cend()); ++it) {
        ans = ans && (p._multipliers.find(it->first) != p._multipliers.cend())
                  && (p._multipliers.at(it->first) == it->second);
    }
    return ans;
}

Monomial Monomial::operator * (const Monomial& p) const {
    Monomial ans = Monomial();
    for (auto it = _multipliers.cbegin(); it != _multipliers.cend(); ++it) {
        ans._multipliers.insert(*it);
    }
    for (auto it = p._multipliers.cbegin(); it != p._multipliers.cend(); ++it) {
        if (!ans._multipliers.insert(*it).second) {
            ans._multipliers.at(it->first) += it->second;
        }
    }
    return ans;
}

std::ostream& operator << (std::ostream& os, const Monomial& p) {
    for (auto it = p._multipliers.cbegin(); it != p._multipliers.cend(); ++it) {
        if (it->second != 1) {
            os << "(" << it -> first << "^" << it -> second << ")";
        } else {
            os << it->first;
        }
    }
    return os;
}

Monomial operator * (const Variable& x, const Monomial& p) {
    return Monomial(x) * p;
}
Monomial operator * (const Variable& x, const Variable& y) {
    return Monomial(x) * Monomial(y);
}
Monomial operator * (const Monomial& p, const Variable& x) {
    return Monomial(x) * p;
}
Monomial pow(const Variable& x, int degree) {
    return Monomial(x, degree);
}

bool Monomial::operator < (const Monomial &p) const {
    for (auto it = _multipliers.cbegin(),
                 jt = p._multipliers.cbegin(); it != _multipliers.cend() &&
                                               jt != p._multipliers.cend(); ++it, ++jt) {
        if ((it->first == jt->first) && (it->second == jt->second))
            continue;
        return (it->first < jt->first) || ((it->first == jt->first) && (it->second > jt->second));
    }
    return _multipliers.size() > p._multipliers.size();
}
