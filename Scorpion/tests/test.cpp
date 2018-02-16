#include<iostream>
#include "scorpion_core_ops.h"
int main() {
    CoreOps coreops;
    Matrix A(3, 2);
    Matrix B(2, 3);
    Matrix C(3, 3);

    float a[3][2] = {{1,2},{3,4},{1,1}};
    float b[2][3] = {{1,2,3},{3,2,1}};
    A.equate_2d_matrix(*a, 3, 2);
    B.equate_2d_matrix(*b, 2, 3);
    for (int i=0;i<3;i++) {
        for (int j=0;j<2;++j) {
            std::cout<<A.base[i][j]<<std::endl;
        }
    }
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;++j) {
            std::cout<<B.base[i][j]<<std::endl;
        }
    }
    C = coreops.mat_mul(A, B);
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;++j) {
            std::cout<<C.base[i][j]<<std::endl;
        }
    }
}
