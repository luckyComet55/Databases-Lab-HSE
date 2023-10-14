#include <filesystem>
#include <fstream>
#include <utility>
#include <vector>
#include <string>

#include "../Types/Meta/Constants.hpp"

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace db {

    namespace fs {
        
        class Container {
        public:
            Container() = default;
            Container(const std::filesystem::path&, int);

            bool insert(const std::vector<std::string>&);
            std::pair<bool, std::vector<std::string>> get();
            std::string get_container_id() const {
                return container_id;
            }

            ~Container() {
                file.close();
            }
        private:
            const std::string container_id;
            const int fields_num;
            std::fstream file;
        };
    }
}

#endif
