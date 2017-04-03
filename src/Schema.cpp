//
// Created by jsanchez on 3/04/17.
//

#include "Schema.h"
Option::Option(std::string abbrev, std::string name, bool defaultValue, std::string info) :
  Option(abbrev,name,info) {
  this->defaultValue = defaultValue;
}

Option::Option(std::string abbrev, std::string name, std::string info)
{
  this->abbrev = abbrev;
  this->name = name;
  this->info = info;
}
bool Option::operator==(const Option &lhs) const {
  // more than enough
  return (lhs.abbrev == abbrev && lhs.name == name);
}
