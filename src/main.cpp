#include <iostream>
#include "Variable.h"

using namespace std;

int main() {
    Variable x(3);
    cout << "current x:" << x.get_x() << endl;
    return 0;
}