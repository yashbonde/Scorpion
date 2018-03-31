#include <iostream>
#include <vector>
#include "../scorpion_core_files/scorpion_core.h"

int main() {
    std::vector<Matrix> v;
    Matrix A(2,2);
    v.push_back(A);
    std::cout << v.size() << '\n';
    return 0;
}
