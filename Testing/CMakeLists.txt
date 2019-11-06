# basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# first catch-based test
add_executable(testCatch testCatch.cpp catch.hpp)
add_test(NAME test-catch COMMAND testCatch)

# create interface library
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Test CaeserCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)
