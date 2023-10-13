#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

#include "Container.hpp"

#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

namespace db {

    namespace fs {

        template <typename T>
        class EntityManager {
        public:
            EntityManager() = default;
            EntityManager(const std::filesystem::path& rootDir, const std::vector<std::string>& fields) :
                rootDir(rootDir), fields(fields) {
                for (auto const& it : std::filesystem::directory_iterator{rootDir}) {
                    std::cout << it.path() << std::endl;
                }
            }
            EntityManager operator=(const EntityManager& other) = delete;
            EntityManager operator=(EntityManager&& other) {
                fields = other.fields;
                rootDir = other.rootDir;
            }

            db::meta::TransactionStatus updateRecord(
                const std::vector<std::string>&,
                const std::vector<std::string>&,
                const std::vector<std::string>&,
                const std::vector<std::string>&
            );
            db::meta::TransactionStatus deleteRecord(const std::vector<std::string>&, const std::string&);
            std::string getRecord(const std::vector<std::string>&, const std::string&);
            db::meta::TransactionStatus insertRecord(const std::vector<std::string>&);

        private:
            std::vector<std::string> fields;
            std::filesystem::path rootDir;
            std::vector<db::fs::Container<T>> containers;
        };
    }
}

#endif
