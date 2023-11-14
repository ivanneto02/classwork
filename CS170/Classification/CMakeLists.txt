CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	unit_test.cpp
)

ADD_EXECUTABLE(run1
	main_part1.cpp
	./src/Driver.cpp
	./src/Graph.cpp
)

ADD_EXECUTABLE(run2
	main_part2.cpp
	./src/ClassifierDriver.cpp
	./src/NearestNeighbors.cpp
	./src/Dataset.cpp
	./src/Validator.cpp
)

ADD_EXECUTABLE(run3
	main_part3.cpp
	./src/FullDriver.cpp
	./src/NearestNeighbors.cpp
	./src/Dataset.cpp
	./src/Validator.cpp
	./src/Graph.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)