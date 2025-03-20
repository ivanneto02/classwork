CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main.out
    main.cpp src/factory/ExpressionFactory.cpp
)

ADD_EXECUTABLE(calculator
    main.cpp src/factory/ExpressionFactory.cpp
)

ADD_EXECUTABLE(test.out
    tests/unit_tests.cpp
)


ADD_COMPILE_OPTIONS(-g -O0 -fno-inline)

TARGET_LINK_LIBRARIES(test.out gtest)
TARGET_COMPILE_DEFINITIONS(test.out PRIVATE gtest_disable_pthreads=ON)