#include <vector>
#include <string>
#include <ios>
#include <filesystem>
#include <fstream>
#include <utility>

#include "Types/Meta/Constants.hpp"
#include "Container.hpp"

namespace db {

    namespace fs {

        template <typename T>
        Container<T>::Container() {
            // maybe delete later
        }

        template <typename T>
        Container<T>::Container(const std::filesystem::path& path, bool is_new, int fields_num, const std::vector<int>& field_size) :
        fields_num(fields_num), field_size(field_size) {
            file.open(path.string(), std::ios::app | std::ios::in);

            if (is_new) {
                records = 0;
                file << records;
            } else {
                file >> records;
            }
        }

        template <typename T>
        void Container<T>::shrink() {

        }

        template <typename T>
        bool Container<T>::insert(const std::vector<std::string>& values) {
            if (!file.is_open()) {
                return false;
            }

            file.seekg(start_offset + records * t_offset);
            for (auto const& s : values) {
                file << s << ' ';
            }
            file << '\n';
            records++:
            file.seekg(std::ios_base::beg);
            file << records;
            return true;
        }

        template <typename T>
        std::pair<db::meta::TransactionStatus, std::string> Container<T>::find(const std::vector<std::string>& where_values, const std::vector<int>& where_fields) {
            if (!file.is_open()) {
                return {false, ""};
            }

            file.seekg(start_offset);
            std::string str;
            for (int i = 0; i < records; ++i) {
                std::size_t object_start_offset = file.tellg();
                std::getline(file, str);
                std::cout << str << std::endl;
            }

            return {false, ""};
        }

    }
}