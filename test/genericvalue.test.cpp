//
// Created by Javi on 8/4/17.
//

#include <catch/catch.hpp>
#include <GenericValue.h>

TEST_CASE("GenericValue","[unit]") {
    SECTION("can compare to other generic values") {
        CHECK(GenericValue(42) == GenericValue(42));
        CHECK(GenericValue(42) != GenericValue(43));
        CHECK(GenericValue(3.2f) != GenericValue(42));
    }
}