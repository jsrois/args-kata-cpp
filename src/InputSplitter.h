//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_INPUTSPLITTER_H
#define ARGS_KATA_INPUTSPLITTER_H

#include <string>
#include <vector>
class InputSplitter {
 public:
  virtual std::vector<std::vector<std::string>>
    split(std::vector<std::string> input);

};

#endif //ARGS_KATA_INPUTSPLITTER_H
