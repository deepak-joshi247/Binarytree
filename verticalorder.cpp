class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map <int,vector<int>>m;
        queue<pair<Node*,int>> q;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            //  we made temp since the below action cant be done in a queue 
            Node* frontnode = temp.first;
            int hd = temp.second;     //  horizontal distance
            
            m[hd].push_back(frontnode->data);   // since we are storing in vector part of map thats why we use push-baack()
            
            if(frontnode->left != NULL){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right != NULL){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:m){
                ans.push_back(i.second);
        } 
        return ans;
    }
};
