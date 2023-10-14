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
            Container(const Container& other) : container_id(other.container_id), fields_num(other.fields_num), filepath(other.filepath) {}
            Container(const std::filesystem::path&, int, std::string&);

            bool insert(const std::vector<std::string>&);
            std::pair<bool, std::vector<std::string>> get();
            std::string get_container_id() const {
                return container_id;
            }

            ~Container() = default;
        private:
            const std::string container_id;
            const int fields_num;
            const std::filesystem::path filepath;
        };
    }
}

#endif
