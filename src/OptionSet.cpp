//
// Created by jsanchez on 3/04/17.
//

#include "OptionSet.h"
void OptionSet::add(Option rule) {
  options.insert({rule.name,rule});
}

void OptionSet::setFlag(std::string name) {

}

void OptionSet::setParameter(std::string name, std::string value) {

}

bool OptionSet::getFlag(std::string name) const {
  return options.at(name).defaultValue;
}

std::string OptionSet::getParameter(std::string name) const {
  return std::string();
}
