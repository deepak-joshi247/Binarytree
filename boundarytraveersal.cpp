void leftpart(vector<int>& ans,Node* root){
    if(root==NULL){
        return;
    }
    //exception child node
    if(root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left)  leftpart(ans,root->left);
    else    leftpart(ans,root->right);
}
void childpart(vector<int>& ans,Node* root){
    if(root==NULL)  return;
    if(root->left == NULL && root->right == NULL)   ans.push_back(root->data);
    childpart(ans,root->left);
    childpart(ans,root->right);
}
void rightpart(vector<int>& ans,Node* root){
    if(root==NULL)  return;
    //exception child node
    if(root->left==NULL && root->right==NULL)   return ;
    ans.push_back(root->data);
    if(root->right)  rightpart(ans,root->right);
    else    rightpart(ans,root->left);
}
void putin_ans(vector<int>&temp,vector<int>&ans){
    for(int i=0;i<temp.size();i++){
        int val = temp[i];
        ans.push_back(val);
    }
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!root)    return ans;
        if(root->left!=NULL || root->right!=NULL)   ans.push_back(root->data);
        //left part except child node
        leftpart(ans,root->left);
        //child part 
        childpart(ans,root);
        //right part except child node
        vector<int> temp;
        rightpart(temp,root->right);
        reverse(temp.begin(),temp.end());
        putin_ans(temp,ans);
        return ans;
    }
};
