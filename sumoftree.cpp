int sumoftree(Node* root,bool& issum){
    if(issum == false){
        return 0;
    }
    if(root==NULL){
        return 0;
    }
    int left = sumoftree(root->left,issum);
    int right = sumoftree(root->right,issum);
    int ans = left+right;
    if(ans != root->data && ans!= 0){
        issum = false;
    }
    return root->data+left+right;
}
class Solution {
  public:
    bool isSumTree(Node* root) {
        bool issum = true;
        sumoftree(root,issum);
        return issum;
    }
};
