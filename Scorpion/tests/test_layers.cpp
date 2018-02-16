#include <iostream>
#include <cmath>
#include "../scorpion_layers/core_layers.h"
CoreLayers c;

#define p(i) std::cout<<i<<'\n'

void test_sigmoid() {
    bool flag = true;
    float a[3][5] = {
                        {1,2,3,4,5},
                        {-1,-2,-3,-4,-5},
                        {-5.2,-2.2,-0.9,0.11,1.231},
                    };
    float ans[3][5] = {
                        {0.73106,0.8808,0.95257,0.98201,0.99331},
                        {0.26894,0.11920,0.047426,0.017986,0.0066929},
                        {0.0054863,0.09975,0.28905,0.52747,0.77399}
                    };
    Matrix A(3,5);
    A.equate_2d_matrix(*a,3,5);
    Matrix RES(3,5);
    RES = c.sigmoid(A);
    for(int i=0;i<3;i++) {
        for(int j=0;j<5;j++) {
            // p(std::abs(RES.base[i][j]-ans[i][j]));
            if(std::abs(RES.base[i][j]-ans[i][j])>0.001) {
                std::cout<<"Error in Sigmoid:\ni: "<<i<<"\nj: "<<j<<"\nExpected value: "<<ans[i][j]<<"\nResult: "<<RES.base[i][j]<<'\n';
                flag = false;
            }
        }
    }
    if(flag) std::cout<<"Sigmoid test completed successfully\n";
}

int main() {
    test_sigmoid();
    return 0;
}