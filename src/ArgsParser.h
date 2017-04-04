//
// Created by jsanchez on 4/04/17.
//

#ifndef ARGS_KATA_ARGSPARSER_H
#define ARGS_KATA_ARGSPARSER_H

#include <string>
#include <vector>
#include "Schema.h"

typedef std::string String;
typedef std::vector<String> StringVector;

class ArgsParser {
 public:
  void setSchema(Schema schema);
  void parse(int argc, const char **argv);
  template <typename ReturnType>
      ReturnType get(String name) {
    return ReturnType();
  }
  bool get(String name) {
    return get<bool>(name);
  }
};

#endif //ARGS_KATA_ARGSPARSER_H
