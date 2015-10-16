#include "Variable.h"
#include <iostream>

using namespace std;

int main() {
    Variable x(5);
    cout << "test x:" << x.get_x() << endl;
    return 1;
}