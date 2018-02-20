#include <iostream>
#include "../scorpion_layers/core_layers.h"

int main() {
    float a[3][5] = {
                        {1,2,3,4,5},
                        {-1,-2,-3,-4,-5},
                        {-5.2,-2.2,-0.9,0.11,1.231},
                    };
    Matrix A(3,5);
    A.equate_2d_matrix(*a,3,5);
    A.print();
}
