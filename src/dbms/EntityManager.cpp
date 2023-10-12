#include <filesystem>

#include "EntityManager.hpp"

namespace db {

    namespace fs {

        template <typename T>
        EntityManager<T>::EntityManager(const std::filesystem::path& root) : rootDir(root) {

        }

        template <typename T>
        EntityManager<T>::~EntityManager() {

        }
    }
}