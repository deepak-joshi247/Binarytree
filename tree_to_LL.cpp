class Solution {
  public:
    void flatten(Node *root) {
        Node* predecessor = NULL;
        Node* current = root;
        while(current!=NULL){
            if(current->left==NULL){
                current = current->right;
            }
            else{
                predecessor = current->left;
                while(predecessor->right != NULL ){
                    predecessor = predecessor->right;
                }
                if(predecessor->right==NULL){
                    predecessor->right = current->right;
                    current->right = current->left;
                    current->left = NULL;
                    current = current->right;
                }
            }
        }
        
    }
};
