#include "../external/json.hpp"
#include <fstream>
#include <iostream>

// for convenience
using json = nlohmann::json;

int main() {
    std::ifstream i("sample.scarch");
    json j;
    i >> j;
    std::cout << j << '\n';
    std::cout << '\n';
    std::cout << j["layers"] << '\n';
    std::cout << '\n';
    std::cout << j["layers"].size() << '\n';
    std::cout << j["layers"][0] << '\n';
    std::cout << '\n';
    std::cout << j["layers"][0]["activation"] << '\n';
    std::cout << '\n';
    //std::ofstream o("pretty.json");
    //o << std::setw(4) << j <<  std::endl;
    return 0;
}