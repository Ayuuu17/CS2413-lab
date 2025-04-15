/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* size){
    int* result = (int*)malloc(100 * sizeof(int));  
    *size = 0;
    inorder(root, result, size);
    return result;
}
