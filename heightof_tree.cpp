class Solution {
  public:
    int height(Node* node) {
        Node* root = node;
        //base case 
        if(node == NULL){
            return -1; // since asked from root and including root so -1 instead of 0
        }
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right)+1;
        
        return ans;
    }
};
