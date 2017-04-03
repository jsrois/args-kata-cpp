//
// Created by jsanchez on 3/04/17.
//

#include "Schema.h"
Rule::Rule(std::string abbrev, std::string name, bool defaultValue, std::string info) :
  Rule(abbrev,name,info) {
  this->defaultValue = defaultValue;
}

Rule::Rule(std::string abbrev, std::string name, std::string info)
{
  abbrev = abbrev;
  name = name;
  info = info;
}
bool Rule::operator==(const Rule &lhs) const {
  // more than enough
  return (lhs.abbrev == abbrev && lhs.name == name);
}
