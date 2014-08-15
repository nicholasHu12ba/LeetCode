/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    Binary Tree Level Order Traversal II
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_107
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
  [15,7]
  [9,20],
  [3],
 ]
 
 Solution: Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> root2leaf;
        queue<TreeNode *> q;
        if (!root) return root2leaf;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (node)
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else
            {
                root2leaf.push_back(level);
                level.clear();
                if (q.empty()) break;    // CAUTIOUS! infinite loop
                q.push(NULL);
            }
        }
    	// reverse
        reverse(root2leaf.begin(), root2leaf.end());
        return root2leaf;
    }
	
	vector<vector<int>> res;
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		res.clear();
		if (!root) return res;
		return levelOrderBottom_1(root);
	}

	// mine: queue+stack
	vector<vector<int> > levelOrderBottom_1(TreeNode *root) {
		queue<TreeNode*> q;
		q.push(NULL); q.push(root);
		stack<TreeNode*> stk;
		stk.push(NULL); stk.push(root);
		while (true) {
			TreeNode* node = q.front(); q.pop();
			if (!node) {
				if (q.empty()) break;
				stk.push(NULL);
				q.push(NULL);
			}
			else {
				if (node->right) {
					stk.push(node->right); q.push(node->right);
				}
				if (node->left) {
					stk.push(node->left); q.push(node->left);
				}
			}
		}
		stk.pop();
		vector<int> level;
		while (!stk.empty()) {
			TreeNode* node = stk.top(); stk.pop();
			if (!node) {
				res.push_back(level); level.clear();
			}
			else 
				level.push_back(node->val);
		}
		return res;
	}
};