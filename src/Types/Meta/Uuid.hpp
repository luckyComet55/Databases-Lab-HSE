#include <string>

#ifndef UUID_HPP
#define UUID_HPP

namespace db {

    namespace meta {
        class Uuid {
        public:
            Uuid();
            std::string getUuid() const {
                return value;
            }
        private:
            std::string value;
        };
    }
}

#endif