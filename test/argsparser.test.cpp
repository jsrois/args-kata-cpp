//
// Created by jsanchez on 4/04/17.
//

#include <catch/catch.hpp>
#include <fakeit/fakeit.hpp>
#include <ArgsParser.h>
using namespace fakeit;
using namespace Catch::Matchers;

TEST_CASE("ArgsParser","[unit]") {
  struct {
    int argc = 5; // C sucks, be careful when changing this number
    const char *m_argv[5] =
        {"-l", "-p", "9300", "-d", "/home/jsrois/logs"};
    const char **argv = m_argv;
  } input;

  Mock<Splitter> splitter;
  Mock<OptionSet> optionSet;
  ArgsParser argsParser(&(splitter.get()),&(optionSet.get()));

  Schema schema({
                    {"-l","Activates logs"},
                    {"-p","Port number",8080},
                    {"-d","Destination folder","/var/log"}
                });

  argsParser.setSchema(schema);



  argsParser.parse(input.argc,input.argv);
  CHECK(argsParser.get("-l"s));
  CHECK(argsParser.get<int>("-p"s) == 9300);
  CHECK_THAT(argsParser.get<String>("-d"s),Equals("/home/jsrois/logs"s));
}