//
// Created by Дарья Колодзей on 16.10.15.
//

#ifndef EQUATIONS_VARIABLE_H
#define EQUATIONS_VARIABLE_H


class Variable {
  public:
    Variable(int x): x(x) {}
    int get_x();
  private:
    int x;
};


#endif //EQUATIONS_VARIABLE_H
