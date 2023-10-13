#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "dbms/EntityManager.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::exit(2);
    }
    std::filesystem::path sandbox{argv[1]};
    std::ofstream{sandbox/"f1.txt"};
    std::ofstream{sandbox/"f2.txt"};
    db::fs::EntityManager<int> em(sandbox, {"val"});
    return 0;
}