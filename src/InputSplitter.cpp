//
// Created by jsanchez on 3/04/17.
//

#include "InputSplitter.h"
#include <algorithm>
using namespace std;



vector<vector<string>> InputSplitter::split(vector<string> tokens) {
  vector<vector<string>> segments;
  for (string token : tokens) {
    if (startsWithDoubleDash(token)) {
      string name, value;
      token.erase(0,2);
      splitByEquals(token, name, value);
      segments.push_back({name,value});
    } else if (startsWithDash(token)) {
      auto name = token.substr(1); // remove leading dash
      segments.push_back({name});
    }
  }
  return segments;
}

void InputSplitter::splitByEquals(std::string input, std::string& name, std::string& value) const {
  auto equalsPos = input.find_first_of("=");
  value = input.substr(equalsPos+1);
  name = input.substr(0,equalsPos);
}

bool InputSplitter::startsWithDash(const string &token) const {
  return equal(DASH.begin(), DASH.begin(), token.begin());
}

bool InputSplitter::startsWithDoubleDash(const string &token) const {
  return equal(DOUBLE_DASH.begin(), DOUBLE_DASH.end(), token.begin());
}
