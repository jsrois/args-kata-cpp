//
// Created by Javi on 8/4/17.
//

#include <catch/catch.hpp>
#include <fakeit/fakeit.hpp>
#include <ArgParser.h>
#include <OptionSet.h>
#include <Splitter.h>
using namespace fakeit;
using namespace std::string_literals;

template <class T>
T* ptrFrom(Mock<T> &mock) {
    return &(mock.get());
}

TEST_CASE("ArgParser", "[unit]") {
     SECTION("registers parameter values according to schema") {
        Mock<Splitter> splitterStub;
        When(Method(splitterStub,getParameterValuesFrom))
                .Return({
                                {"-v", true},
                                {"-a", 3.4f},
                                {"-n", 2000}
                        });

        Mock<OptionSet> optionSetMock;
        Fake(Method(optionSetMock,initializeFrom));

        ArgParser parser(ptrFrom(splitterStub), ptrFrom(optionSetMock));
        Schema schema = {
                {"-v", "Activates verbosity"},
                {"-n", "Number of meatballs (default 20)",20},
                {"-a", "Alfa parameter (default 1.3f)", 3.2f},
                {"-e", "Enables stupidity"}
        };

        parser.addSchema(schema);

        Verify(Method(optionSetMock,initializeFrom).Using(schema)).Once();

        string commandLineArgs = "./myApp -v -a 3.4 -n 2000"s;
        parser.parse(commandLineArgs);

        Verify(Method(splitterStub, getParameterValuesFrom)
                       .Using(commandLineArgs)).Once();


        CHECK(parser.get<int>("-n") == 2000);
        CHECK(parser.get<float>("-a") == 3.4f);
        CHECK(parser.get<bool>("-v"));
        CHECK_FALSE(parser.get<bool>("-e"));
    }
}