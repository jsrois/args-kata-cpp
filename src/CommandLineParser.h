//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_COMMANDLINEPARSER_H
#define ARGS_KATA_COMMANDLINEPARSER_H

#include <string>
#include "Schema.h"
#include "OptionSet.h"
#include "InputSplitter.h"

class CommandLineParser {

 public:
  CommandLineParser();
  CommandLineParser(InputSplitter * splitter, OptionSet * optionSet);
  void addSchema(Schema schema);
  void parse(int argc, const char **argv);
  bool getFlag(const std::string& name) const;
  std::string getParameter(const std::string& name) const;
 protected:
  OptionSet *optionSet;
  InputSplitter *splitter;
};

#endif //ARGS_KATA_COMMANDLINEPARSER_H
