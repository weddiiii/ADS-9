// Copyright 2022 NNTU-CS

#include <iostream>
#include <vector>

#include "tree.h"

int main() {
  PMTree tree(std::vector<char>{'1', '2', '3', '4'});

  std::vector<std::vector<char>> perms = getAllPerms(tree);

  std::cout << "Count = " << perms.size() << std::endl;

  std::vector<char> p1 = getPerm1(tree, 1);

  for (char c : p1)
    std::cout << c;

  std::cout << std::endl;

  std::vector<char> p2 = getPerm2(tree, 2);

  for (char c : p2)
    std::cout << c;

  std::cout << std::endl;

  return 0;
}
