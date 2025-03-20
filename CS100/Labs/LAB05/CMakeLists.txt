CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	tests/unit_test.cpp
	src/Add.cpp
	src/Div.cpp
	src/Rand.cpp
	src/Sub.cpp 
	src/Pow.cpp
	src/Mult.cpp
)

ADD_EXECUTABLE(lab
	main.cpp
	src/Add.cpp
	src/Div.cpp
	src/Rand.cpp
	src/Sub.cpp 
	src/Pow.cpp
	src/Mult.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
