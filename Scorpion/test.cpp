#include "scorpion.h"

int main() {
    ScorpionModel s;
    s.load_architecture("./tests/sample.scarch");
    Matrix inp(10, 1);
    s.predict(inp);
    return 0;
}
