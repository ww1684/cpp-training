# CMake generated Testfile for 
# Source directory: C:/workspace/cpp-training/tests
# Build directory: C:/workspace/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(training_main "C:/workspace/build/tests/training_main.exe")
set_tests_properties(training_main PROPERTIES  _BACKTRACE_TRIPLES "C:/workspace/cpp-training/tests/CMakeLists.txt;8;ADD_TEST;C:/workspace/cpp-training/tests/CMakeLists.txt;0;")
subdirs("googletest")
