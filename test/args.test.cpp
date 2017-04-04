//
// Created by jsanchez on 4/04/17.
//

// "Once the schema has been specified, the program should pass the actual argument list to
// the args parser. It will verify that the arguments match the schema. The program can
// then ask the args parser for each of the values, using the names of the flags. The values
// are returned with the correct types, as specified in the schema."
// e.g. "-l -p 9300 -d /home/jsrois/logs -g this,is,a,list -d 1,2,-3,5"

#include <catch/catch.hpp>
SCENARIO("Arg Parser stores and updates the program arguments according to the schema") {
  ArgsParser argsParser;

  GIVEN("that we have specified a schema") {
    Schema schema = {
        {"l","Activates logs"},
        {"p","Port number",8080},
        {"-d","Destination folder","/var/log"}
        // we skip the list arguments for now
    };
    argsParser.setSchema(schema);
  }

  WHEN("we pass the actual argument list to the args parser") {
    struct {
      int argc = 9; // C sucks, be careful when changing this number
      const char *m_argv[9] =
          {"-l", "-p", "9300", "-d", "/home/jsrois/logs", "-g","this,is,a,list","-d","1,2,-3,5"};
      const char **argv = m_argv;
    } goodInput;

    argsParser.parse(argc,argv);
  }
  using namespace Catch::Matchers;
  THEN("we can ask the args parser for each of the flag values, using their names"){
    CHECK(argsParser.get("-l"));
    CHECK(argsParser.get<int>("-p") == 9300);
    CHECK_THAT(argsParser.get<String>("-d"),Equals("/home/jsrois/logs"));
    CHECK_THAT(argsParser.get<StringVector>("-g"),Equals({"this","is","a","list"}));
    CHECK_THAT(argsParser.get<std::vector<int>>("-d"),Equals({1,2,3,4,5}));
  }


}