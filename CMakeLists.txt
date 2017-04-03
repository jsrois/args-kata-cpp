cmake_minimum_required(VERSION 3.7)
project(args_kata)

set(CMAKE_CXX_STANDARD 14)

set(source_files
        src/CommandLineParser.cpp src/CommandLineParser.h src/Schema.cpp src/Schema.h
        src/InputSplitter.cpp
        src/InputSplitter.h
        src/OptionSet.cpp
        src/OptionSet.h)

set(test_files
        test/main.test.cpp test/args.test.cpp test/cli.test.cpp)

add_executable(unit_tests
        ${source_files}
        ${test_files})

target_include_directories(unit_tests PRIVATE
        src
        test)