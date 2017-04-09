//
// Created by Javi on 8/4/17.
//

#include <catch/catch.hpp>
#include <OptionSet.h>

TEST_CASE("OptionSet","[unit]") {
    Schema schema = {
            {"-v", "Activates verbosity"},
            {"-n", "Number of meatballs (default 20)",20},
            {"-a", "Alfa parameter (default 1.3f)", 3.2f},
            {"-e", "Enables stupidity"}
    };
    OptionSet optionSet;
    optionSet.initializeFrom(schema);

    SECTION("returns default values... by default") {
        CHECK(optionSet.get("-v") == false);
        CHECK(optionSet.get("-n") == 20);
        CHECK(optionSet.get("-a") == 3.2f);
        CHECK(optionSet.get("-e") == false);
    }

    SECTION("updates parameter values") {
        optionSet.updateParameters({{"-v",true},{"-a",5.2f}});
        CHECK(optionSet.get("-v")==true);
        CHECK(optionSet.get("-a") == 5.2f);
    }

}