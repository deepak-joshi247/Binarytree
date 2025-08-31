class Solution {
    
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* predecessor = NULL;
        Node* current = root;
        while(current!=NULL){
            if(current->left == NULL){
                ans.push_back(current->data);
                current = current->right;
            }
            else{
                /* using recursion or loops in a function to find 
                    predecessor was giving TLE
                */
                Node* predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if(predecessor->right == NULL){
                    predecessor->right = current;
                    current = current->left;
                }
                else{
                    predecessor->right = NULL;
                    ans.push_back(current->data);
                    current = current->right;
                }
            }
        }
        return ans;
    }
};
