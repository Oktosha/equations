//
// Created by Дарья Колодзей on 16.10.15.
//

#include "Variable.h"

std::ostream& operator << (std::ostream& os, const Variable& x) {
    os << x.getName();
    return os;
}
