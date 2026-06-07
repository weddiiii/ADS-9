// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class PMTree {
 private:
  std::vector<char> alphabet;

 public:
  explicit PMTree(const std::vector<char>& data) : alphabet(data) {}

  std::vector<char> getAlphabet() const {
    return alphabet;
  }
};

std::vector<std::vector<char>> setAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
