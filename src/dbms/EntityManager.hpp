#include <string>
#include <vector>
#include <filesystem>

namespace db {

    namespace fs {

        template <typename T>
        class EntityManager {
        public:
            EntityManager() = default;
            EntityManager(const std::filesystem::path&);
            EntityManager operator=(const EntityManager& other) = delete;
            EntityManager operator=(EntityManager&& other) {
                t_offset = other.t_offset;
                rootDir = other.rootDir;
            }

            void shrinkRecords();
            bool updateRecord(
                const std::vector<std::string>& fieldsWhere,
                const std::vector<std::string>& valsWhere,
                const std::vector<std::string>& fieldsUpdate,
                const std::vector<std::string>& valsUpdate,
            );
            bool deleteRecord(const std::vector<std::string>& fields, const std::string& vals);
            bool getRecord(const std::vector<std::string>& fields, const std::string& vals);
            bool insertRecord(const T& val);


            ~EntityManager();
        private:
            const std::size_t t_offset = sizeof(T);
            std::filesystem::path rootDir;
        };
    }
}