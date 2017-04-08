//
// Created by Javi on 8/4/17.
//

#include <catch/catch.hpp>
#include <ArgParser.h>
using namespace std::string_literals;

SCENARIO("Args Parser recognizes and stores parameters according to the schema") {
    ArgParser parser;
    GIVEN("we have set a valid test schema") {
        parser.addSchema({
                                 {"-v", "Activates verbosity"},
                                 {"-n", "Number of meatballs (default 20)",20},
                                 {"-a", "Alfa parameter (default 1.3f)", 3.2f},
                                 {"-e", "Enables stupidity"}
                         });
    }

    WHEN("we parse the command line arguments") {
        parser.parse("./myApp -v -a 3.4 -n 2000"s);
    }
    THEN("we can retrieve each parameter value") {
        CHECK(parser.get("-n") == 2000);
        CHECK(parser.get("-a") == 3.4f);
        CHECK(parser.get("-v") == true);
        CHECK_FALSE(parser.get("-e") == false);
    }
}
