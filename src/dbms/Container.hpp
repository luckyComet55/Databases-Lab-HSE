#include <filesystem>
#include <fstream>
#include <utility>
#include <vector>
#include <string>

#include "Types/Meta/Constants.hpp"

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace db {

    namespace fs {
        
        constexpr int MAX_RECORDS_PER_FILE = 2048;

        template <typename T>
        class Container {
        public:
            Container();
            Container(const std::filesystem::path&, bool, int, const std::vector<int>&);

            bool insert(const std::vector<std::string>&);
            bool remove(const std::vector<std::string>&, const std::vector<int>&);
            bool update(
                const std::vector<std::string>&,
                const std::vector<std::int>&,
                const std::vector<std::string>&,
                const std::vector<std::int>&,
            );
            std::pair<db::meta::TransactionStatus, std::string> find(const std::vector<std::string>&, const std::vector<int>&);
            std::pair<db::meta::TransactionStatus, std::string> find_by_id(char[db::meta::MAX_ID_LEN]);

            ~Container() {
                file.close();
            }
        private:
            const int start_offset = sizeof(db::fs::MAX_RECORDS_PER_FILE);
            const std::size_t t_offset = sizeof(T);
            const std::size_t t_max_records = sizeof(T) * db::fs::MAX_RECORDS_PER_FILE;
            const int fields_num;
            const std::vector<int> field_size;
            std::size_t records;
            std::fstream file;

            void shrink();
        };
    }
}

#endif
