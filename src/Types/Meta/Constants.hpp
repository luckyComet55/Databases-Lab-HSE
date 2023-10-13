#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace db {

    namespace meta {

        constexpr int MAX_NAME_LEN = 30;
        constexpr int MAX_ID_LEN = 36;
        constexpr int MAX_VAR_LEN = 50;
        constexpr int MAX_MARK_LEN = 1;

        enum class TransactionStatus {
            SUCCESS,
            FAIL_ON_INTERNAL,
            FAIL_ON_CONSTRAINT,
            FAIL_ON_SPACE
        };
    }
}

#endif