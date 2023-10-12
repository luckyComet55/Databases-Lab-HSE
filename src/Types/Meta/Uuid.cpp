#include <sstream>
#include <random>

#include "Uuid.hpp"

namespace db {

    namespace meta {

        namespace uuid {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_int_distribution<> dis(0, 15);
            static std::uniform_int_distribution<> dis2(8, 11);

            std::string generateUuid() {
                std::stringstream ss;
                int i;
                ss << std::hex;
                for (i = 0; i < 8; i++) {
                    ss << uuid::dis(uuid::gen);
                }
                ss << "-";
                for (i = 0; i < 4; i++) {
                    ss << uuid::dis(uuid::gen);
                }
                ss << "-4";
                for (i = 0; i < 3; i++) {
                    ss << uuid::dis(uuid::gen);
                }
                ss << "-";
                ss << uuid::dis2(uuid::gen);
                for (i = 0; i < 3; i++) {
                    ss << uuid::dis(uuid::gen);
                }
                ss << "-";
                for (i = 0; i < 12; i++) {
                    ss << uuid::dis(uuid::gen);
                };
                return ss.str();
            }
        }
    }
}