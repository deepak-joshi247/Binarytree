class Solution {
  public:
    vector<int> rightView(Node *root) {
        map<int,int> m;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontnode = temp.first;
            int level = temp.second;
            m[level] = frontnode->data;
            if(frontnode->left != NULL){
                q.push(make_pair(frontnode->left,level+1));
            }
            if(frontnode->right != NULL){
                q.push(make_pair(frontnode->right,level+1));
            }
        }
        for (auto i: m){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};
