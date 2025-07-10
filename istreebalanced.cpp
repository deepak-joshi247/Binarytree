int height(Node* root,bool& balanced){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left,balanced);
    int right = height(root->right,balanced);
    if((left-right)>1 || (left - right)<-1){
        balanced = false;
    }
    return max(left,right)+1;
}
class Solution {
  public:
    bool isBalanced(Node* root) {
       bool balanced = true;
       int ans = height(root,balanced);
       return balanced;
    }
};
