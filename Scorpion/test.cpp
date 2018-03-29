#include "scorpion.h"

int main() {
    ScorpionModel s;
    s.load_architecture("tests/sample.scarch");
    std::cout << s.layers << "\n";
    return 0;
}
