# CMake generated Testfile for 
# Source directory: /Users/vahealeksanyan/Downloads/aca-main/math/tests
# Build directory: /Users/vahealeksanyan/Downloads/aca-main/math/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(math_gtests "my_lib_test")
set_tests_properties(math_gtests PROPERTIES  _BACKTRACE_TRIPLES "/Users/vahealeksanyan/Downloads/aca-main/math/tests/CMakeLists.txt;19;add_test;/Users/vahealeksanyan/Downloads/aca-main/math/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
