class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        map <int,pair<int,bool>>m;  //bool is made so that the value of node on a hd doesnt get update
        queue<pair<Node*,int>> q;
        vector<int> ans;
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
            if(m[hd].second!=true){
                m[hd].first = frontnode->data;
                m[hd].second = true;
            }
            if(frontnode->left != NULL){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right != NULL){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:m){
                ans.push_back(i.second.first);
        } 
        return ans;
    }

    
};
