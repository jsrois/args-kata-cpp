//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_OPTIONSSET_H
#define ARGS_KATA_OPTIONSSET_H

#include "Schema.h"
class OptionSet {
 public:
  virtual void add(Rule) = 0;
  virtual void setFlag(std::string name) = 0;
  virtual void setParameter(std::string name, std::string value) = 0;
};

#endif //ARGS_KATA_OPTIONSSET_H
