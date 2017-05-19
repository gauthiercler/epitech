add_executable(ASMTests
        strlen.cpp
        strcmp.cpp
        strncmp.cpp
        strcasecmp.cpp
        memset.cpp
        memcpy.cpp
        memmove.cpp
        rindex.cpp
        strchr.cpp
        strpbrk.cpp
        strcspn.cpp
        strstr.cpp)

add_definitions(-W -Wall -Wextra -Werror -lasm)

target_link_libraries(ASMTests
        GTest::GTest
        GTest::Main)