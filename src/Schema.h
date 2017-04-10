//
// Created by jsanchez on 4/04/17.
//

#ifndef ARGS_KATA_SCHEMA_H
#define ARGS_KATA_SCHEMA_H

class ArgSpec {
 public:
  ArgSpec(std::string name, std::string info);
  ArgSpec(std::string name, std::string info, int value);
  ArgSpec(std::string name, std::string info, std::string value);
};

class Schema {
 public:
  Schema(std::vector<ArgSpec>);
};

#endif //ARGS_KATA_SCHEMA_H
