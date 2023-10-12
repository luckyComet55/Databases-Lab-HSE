#include <filesystem>
#include <fstream>

#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#define MAX_RECORDS_PER_FILE 2048

namespace db {

    namespace fs {
        
        template <typename T>
        class Container {
        public:
            Container();
            Container(const std::filesystem::path&, bool is_new);

            ~Container() {
                file.close();
            }
        private:
            const int start_offset = sizeof(MAX_RECORDS_PER_FILE);
            const std::size_t t_offset = sizeof(T);
            const std::size_t t_max_records = sizeof(T) * MAX_RECORDS_PER_FILE;
            std::size_t records;
            std::fstream file;

            void shrink();
        };
    }
}

#endif
