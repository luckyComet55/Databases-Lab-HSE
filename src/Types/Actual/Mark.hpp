#include "Types/Meta/Uuid.hpp"

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
            StudentMark() = delete;
            StudentMark(db::meta::Uuid student_id, db::meta::Uuid assignement_id) :
                student_id(student_id), assignment_id(assignement_id) {}
            StudentMark(db::meta::Uuid student_id, db::meta::Uuid assignement_id, db::types::Mark Mark) :
                student_id(student_id), assignment_id(assignement_id), mark(mark) {}
            StudentMark operator=(const StudentMark& other) {
                student_id = other.student_id;
                assignment_id = other.assignment_id;
                mark = other.mark;
            }
        private:
            db::meta::Uuid student_id, assignment_id;
            db::types::Mark mark;
        };
    }
}

#endif
