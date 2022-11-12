#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node * root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node * root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void posorder(Node * root){
    if(root==NULL)return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}


int main(){

    int x;
    cout<<"enter root: ";
    cin>>x;
    Node *root = new Node(x);
    Node *temp, *newNode;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        cout<<"enter left of "<<temp->data<<" : ";
        cin>>x;
        if(x!=-1){
            newNode = new Node(x);
            q.push(newNode);
            temp->left = newNode;
        }
        cout<<"enter right of "<<temp->data<<" : ";
        cin>>x;
        if(x!=-1){
            newNode = new Node(x);
            q.push(newNode);
            temp->right = newNode;
        }

    }

    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    preorder(root);
    cout<<endl;

    return 0;
}