//
// Created by jsanchez on 3/04/17.
//

#include "CommandLineParser.h"
void CommandLineParser::addSchema(Schema schema) {
  for (auto rule : schema) {
    optionSet->add(rule);
  }
}
void CommandLineParser::parse(int argc, const char **argv) {

}
bool CommandLineParser::getFlag(const std::string &name) const {
  return false;
}
std::string CommandLineParser::getParameter(const std::string &name) const {
  return std::string();
}

CommandLineParser::CommandLineParser(InputSplitter* splitter, OptionSet* optionSet) {
  // TODO fix this crap or Acceptance tests will crash
  this->splitter = splitter;
  this->optionSet = optionSet;
}
CommandLineParser::CommandLineParser() {

}
