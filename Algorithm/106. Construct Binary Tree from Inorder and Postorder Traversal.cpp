
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderHash;
        //use hashtable to quickly look up to compare the relative location (to the left or to the right) of two nodes 
        for (int i=0;i<inorder.size();i++)    {
            inorderHash[inorder[i]]=i;
        }
        
        return buildTreeRec(inorderHash,postorder,inorder,0,postorder.size(),0,postorder.size());
    }
    TreeNode* buildTreeRec(unordered_map<int,int> &inorderHash, vector<int>& postorder, vector<int>& inorder,int pstart,int pend,int instart,int inend)  {

        if (pstart==pend ) return NULL;
        TreeNode* root=new TreeNode(postorder[pend-1]);
        int rightSize=inend-inorderHash[postorder[pend-1]];


        root->right=buildTreeRec(inorderHash,postorder,inorder,pend-rightSize,pend-1,inorderHash[postorder[pend-1]]+1,inend);
        root->left=buildTreeRec(inorderHash,postorder,inorder,pstart,pend-rightSize,instart,inorderHash[postorder[pend-1]]);
        return root;
    }
};

//calculate the left subtree size also works.
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderHash;
        //use hashtable to quickly look up to compare the relative location (to the left or to the right) of two nodes 
        for (int i=0;i<inorder.size();i++)    {
            inorderHash[inorder[i]]=i;
        }
        
        return buildTreeRec(inorderHash,postorder,inorder,0,postorder.size(),0,postorder.size());
    }
    TreeNode* buildTreeRec(unordered_map<int,int> &inorderHash, vector<int>& postorder, vector<int>& inorder,int pstart,int pend,int instart,int inend)  {

        if (pstart==pend ) return NULL;
        TreeNode* root=new TreeNode(postorder[pend-1]);
        //int rightSize=inend-inorderHash[postorder[pend-1]];
        int leftSize=inorderHash[postorder[pend-1]]-instart;

        root->left=buildTreeRec(inorderHash,postorder,inorder,pstart,pstart+leftSize,instart,inorderHash[postorder[pend-1]]);
        root->right=buildTreeRec(inorderHash,postorder,inorder,pstart+leftSize,pend-1,inorderHash[postorder[pend-1]]+1,inend);

        return root;
    }
};
