#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

#include "Container.hpp"

#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

namespace db {

    namespace fs {

        enum class TransactionStatus {
            SUCCESS,
            FAIL_ON_INTERNAL,
            FAIL_ON_CONSTRAINT,
            FAIL_ON_SPACE
        };

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

            db::fs::TransactionStatus updateRecord(
                const std::vector<std::string>& fieldsWhere,
                const std::vector<std::string>& valsWhere,
                const std::vector<std::string>& fieldsUpdate,
                const std::vector<std::string>& valsUpdate
            );
            db::fs::TransactionStatus deleteRecord(const std::vector<std::string>& fields, const std::string& vals);
            std::string getRecord(const std::vector<std::string>& fields, const std::string& vals);
            db::fs::TransactionStatus insertRecord(const std::vector<std::string>& val);

        private:
            std::vector<std::string> fields;
            std::filesystem::path rootDir;
            std::vector<db::fs::Container<T>> containers;
        };
    }
}

#endif
