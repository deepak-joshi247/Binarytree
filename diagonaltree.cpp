// there was some mistake while assigning when using bsf so used recursion onw
class Solution {
    void orderit(map<int,vector<int>>&m,Node* root,int hd){
        if(root==NULL){
            return ;
        }
        m[hd].push_back(root->data);
        orderit(m,root->left,hd+1);
        orderit(m,root->right,hd);
    }
  public:
    vector<int> diagonal(Node *root) {
        map<int,vector<int>> m;        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        int hd = 0;
        orderit(m,root,hd);
        for(auto i:m){
            for(auto j:i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
