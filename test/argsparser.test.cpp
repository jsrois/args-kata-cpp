//
// Created by Javi on 9/4/17.
//

#include <catch/catch.hpp>
#include <fakeit/fakeit.hpp>
#include <Schema.h>
#include <ArgParser.h>
using namespace fakeit;

TEST_CASE("ArgParser updates each parameter from input according to schema",
            "[unit]") {

    struct {
        int argc = 4;
        const char * args[4] = {"./myApp","-v","-g","1.2"};
        const char ** argv = args;
    } cli;

    Mock<Splitter> splitter;
    When(Method(splitter,getParameterValues)).Return({"-v",true},{"-g",1.2});
    Mock<ParameterSet> parameterSet;
    Fake(Method(parameterSet,initialize));


    ArgParser argParser(&splitter, &parameterSet);

    Schema schema = {
            {"-v","Activates verbosity"},
            {"-n","Number of wheels (default: 4)", 4},
            {"-g","Gravity Factor (default: 1.0)", 1.0f}
    };
    argParser.setSchema(schema);

    Verify(Method(parameterSet,initialize).Using(schema)).Once();

    argParser.parse(cli.argc, cli.argv);
    Verify(Method(splitter,getParameterValues).Using(cli.argc,cli.argv)).Once();
    Verify(Method(parameterSet,set("-v",true)));
    Verify(Method(parameterSet,set("-g",1.2)));



    CHECK(argParser.get("-v") == true);
    CHECK(argParser.get("-n") == 4);
    CHECK(argParser.get("-g") == 1.2f);
}
