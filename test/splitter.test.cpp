//
// Created by jsanchez on 3/04/17.
//

#include <catch/catch.hpp>
#include <InputSplitter.h>
using namespace std::string_literals;
using namespace Catch::Matchers;

TEST_CASE("Splitter","[unit]") {
  InputSplitter splitter;

  SECTION("separates flags and parameters from input text") {
    auto segments = splitter.split({"./myApp", "-v", "--input-file=input.pdf"});
    CHECK_THAT(segments, Equals(decltype(segments){{"v"},{"input-file","input.pdf"}}));
    segments = splitter.split({"./myApp", "--verbose", "--input-file=input.pdf"});
    CHECK_THAT(segments, Contains(decltype(segments){{"verbose"},{"input-file","input.pdf"}}));
//    segments = splitter.split({"./myApp", "--verbose", "-input-file","input.pdf"});
//    CHECK_THAT(segments, Contains(decltype(segments){{"verbose"},{"input-file","input.pdf"}}));
//    segments = splitter.split({"./myApp", "-v", "-input-file","input.pdf"});
//    CHECK_THAT(segments, Contains(decltype(segments){{"v"},{"input-file","input.pdf"}}));
//    segments = splitter.split({"./myApp", "--input-file=input.pdf", "-v"});
//    CHECK_THAT(segments, Contains(decltype(segments){{"v"},{"input-file","input.pdf"}}));
  }
}