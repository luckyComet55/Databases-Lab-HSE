#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "dbms/EntityManager.hpp"
#include "Types/Meta/Constants.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::exit(2);
    }
    std::filesystem::path sandbox{argv[1]};
    db::fs::EntityManager<int> em(sandbox, {"val"}, {2});
    em.insertRecord({"4"});
    em.getRecord({"4"}, {"val"});
    return 0;
}