CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main.out
    main.cpp
)

ADD_EXECUTABLE(calculator
    main.cpp
)

ADD_EXECUTABLE(test.out
    tests/unit_tests.cpp
)

TARGET_LINK_LIBRARIES(test.out gtest)
TARGET_COMPILE_DEFINITIONS(test.out PRIVATE gtest_disable_pthreads=ON)