/**
 * Definition for a binary tree node.
 */

#include <queue>
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::queue<TreeNode *> q{};
    std::vector<int> result{};
    if (!root) return result;

    q.push(root);

    while (!q.empty()) {
      auto len = q.size();
      result.push_back(q.front()->val);

      for (auto i{0}; i < len; ++i) {
        const auto current = q.front();
        q.pop();

        if (current->right) {
          q.push(current->right);
        }
        if (current->left) {
          q.push(current->left);
        }
      }
    }

    return result;
  }
};
