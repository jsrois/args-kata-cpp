//
// Created by jsanchez on 3/04/17.
//

#include <catch/catch.hpp>
#include <CommandLineParser.h>
using namespace std::string_literals;

SCENARIO("the specified flags and parameters should be parsed from CLI","[acceptance]") {
  CommandLineParser parser;
  GIVEN("that a schema is provided") {
    parser.addSchema({
                         {"v","verbose",false,"Displays messages during processing"},
                         {"i","input-file","Input File to be processed"}
                     });
  }
  WHEN("we parse the command line input") {
    const char * m_argv[] = {"./myApp","-v","--input-file=input.pdf"};
    const char ** argv = m_argv;
    int argc = 3; // C sucks, be careful when changing this number
    parser.parse(argc,argv);
  }
  THEN("we should be able to retrieve the provided configuration") {
    CHECK(parser.getFlag("verbose"));
    CHECK(parser.getParameter("input-file") == "input.pdf"s);
  }
}