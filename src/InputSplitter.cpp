//
// Created by jsanchez on 3/04/17.
//

#include "InputSplitter.h"
#include <algorithm>
using namespace std;

vector<vector<string>> InputSplitter::split(vector<string> tokens) {
  vector<vector<string>> segments;
  for (const string token : tokens) {
    string dashes = "--"s;
    if (equal(dashes.begin(),dashes.end(),token.begin())) {
      // remove prefix from string c++
      string name, value;
      name = token.substr(2);
      auto equalsPos = name.find_first_of("=");
      value = name.substr(equalsPos+1);
      name = name.substr(0,equalsPos);
      segments.push_back({name,value});
    } else if (equal(dashes.begin(),dashes.begin(),token.begin())) {
      auto name = token.substr(1); // remove leading dash
      segments.push_back({name});
    }
  }
  return segments;
}
