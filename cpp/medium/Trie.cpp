#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
  Trie() : end(false), childs(26, nullptr) {}

  void insert(string word) {
    Trie *cur = this;
    for (int i = 0; i < word.size(); ++i) {
      vector<Trie *> &temp = cur->childs;
      char c = word[i];
      if (temp[c - 'a'] == nullptr) {
        Trie *newnode = new Trie();
        temp[c - 'a'] = newnode;
      }
      if (i == word.size() - 1)
        temp[c - 'a']->end = true;
      cur = temp[c - 'a'];
    }
  }

  bool search(string word) {
    Trie *travel = this;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      if (travel && travel->childs[c - 'a']) {
        if (i == word.size() - 1 && travel->childs[c - 'a']->end == false)
          return false;
        travel = travel->childs[c - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }

  bool startsWith(string prefix) {
    Trie *travel = this;
    for (int i = 0; i < prefix.size(); ++i) {
      char c = prefix[i];
      if (travel && travel->childs[c - 'a']) {
        travel = travel->childs[c - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }

private:
  bool end;
  vector<Trie *> childs;
};

int main() {
  Trie *root = new Trie();
  root->insert("apple");
  cout << root->search("apple");
  return 0;
}
