#include "WordingEngine.hpp"
#include <unordered_map>

int main(){
    std::string testInput = "abcdef{{ghijk}}lmnopqrstuvwxyz{{ghijk}}";
    std::unordered_map<std::string, std::string> map;
    map["ghijk"] = "Hello, World!";

    std::cout << wordingEngine::process(testInput, map);

    return 0;
}