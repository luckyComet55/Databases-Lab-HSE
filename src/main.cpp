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
    res = manager.insert_record({"Ivan", "Kurikhin", "Alexandrovich"});
    manager.show_containers();
    res = manager.insert_record({"Ivan", "Miroshnochenko", "Vladimirovich"});
    manager.show_containers();
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
        std::exit(10);
    }

    auto res2 = manager.find_record({"Ivan"}, {1});
    switch (res2.first) {
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
    for (int i = 0; i < res2.second.size(); ++i) {
        std::cout << "Student: " << res2.second[i] << '\n';
    }
    return 0;
}