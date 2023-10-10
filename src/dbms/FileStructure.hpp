#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#ifndef FILESTRUCT_HPP
#define FILESTRUCT_HPP

#define L1_DIRS 3

namespace db {

    namespace fs {

        class WorkDir {
        public:
            WorkDir() {
                std::cout << "Inside constructor\n";
                bool ok;
                if (!std::filesystem::exists(root)) {
                    ok = startCold();
                } else {
                    ok = startNormal();
                }

                if (!ok) {
                    std::cout << "Something went wrong\n";
                    exitCleanup();
                    std::exit(1);
                }
                std::cout << "Everything ok\n";
            }

            ~WorkDir() {
                normalCleanup();
            }
        private:
            const std::filesystem::path root{"/home/user1/luckygres-data"};
            const char* dirs[L1_DIRS] = {"students", "assignments", "student-assignment"};
            std::size_t nodeSize;
            std::size_t clusterSize;

            bool startCold() {
                bool res = std::filesystem::create_directory(root);
                if (!res) {
                    return false;
                }
                for (int i = 0; i < L1_DIRS; ++i) {
                    res = createDir(root / dirs[i]);
                    if (!res) {
                        break;
                    }
                }
                return res;
            }

            bool createDir(const std::filesystem::path& rootDir) {
                bool res = std::filesystem::create_directories(rootDir / "data");
                if (!res) {
                    return false;
                }
                res = std::filesystem::create_directories(rootDir / "indexies");
                return res;
            }

            bool startNormal() {

                return true;
            }

            void exitCleanup() {

            }

            void normalCleanup() {

            }
        };
    }
}

#endif
