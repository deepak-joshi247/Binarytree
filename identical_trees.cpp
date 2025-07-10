void pushinstack(Node* r1,stack<int>& s){
    if(r1==NULL){
        return ;
    }
    pushinstack(r1->left,s);
   pushinstack(r1->right,s);
    s.push(r1->data);
}
void checkwithr2(Node* r2,stack<int>& s,bool& isequal){
    if(r2==NULL){
        return ;
    }
    int tip = s.top();
    s.pop();
    if(tip != r2->data){
        isequal = false;
        return;
    }
    checkwithr2(r2->right,s,isequal);
    checkwithr2(r2->left,s,isequal);
}

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        stack<int> s;
        pushinstack(r1,s);
        bool isequal = true;
        checkwithr2(r2,s,isequal);
        return isequal;
        
    }
};
