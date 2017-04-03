//
// Created by jsanchez on 3/04/17.
//

#include <catch/catch.hpp>
#include <fakeit/fakeit.hpp>
#include <CommandLineParser.h>
using namespace fakeit;
using namespace std::string_literals;

TEST_CASE("CommandLineParser","[unit]") {
  Mock<InputSplitter> splitterMock;
  When(Method(splitterMock,split)).AlwaysReturn({
    {"v"},
    {"input-file","input.pdf"}
  });
  Mock<OptionSet> fakeOptionSet;
  Fake(Method(fakeOptionSet,add));
  Fake(Method(fakeOptionSet,setFlag));Fake(Method(fakeOptionSet,setParameter));
  When(Method(fakeOptionSet,getFlag).Using("verbose")).AlwaysReturn(true);
  When(Method(fakeOptionSet,getParameter).Using("input-file")).AlwaysReturn("input.pdf");

  CommandLineParser parser(&(splitterMock.get()),&(fakeOptionSet.get()));
  Rule
      verboseRule={"v", "verbose", false, "Displays messages during processing"},
      inputRule={"i", "input-file", "Input File to be processed"};

  Schema schema = {verboseRule,inputRule};

  const char * m_argv[] = {"./myApp","-v","--input-file=input.pdf"};
  const char ** argv = m_argv; int argc = 3; // C sucks, be careful when changing this number

  parser.addSchema(schema);

  Verify(Method(fakeOptionSet,add).Using(verboseRule)).Once();
  Verify(Method(fakeOptionSet,add).Using(inputRule)).Once();

  parser.parse(argc,argv);

  Verify(Method(splitterMock,split)
             .Using(/*std::vector*/{"./myApp","-v","--input-file=input.pdf"}))
      .Once();

  Verify(Method(fakeOptionSet,setFlag).Using("v"));
  Verify(Method(fakeOptionSet,setParameter).Using("input-file","input.pdf"));

  CHECK(parser.getFlag("verbose"));
  CHECK(parser.getParameter("input-file") == "input.pdf"s);
}

