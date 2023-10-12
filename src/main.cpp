#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "dbms/EntityManager.hpp"

int main() {
    std::filesystem::path sandbox{"C:/Users/kurik/VSCode Projects/Databases Lab 1/"};
    std::ofstream{sandbox/"f1.txt"};
    std::ofstream{sandbox/"f2.txt"};
    db::fs::EntityManager<int> em(sandbox, {"val"});
    return 0;
}