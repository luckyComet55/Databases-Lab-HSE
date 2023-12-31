#include <string>

#include "Types/Meta/Constants.hpp"

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

namespace db {

    namespace types {

        class Assignment {
        public:
            Assignment(char title_l[db::meta::MAX_VAR_LEN]) {
                for (int i = 0; i < db::meta::MAX_VAR_LEN; ++i) {
                    title[i] = ' ';
                }

                for (int i = 0; i < db::meta::MAX_VAR_LEN && title_l[i] != ' '; ++i) {
                    title[i] = title_l[i];
                }
            }

            std::string getTitle() { return title; };
        private:
            char title[db::meta::MAX_VAR_LEN];
        };
    }
}

#endif