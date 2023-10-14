#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <filesystem>

#include "Container.hpp"
#include "../Types/Meta/Constants.hpp"

#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP

namespace db {

    namespace fs {

        class student_manager {
        public:

            student_manager() = default;
            student_manager(const std::filesystem::path&, bool);

            std::pair<db::meta::TransactionStatus, std::vector<std::string>> find_record(const std::vector<std::string>&, const std::vector<int>&);
            db::meta::TransactionStatus insert_record(const std::vector<std::string>&);
            db::meta::TransactionStatus delete_record(const std::vector<std::string>&, const std::vector<int>&);
            db::meta::TransactionStatus update_record(
                const std::vector<std::string>&,
                const std::vector<int>&,
                const std::vector<std::string>&,
                const std::vector<int>&
            );

            void show_containers() {

                for (int i = 0; i < containers.size(); ++i) {
                    std::cout << "Container " << containers[i].get_container_id() << std::endl;
                }
            }
        private:
            std::vector<db::fs::Container> containers;
            const std::vector<std::string> fields{"id", "name", "surname", "patronym"};
            const std::filesystem::path root_dir;

            std::pair<bool, std::vector<int>> find_containers_where_clause(const std::vector<std::string>&, const std::vector<int>&);
        };
    }
}

#endif
