class Solution {
    void nodessum(Node* root,pair<int,int>m,pair<int,int> &endnode){
        if(root==NULL){
            return ;
        }
        m.second = m.second + root->data;
        if(root->left == NULL && root->right == NULL){
            if(endnode.first < m.first){
                endnode.first = m.first;
                endnode.second = m.second;
            }
            if(endnode.first == m.first){
                endnode.second = max(endnode.second,m.second);
            }
        }
        m.first+=1;
        nodessum(root->left,m,endnode);
        nodessum(root->right,m,endnode);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        pair<int,int> m = {0,0};
        pair<int,int> endnode = {0,0};
        nodessum(root,m,endnode);
        int largestnode = endnode.second;
        return largestnode;
        
    }
};
