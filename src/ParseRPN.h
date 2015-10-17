//
// Created by Дарья Колодзей on 17.10.15.
//

#ifndef EQUATIONS_PARSERPN_H
#define EQUATIONS_PARSERPN_H

#include <string>
#include <map>
#include <sstream>
#include "Operation.h"

template <class Value>
std::vector<Operation<Value>> parseRPN(const std::string& expression,
                                       const std::map<char, std::pair<int,
                                               std::function<Value(const std::vector<Value>&)>>>& operators) {
    std::vector<Operation<Value>> ans;
    std::stringstream ss;
    for (char ch : expression) {
        if (ch == ' ')
            continue;
        if (operators.find(ch) != operators.cend()) {
            if (ss.str() != "") {
                Value x;
                ss >> x;
                ans.emplace_back(0, [x](){return x;});
            }
            ans.emplace_back(operators[ch].first, operators[ch].second);
        } else {
            ss << ch;
        }
    }
    return ans;
}

#endif //EQUATIONS_PARSERPN_H
