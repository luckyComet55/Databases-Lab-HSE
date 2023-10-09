#include <string>

#ifndef STUDENT_HPP
#define STUDENT_HPP

namespace db {

    namespace types {

        class Student {
        public:
            Student() = delete;
            Student(const Student& st) {
                name = st.name;
                surname = st.surname;
                patronym = st.patronym;
            }
            Student(Student&& st) : name(std::move(st.name)), surname(std::move(st.surname)), patronym(std::move(st.patronym)) {}
            Student(std::string& name, std::string& surname, std::string& patronym) : name(name), surname(surname), patronym(patronym) {}
            Student(std::string&& name, std::string&& surname, std::string&& patronym) : name(name), surname(surname), patronym(patronym) {}

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
            std::string name, surname, patronym;
        };
    }
}

#endif