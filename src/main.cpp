#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "dbms/StudentManager.hpp"
#include "Types/Meta/Constants.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::exit(2);
    }
    std::filesystem::path sandbox{argv[1]};
    db::fs::student_manager manager(sandbox, false);
    auto res2 = manager.delete_record({"Ivan"}, {1});
    switch (res2) {
    case db::meta::TransactionStatus::SUCCESS:
        std::cout << "All good\n";
        break;
    case db::meta::TransactionStatus::NOT_FOUND:
        std::cout << "Not found\n";
        break;
    default:
        std::cout << "Internal error\n";
        std::exit(10);
    }
    return 0;
}