//
// Created by jsanchez on 3/04/17.
//

#include "InputSplitter.h"
using namespace std;

vector<vector<string>> InputSplitter::split(vector<string> tokens) {
  for (string token : tokens) {
    if (startsWithDoubleDash(token)) {
      flushCurrentSegment();
      removeLeadingDashes(token);
      auto parts = splitByEquals(token);
      segments.push_back(parts);
    } else if (startsWithDash(token)) {
      flushCurrentSegment();
      removeLeadingDashes(token);
      auto name = token;
      currentSegment.push_back(name);
    }
    else if (!currentSegment.empty()) {
      currentSegment.push_back(token);
      segments.push_back(currentSegment);
      currentSegment.clear();
    }
  }
  flushCurrentSegment();
  return segments;
}

void InputSplitter::removeLeadingDashes(string &token) {
  while (!token.find('-')) { // returns position
    token.erase(0,1);
  }
}

void InputSplitter::flushCurrentSegment() {
  if (!currentSegment.empty()) {
        segments.push_back(currentSegment);
        currentSegment.clear();
      }
}

std::vector<std::string> InputSplitter::splitByEquals(std::string input) const {
  auto equalsPos = input.find_first_of("=");
  vector<string> segment = {input.substr(0,equalsPos)};
  if (equalsPos != string::npos) {
    segment.push_back(input.substr(equalsPos+1));
  }
  return segment;
}

bool InputSplitter::startsWithDash(const string &token) const {
  return equal(DASH.begin(), DASH.end(), token.begin());
}

bool InputSplitter::startsWithDoubleDash(const string &token) const {
  return equal(DOUBLE_DASH.begin(), DOUBLE_DASH.end(), token.begin());
}
