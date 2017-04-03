//
// Created by Javi on 3/4/17.
//


#include <catch/catch.hpp>
#include <OptionSet.h>

TEST_CASE("OptionSet","[unit]") {
    OptionSet optionSet;
    Option verboseRule = {"v", "verbose", false, "Displays messages during processing"},
            inputRule={"i", "input-file", "Input File to be processed"};

    SECTION("Stores default flag values") {
        optionSet.add({"p","positive",true,"A positive default flag"});
        CHECK(optionSet.getFlag("positive"));
    }
}
