#include <filesystem>
#include <fstream>

#include "Container.hpp"

namespace db {

    namespace fs {

        template <typename T>
        Container<T>::Container() {
            // maybe delete later
        }

        template <typename T>
        Container<T>::Container(const std::filesystem::path& path, bool is_new) {
            file.open(path.string());

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
    }
}