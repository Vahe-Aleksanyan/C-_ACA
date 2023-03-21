//
// Created by Vahe Aleksanyan on 21.03.23.
//
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:


    // 94. Binary Tree Inorder Traversal
    vector<int> ans;

    void dfs(TreeNode *node) {
        if (!node)
            return;
        dfs(node->left);
        ans.push_back(node->val);
        dfs(node->right);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }


    // 144. Binary Tree Preorder Traversal
    void preorderfun(vector<int> &preorder, TreeNode *root) {
        if (root == NULL) { return; }
        preorder.push_back(root->val);
        preorderfun(preorder, root->left);
        preorderfun(preorder, root->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        preorderfun(preorder, root);
        return preorder;
    }


//    145. Binary Tree Postorder Traversal

    vector<int> v;

    void postorder(TreeNode *root) {
        if (root == nullptr) { return; }
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        postorder(root);
        return v;
    }


//    226. Invert Binary Tree
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) return NULL;
        // swap(invertTree(root->left), invertTree(root->right));
        invertTree(root->left); //calling the left subtree
        invertTree(root->right); //calling the right subtree
        TreeNode *temp = root->left; //swap both
        root->left = root->right;
        root->right = temp;
        return root;
    }

    // 112. Path Sum
    bool solve(TreeNode *root, int targetSum, int &curr) {
        if (root == NULL) return false;
        curr += root->val;
        if (curr == targetSum && root->left == NULL && root->right == NULL) return true;

        bool left = solve(root->left, targetSum, curr);
        bool right = solve(root->right, targetSum, curr);
        curr -= root->val;

        return left || right;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == NULL) return false;
        int cr = 0;
        bool ans = solve(root, targetSum, cr);
        return ans;
    }


//    110. Balanced Binary Tree
    bool answer = true;

    int solve(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if (abs(left - right) > 1)
            answer = false;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root) {
        solve(root);
        return answer;
    }


    //98. Validate Binary Search Tree
    void helper(TreeNode *root, vector<int> &ans) {
        if (root == NULL) return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);

    }

    bool isValidBST(TreeNode *root) {
        vector<int> ans;
        helper(root, ans);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1]) return false;
        }
        return true;
    }

    // 108. Convert Sorted Array to Binary Search Tree

    TreeNode *chk(vector<int> &nums, int i, int j) {
        if (i > j) { return NULL; }
        int pos = (i + j) / 2;
        TreeNode *root = new TreeNode(nums[pos]);
        root->left = chk(nums, i, pos - 1);
        root->right = chk(nums, pos + 1, j);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return chk(nums, 0, nums.size() - 1);
    }

//    102. Binary Tree Level Order Traversal

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while (sz--) {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)q.push(f->left);
                if (f->right)q.push(f->right);

            }
            ans.push_back(v);
        }
        return ans;
    }

//    116. Populating Next Right Pointers in Each Node
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node *_left, Node *_right, Node *_next)
                : val(_val), left(_left), right(_right), next(_next) {}
    };

    Node *connect(Node *root) {
        if (!root) return nullptr;
        queue<Node *> q;
        q.push(root);
        while (q.size()) {
            Node *rightNode = nullptr;
            for (int i = q.size(); i; i--) {
                auto cur = q.front();
                q.pop();
                cur->next = rightNode;
                rightNode = cur;
                if (cur->right)
                    q.push(cur->right),
                            q.push(cur->left);
            }
        }
        return root;
    }

    // 117. Populating Next Right Pointers in Each Node II
    Node* connect2(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                q.pop();
                if(i==n-1){
                    curr->next=NULL;
                }else{
                    curr->next=q.front();
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return root;

    }
};

