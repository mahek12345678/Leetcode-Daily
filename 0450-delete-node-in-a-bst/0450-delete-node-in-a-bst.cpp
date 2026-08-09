class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Case 1: no left child
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: no right child
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: two children
            TreeNode* temp = root->right;

            // Find smallest node in right subtree
            while(temp->left != NULL){
                temp = temp->left;
            }

            // Copy successor value
            root->val = temp->val;

            // Delete duplicate successor
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};