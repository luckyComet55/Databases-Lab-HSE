#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

#include "dbms/StudentManager.hpp"
#include "Types/Meta/Constants.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Err\n";
        std::exit(2);
    }
    std::filesystem::path sandbox{argv[1]};
    db::fs::student_manager manager(sandbox, true);
    std::cout << "Constructor ok\n";
    auto res = manager.insert_record({"Ivan", "Kurikhin", "Vladimirovich"});
    manager.show_containers();
    auto res1 = manager.insert_record({"Andrew", "Abramov", "Sergeevich"});
    manager.show_containers();
    res = manager.insert_record({"Ivan", "Kurikhin", "Vladimirovich"});
    std::cout << "Insert ok\n";
    switch (res) {
    case db::meta::TransactionStatus::SUCCESS:
        std::cout << "All good\n";
        break;
    case db::meta::TransactionStatus::FAIL_ON_CONSTRAINT:
        std::cout << "Unique verification fail\n";
        break;
    default:
        std::cout << "Internal error\n";
        break;
    }
    return 0;
}