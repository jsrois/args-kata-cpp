//
// Created by Javi on 9/4/17.
//

#include <catch/catch.hpp>

SCENARIO("ArgsParser takes parameters from command line according to a schema") {
    ArgParser argParser;
    GIVEN("a schema of arguments with their names and default values") {
        Schema schema = {
                {"-v","Activates verbosity"},
                {"-n","Number of wheels (default: 4)", 4},
                {"-g","Gravity Factor (default: 1.0)", 1.0f}
        };
        argParser.setSchema(schema);
    }
    WHEN("we pass the command line arguments") {
        struct {
            int argc = 4;
            const char * args[argc] = {"./myApp","-v","-g","1.2"};
            const char ** argv = &args[0];
        } cli;
        argParser.parse(cli.argc, cli.argv);
    }
    THEN("we can get the value of each parameter") {
        CHECK(argParser.get("-v") == true);
        CHECK(argParser.get("-n") == 4);
        CHECK(argParser.get("-g") == 1.2f);
    }
}