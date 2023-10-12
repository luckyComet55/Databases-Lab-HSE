#include "Types/Meta/Uuid.hpp"
#include "Types/Meta/Constants.hpp"

#ifndef MARK_HPP
#define MARK_HPP

namespace db {

    namespace types {

        enum class Mark {
            TBNT = 1,
            Bad,
            Satisfactory,
            Good,
            Excellent
        };

        class StudentMark {
        public:
            StudentMark(const std::string& student_id_l, const std::string& assignment_id_l) {
                for (int i = 0; i < MAX_ID_LEN; ++i) {
                    student_id[i] = student_id_l[i];
                }

                for (int i = 0; i < MAX_ID_LEN; ++i) {
                    assignment_id[i] = assignment_id_l[i];
                }
            }

            StudentMark(const std::string& student_id_l, const std::string& assignment_id_l, db::types::Mark Mark) :
                mark(mark) {
                for (int i = 0; i < MAX_ID_LEN; ++i) {
                    student_id[i] = student_id_l[i];
                }

                for (int i = 0; i < MAX_ID_LEN; ++i) {
                    assignment_id[i] = assignment_id_l[i];
                }
            }
        private:
            char student_id[MAX_ID_LEN], assignment_id[MAX_ID_LEN];
            db::types::Mark mark;
        };
    }
}

#endif
