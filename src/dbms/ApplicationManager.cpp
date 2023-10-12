#include "ApplicationManager.hpp"

namespace db {

    namespace fs {

        ApplicationManager::ApplicationManager() {
            bool ok;
            if (!std::filesystem::exists(root)) {
                ok = startCold();
            } else {
                ok = startNormal();
            }

            if (!ok) {
                exitCleanup();
                std::exit(1);
            }
            studentManager = db::fs::EntityManager<db::types::Student>(root / dirs[0]);
            assignmentManager = db::fs::EntityManager<db::types::Assignment>(root / dirs[1]);
            studentMarkManager = db::fs::EntityManager<db::types::StudentMark>(root / dirs[1]);
        }

        ApplicationManager::~ApplicationManager() {
            normalCleanup();
        }

        bool ApplicationManager::startCold() {
            bool res = std::filesystem::create_directory(root);
            if (!res) {
                return false;
            }

            res = res & std::filesystem::create_directories(root / dirs[0]);
            res = res & std::filesystem::create_directories(root / dirs[1]);
            res = res & std::filesystem::create_directories(root / dirs[2]);
            return res;
        }

        void ApplicationManager::exitCleanup() {
            
        }

    }
}