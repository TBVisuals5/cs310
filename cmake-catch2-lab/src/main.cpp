#include <iostream>
#include "math_functions.h"
using namespace std;

int main() {
    double num = 25.0;
    double result = compute_square_root(num);
    cout << "Square root of " << num << " is " << result << endl;
    return 0;
}