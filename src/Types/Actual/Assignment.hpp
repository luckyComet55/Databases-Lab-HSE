#include <string>

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

namespace db {

    namespace types {

        class Assignment {
        public:
            Assignment() = delete;
            Assignment(const Assignment& other) : title(other.title) {}
            Assignment(Assignment&& other) : title(std::move(other.title)) {}
            Assignment(const std::string& title) : title(title) {}
            Assignment(std::string&& title) : title(title) {}

            std::string getTitle() { return title; };
        private:
            std::string title;
        };
    }
}

#endif