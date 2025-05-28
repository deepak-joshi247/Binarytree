#include<iostream>
#include<queue>
using namespace std;
    class node{
        public:
            int data;
            node* left;
            node* right;
            node(int d){
                this->data = d;
                this->left = NULL;
                this->right = NULL;
            }
    };
    node* createTree(node* root,int data){
        int data_left;
        int data_right;
        if(data==-1){
            return NULL;
        }
        root = new node(data); //intial  node value
        cout<<"enter data to the left of "<<data<<endl;
        cin>>data_left;
        root->left = createTree(root->left,data_left);
        cout<<"enter data to the right of "<<data<<endl;
        cin>>data_right;
        root->right = createTree(root->right,data_right);
        return root;
    }
    void printlevel(node* root){ // 1 3 5 -1 -1 -4 -1 -1 7 6 -1 -1 -1
        if(!root){
            return ;
        }
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            if(temp == NULL){
                cout<<endl; // a level is over
                if(!q.empty()){
                    q.push(NULL); // for new level 
                }
            }
            else{
                if (temp->data != -1){
                    cout << temp->data << " ";
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    void inorder(node* root){
        //LNR ->  L =left , N = print node , R = right
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(node* root){
        //NLR 
        if(root == NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(node* root){
        //LRN 
        if(root == NULL){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    int main()
    {
        int data;
        cout<<"enter data value "; //why this doesnt print with each left or right node
        cin>>data;
        node* root = NULL; //intialy root point to NULL
        root = createTree(root,data); 
        printlevel(root);
        cout<<"inorder sequence is : ";
        inorder(root);
        cout<<endl<<"preorder sequence is : ";
        preorder(root);
        cout<<endl<<"postorder sequence is : ";
        postorder(root);
    return 0;
    }