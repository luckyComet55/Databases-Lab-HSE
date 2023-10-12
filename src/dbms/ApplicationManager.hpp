#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "Types/Meta/Record.hpp"
#include "Types/Actual/Student.hpp"
#include "Types/Actual/Assignment.hpp"
#include "Types/Actual/Mark.hpp"
#include "dbms/EntityManager.hpp"

#ifndef APP_MANAGER_HPP
#define APP_MANAGER_HPP

#define L1_DIRS 3

namespace db {

    namespace fs {

        class ApplicationManager {
        public:
            ApplicationManager();

            ~ApplicationManager();
        private:
            #ifdef __linux__
            const std::filesystem::path root{"/home/user1/luckygres-data"};
            #else
            const std::filesystem::path root{"C:\\Users\\Public\\luckygres-data"};
            #endif

            const char* dirs[L1_DIRS] = {"students", "assignments", "student-mark"};

            db::fs::EntityManager<db::types::Student> studentManager;
            db::fs::EntityManager<db::types::Assignment> assignmentManager;
            db::fs::EntityManager<db::types::StudentMark> studentMarkManager;
            
            bool startCold();
            bool startNormal();
            void exitCleanup();
            void normalCleanup();
        };
    }
}

#endif
