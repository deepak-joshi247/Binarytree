// approach 1 
class Solution {
  public:
    vector<int> leftView(Node *root) {
        map<int,pair<bool,int>> m;
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
            if(m[level].first != true){
                m[level].second = frontnode->data;
                m[level].first = true;
            }
            if(frontnode->left != NULL){
                q.push(make_pair(frontnode->left,level+1));
            }
            if(frontnode->right != NULL){
                q.push(make_pair(frontnode->right,level+1));
            }
        }
        for(auto i: m){
            ans.push_back(i.second.second);
        }
        return ans;
    }
};

// --------------------------------------------------------------------------------
// approach 2
class Solution {
    void helpmerecursion(map<int,Node*> &m,Node* root,int level){
        if(root==NULL){
            return;
        }
        if(m[level]==NULL){
            m[level] = root;
        }
        helpmerecursion(m,root->left,level+1);
        helpmerecursion(m,root->right,level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        map<int,Node*> m;
        int level = 0;
        helpmerecursion(m,root,level);
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second->data);
        }
        return ans;
    }
};

