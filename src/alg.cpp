// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <vector>

#include "tree.h"

static void genPerms(std::vector<char> current,
                     std::vector<char> remaining,
                     std::vector<std::vector<char>>* result) {
  if (remaining.empty()) {
    result->push_back(current);
    return;
  }

  for (size_t i = 0; i < remaining.size(); i++) {
    std::vector<char> nextCurrent = current;
    nextCurrent.push_back(remaining[i]);

    std::vector<char> nextRemain = remaining;
    nextRemain.erase(nextRemain.begin() + i);

    genPerms(nextCurrent, nextRemain, result);
  }
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> result;

  genPerms({}, tree.getAlphabet(), &result);

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
