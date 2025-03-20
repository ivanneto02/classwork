CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main.out
    main.cpp
    src/Add.cpp
    src/Div.cpp
    src/iterator.cpp
    src/Mult.cpp
    src/Pow.cpp
    src/Rand.cpp
    src/Sub.cpp
    src/VisitorLaTeX.cpp
    src/VisitorMathML.cpp
)

ADD_EXECUTABLE(test.out
    tests/unit_tests.cpp
    src/Add.cpp
    src/Div.cpp
    src/iterator.cpp
    src/Mult.cpp
    src/Pow.cpp
    src/Rand.cpp
    src/Sub.cpp
    src/VisitorLaTeX.cpp
    src/VisitorMathML.cpp
)

ADD_COMPILE_OPTIONS(-g -O0 -fno-inline)

TARGET_LINK_LIBRARIES(test.out gtest)
TARGET_COMPILE_DEFINITIONS(test.out PRIVATE gtest_disable_pthreads=ON)