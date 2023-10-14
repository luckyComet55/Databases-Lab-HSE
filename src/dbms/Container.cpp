#include <vector>
#include <string>
#include <ios>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <utility>

#include "Container.hpp"

namespace db {

    namespace fs {

        Container::Container(const std::filesystem::path& path, int fields_num, std::string& container_id) :
        fields_num(fields_num), container_id(container_id), filepath(path) {}

        bool Container::insert(const std::vector<std::string>& vals) {
            std::ofstream file{filepath};
            if (!file.is_open()) {
                std::cout << "File is closed\n";
                return false;
            }

            file << container_id << ' ';
            for (auto const& s : vals) {
                file << s << ' ';
            }
            file.close();
            return true;
        }

        std::pair<bool, std::vector<std::string>> Container::get() {
            std::ifstream file{filepath};
            if (!file.is_open()) {
                std::cout << "File is closed\n";
                return {false, {}};
            }
            std::vector<std::string> res(fields_num);
            for (int i = 0; i < fields_num; ++i) {
                file >> res[i];
            }

            file.close();
            return {true, res};
        }
    }
}