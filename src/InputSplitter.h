//
// Created by jsanchez on 3/04/17.
//

#ifndef ARGS_KATA_INPUTSPLITTER_H
#define ARGS_KATA_INPUTSPLITTER_H


#include <string>
#include <vector>
using namespace std::string_literals;
static const std::string DOUBLE_DASH = "--"s;
static const std::string DASH = "-"s;

class InputSplitter {
 public:
  virtual std::vector<std::vector<std::string>>
    split(std::vector<std::string> input);

  bool startsWithDoubleDash(const std::string &token) const;
  bool startsWithDash(const std::string &token) const;

  std::vector<std::string> splitByEquals(std::string input) const;

  std::vector<std::string> currentSegment;
  std::vector<std::vector<std::string>> segments;

    void flushCurrentSegment();

    void removeLeadingDashes(std::string &token);
};

#endif //ARGS_KATA_INPUTSPLITTER_H
