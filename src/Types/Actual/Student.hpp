#include <string>

#include "Types/Meta/Constants.hpp"

#ifndef STUDENT_HPP
#define STUDENT_HPP

namespace db {

    namespace types {

        class Student {
        public:
            Student(const std::string& id_l, const char name_l[db::meta::MAX_NAME_LEN], const char surname_l[db::meta::MAX_NAME_LEN], const char patronym_l[db::meta::MAX_NAME_LEN]) {
                for (int i = 0; i < db::meta::MAX_ID_LEN; ++i) {
                    id[i] = id_l[i];
                }

                for (int i = 0; i < db::meta::MAX_NAME_LEN; ++i) {
                    name[i] = ' ';
                    surname[i] = ' ';
                    patronym[i] = ' ';
                }
                
                for (int i = 0; i < db::meta::MAX_NAME_LEN && name_l[i] != ' '; ++i) {
                    name[i] = name_l[i];
                }
                
                for (int i = 0; i < db::meta::MAX_NAME_LEN && surname_l[i] != ' '; ++i) {
                    surname[i] = surname_l[i];
                }

                for (int i = 0; i < db::meta::MAX_NAME_LEN && patronym_l[i] != ' '; ++i) {
                    patronym[i] = patronym_l[i];
                }
            }

            std::string getName() const {
                return name;
            }

            std::string getSurname() const {
                return surname;
            }

            std::string getPatronym() const {
                return patronym;
            }
        private:
            char id[db::meta::MAX_ID_LEN];
            char name[db::meta::MAX_NAME_LEN], surname[db::meta::MAX_NAME_LEN], patronym[db::meta::MAX_NAME_LEN];
        };
    }
}

#endif