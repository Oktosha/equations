//
// Created by Дарья Колодзей on 16.10.15.
//

#include "Polynomial.h"

bool Polynomial::operator == (const Polynomial &polynomial) const {
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
