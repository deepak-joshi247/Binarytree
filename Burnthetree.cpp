steps- 
1. a map from childtoparent
2. finding target node
3. Burning the tree 
*/

class Solution {
    Node* mappingchildtoparent(int target,Node* root,map<Node*,Node*> &childtoparent){
        childtoparent[root] = NULL;
        Node* targetnode = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == target){
                targetnode = front;
            }
            if(front->left){
                childtoparent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                childtoparent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetnode;
    }
    int burnthetree(Node* root,map<Node*,Node*> &childtoparent,Node* targetnode){
        map<Node*,bool> nodevisited;
        queue<Node*> q;
        q.push(targetnode);
        nodevisited[targetnode] = true;
        int ans = 0;
        while(!q.empty()){
            int flag = 0;   
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                if(front->left && nodevisited[front->left]==false){
                    flag = 1;
                    nodevisited[front->left] = true;
                    q.push(front->left);
                }
                if(front->right && nodevisited[front->right]==false){
                    flag = 1;
                    nodevisited[front->right] = true;
                    q.push(front->right);
                }
                if(childtoparent[front] && nodevisited[childtoparent[front]]==false){
                    flag = 1;
                    nodevisited[childtoparent[front]] = true;
                    q.push(childtoparent[front]);
                }
            }
            if (flag==1){
                ans+=1;
            }
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) {
        map<Node*,Node*> childtoparent;
        Node* targetnode = mappingchildtoparent(target,root,childtoparent);
        int ans = burnthetree(root,childtoparent,targetnode);
        return ans;
    }
};

