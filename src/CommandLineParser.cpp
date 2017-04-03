//
// Created by jsanchez on 3/04/17.
//

#include <array>
#include "CommandLineParser.h"
void CommandLineParser::addSchema(Schema schema) {
  for (auto rule : schema) {
    optionSet->add(rule);
  }
}
void CommandLineParser::parse(int argc, const char **argv) {
  std::vector<std::string> tokens(argv,argv+argc);
  
  auto segments = splitter->split(tokens);
  
  for (std::vector<std::string> segment : segments) {
    std::string name = segment.at(0);
    if (segment.size() == 2) {
      optionSet->setParameter(name, segment.at(1));
    }    
    else {
      optionSet->setFlag(name);
    }
      
  }
  
}
bool CommandLineParser::getFlag(const std::string &name) const {
  return optionSet->getFlag(name);
}
std::string CommandLineParser::getParameter(const std::string &name) const {
  return optionSet->getParameter(name);
}

// production constructor
CommandLineParser::CommandLineParser() :
  CommandLineParser(new InputSplitter,new OptionSet) {}

CommandLineParser::CommandLineParser(InputSplitter* splitter, OptionSet* optionSet) {
  // TODO fix this crap or Acceptance tests will crash
  this->splitter = splitter;
  this->optionSet = optionSet;
}
