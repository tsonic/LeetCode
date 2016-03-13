//Given preorder and inorder traversal of a tree, construct the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// scan preorder vector, and use the inorder vector to determine left or right child.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderHash;
        //use hashtable to quickly look up to compare the relative location (to the left or to the right) of two nodes 
        for (int i=0;i<inorder.size();i++)    {
            inorderHash[inorder[i]]=i;
        }
        
        if (preorder.empty()) return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if (preorder.size()==1) return root;
        
        TreeNode* current=root;
        TreeNode* prev;
        
        stack<TreeNode*> st;

        for (int i=1;i<preorder.size();i++)  {
            st.push(current);
            //if the next element in inorder is to the left of preorder, that means it is current node's left child.
            if (inorderHash[preorder[i]]<inorderHash[current->val]) {
                current->left=new TreeNode(preorder[i]);
                current=current->left;
            }
            else    {
                current=st.top();
                //chase all the way back the stack to see where the preorder[i] appear to the left of the nodes in the stack, its previous node is the location to insert the right child.
                do  {
                    prev=current;
                    st.pop();
                    // if stack is empty, no need to advance the current node, the prev node is the root of the tree
                    if (!st.empty())
                        current=st.top();
                } while (inorderHash[preorder[i]]>inorderHash[current->val] && !st.empty());
                
                prev->right=new TreeNode(preorder[i]);
                current=prev->right;

            }

        }
        return root;
    }
};
