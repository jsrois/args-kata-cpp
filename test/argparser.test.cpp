//
// Created by Javi on 8/4/17.
//

#include <catch/catch.hpp>
#include <fakeit/fakeit.hpp>
#include <ArgParser.h>

using namespace fakeit;
using namespace std::string_literals;

template <class T>
T* ptrFrom(Mock<T> &mock) {
    return &(mock.get());
}

TEST_CASE("ArgParser", "[unit]") {
    SECTION("registers parameter values according to schema") {
        ParameterValueMap parameterValues = {
                {"-v", true},
                {"-a", 3.4f},
                {"-n", 2000}
        };
        Mock<Splitter> splitterStub;Fake(Dtor(splitterStub));
        When(Method(splitterStub, getParameterValuesFrom))
                .Return(parameterValues);

        Mock<OptionSet> optionSetMock;Fake(Dtor(optionSetMock));
        Fake(Method(optionSetMock,initializeFrom));
        Fake(Method(optionSetMock,updateParameters));
        When(Method(optionSetMock,get).Using("-n")).Return(2000);
        When(Method(optionSetMock,get).Using("-a")).Return(3.4f);
        When(Method(optionSetMock,get).Using("-v")).Return(true);
        When(Method(optionSetMock,get).Using("-e")).Return(false);


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

        Verify(Method(splitterStub, getParameterValuesFrom).Using(commandLineArgs)).Once();
        Verify(Method(optionSetMock, updateParameters).Using(parameterValues)).Once();


        CHECK(parser.get("-n") == 2000);
        CHECK(parser.get("-a") == 3.4f);
        CHECK(parser.get("-v") == true);
        CHECK(parser.get("-e") == false);
    }
}