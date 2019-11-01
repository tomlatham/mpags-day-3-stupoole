add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

add_executable(testCatch testCatch.cpp catch.hpp)
add_test(NAME test-catch COMMAND testCatch)