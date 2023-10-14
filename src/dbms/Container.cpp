#include <vector>
#include <string>
#include <ios>
#include <filesystem>
#include <fstream>
#include <utility>

#include "../Types/Meta/Uuid.hpp"
#include "Container.hpp"

namespace db {

    namespace fs {

        Container::Container(const std::filesystem::path& path, int fields_num) :
        fields_num(fields_num), container_id(db::meta::uuid::generateUuid()) {
            file.open(path.string(), std::ios::app | std::ios::in);
        }

        bool Container::insert(const std::vector<std::string>& vals) {
            if (!file.is_open()) {
                return false;
            }

            for (auto const& s : vals) {
                file << s << ' ';
            }
            file.seekg(std::ios_base::beg);
            return true;
        }

        std::pair<bool, std::vector<std::string>> Container::get() {
            if (!file.is_open()) {
                return {false, {}};
            }

            file.seekg(std::ios_base::beg);
            std::vector<std::string> res(fields_num);
            for (int i = 0; i < fields_num; ++i) {
                file >> res[i];
            }

            file.seekg(std::ios_base::beg);
            return {true, res};
        }
    }
}