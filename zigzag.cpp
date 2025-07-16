// this was like 95% done by me and the temp part is help of AI 
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue<Node*> currentlevel;
        queue<Node*> nextlevel;
        bool righttoleft = false;
        currentlevel.push(root);

        vector<int> temp; // To hold current level's values

        while (!currentlevel.empty()) {
            Node* front = currentlevel.front();
            currentlevel.pop();
            temp.push_back(front->data);

            if (front->left)  nextlevel.push(front->left);
            if (front->right) nextlevel.push(front->right);

            if (currentlevel.empty()) {
                if (righttoleft) reverse(temp.begin(), temp.end());
                ans.insert(ans.end(), temp.begin(), temp.end());
                temp.clear();
                righttoleft = !righttoleft;
                swap(currentlevel, nextlevel);
            }
        }

        return ans;
    }
};
