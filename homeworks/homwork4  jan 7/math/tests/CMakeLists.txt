include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(my_lib_test my_lib_test.cpp)

target_link_libraries(my_lib_test
 PRIVATE
  GTest::GTest
  math)

add_test(math_gtests my_lib_test)
