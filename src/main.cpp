#include <iostream>
#include "Variable.h"

using namespace std;

int main() {
    Variable x("x");
    cout << "current x:" << x.getName() << endl;
    return 0;
}