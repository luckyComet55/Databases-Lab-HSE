#include "Uuid.hpp"
#ifndef RECORD_HPP
#define RECORD_HPP

namespace db {
    
    namespace meta {
        
        template <typename T>
        class Record {
        public:
            Record() = delete;
            Record(const Record&) = delete;
            Record(Record&&) = delete;
            Record(T newInstance) : instance(newInstance), uuid() {
                // change to generate real uuid's
                // or at least - timestamps
            }

            Uuid getUuid() const {
                return uuid;
            }

            T getInstance() const {
                return instance;
            }
        private:
            T instance;
            Uuid uuid;
        };
    }
}

#endif