//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_OPTIONSSET_H
#define ARGS_KATA_OPTIONSSET_H

#include "Schema.h"
class OptionSet {
 public:
  virtual void add(Rule);
  virtual void setFlag(std::string name);
  virtual void setParameter(std::string name, std::string value);
};

#endif //ARGS_KATA_OPTIONSSET_H
