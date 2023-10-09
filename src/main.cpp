#include <iostream>
#include <string>

#include "Types/Actual/Student.hpp"
#include "Types/Actual/Assignment.hpp"
#include "Types/Meta/Record.hpp"

int main() {
    db::types::Student student("Ivan", "Ivanov", "Ivanovich");
    db::types::Assignment assignment("Lab 1");

    db::meta::Record<db::types::Student> r1(student);
    db::meta::Record<db::types::Assignment> r2(assignment);

    std::cout << r1.getUuid().getUuid() << " -> " << r1.getInstance().getName() << ' ' << r1.getInstance().getSurname() << ' ' << r1.getInstance().getPatronym() << std::endl;
    std::cout << r2.getUuid().getUuid() << " -> " << r2.getInstance().getTitle() << std::endl;
    return 0;
}