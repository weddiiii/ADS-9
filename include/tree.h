// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

class PMTree {
 public:
  struct Node {
    char value;
    std::vector<Node*> children;

    explicit Node(char v) : value(v) {}
  };

 private:
  Node* root;
  std::vector<char> alphabet;

  void build(Node* parent, const std::vector<char>& remaining) {
    if (remaining.empty())
      return;

    for (size_t i = 0; i < remaining.size(); i++) {
      Node* child = new Node(remaining[i]);
      parent->children.push_back(child);

      std::vector<char> next = remaining;
      next.erase(next.begin() + i);

      build(child, next);
    }
  }

  void clear(Node* node) {
    if (!node)
      return;

    for (Node* child : node->children)
      clear(child);

    delete node;
  }

 public:
  explicit PMTree(const std::vector<char>& data)
      : root(new Node('\0')), alphabet(data) {
    build(root, alphabet);
  }

  ~PMTree() {
    clear(root);
  }

  Node* getRoot() const {
    return root;
  }

  std::vector<char> getAlphabet() const {
    return alphabet;
  }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
