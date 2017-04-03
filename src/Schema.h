//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_SCHEMA_H
#define ARGS_KATA_SCHEMA_H

#include <string>
#include <vector>
struct Rule {
  Rule(std::string abbrev,std::string name, bool defaultValue, std::string info);
  Rule(std::string abbrev,std::string name, std::string info);
  std::string abbrev, name, info;
  bool defaultValue;
  bool operator==(const Rule&lhs) const;
};

typedef std::vector<Rule> Schema;



#endif //ARGS_KATA_SCHEMA_H
