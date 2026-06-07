// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>

#include <vector>

#include "tree.h"

static void dfs(PMTree::Node* node,
                std::vector<char>& path,
                std::vector<std::vector<char>>& result) {
  if (!node)
    return;

  if (node->value != '\0')
    path.push_back(node->value);

  if (node->children.empty()) {
    if (!path.empty())
      result.push_back(path);
  } else {
    for (PMTree::Node* child : node->children)
      dfs(child, path, result);
  }

  if (node->value != '\0')
    path.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> result;
  std::vector<char> path;

  dfs(tree.getRoot(), path, result);

  return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  std::vector<std::vector<char>> perms = getAllPerms(tree);

  if (num < 1 || num > static_cast<int>(perms.size()))
    return {};

  return perms[num - 1];
}

static long long factorial(int n) {
  long long r = 1;

  for (int i = 2; i <= n; i++)
    r *= i;

  return r;
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  std::vector<char> symbols = tree.getAlphabet();

  int n = static_cast<int>(symbols.size());

  long long total = factorial(n);

  if (num < 1 || num > total)
    return {};

  num--;

  std::vector<char> result;

  for (int pos = n; pos >= 1; pos--) {
    long long block = factorial(pos - 1);

    int index = static_cast<int>(num / block);

    result.push_back(symbols[index]);

    symbols.erase(symbols.begin() + index);

    num %= block;
  }

  return result;
}
