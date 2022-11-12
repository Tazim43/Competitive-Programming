#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node *insert(Node *root, int val){
    if(root==NULL)return new Node(val);

    if(root->data>val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node *search(Node *root, int val){
    if(root==NULL)return NULL;
    if(root->data==val)return root;
    if(root->data>val)return search(root->left, val);
    else return search(root->right, val);
}

Node *inorderSucc(Node *root){
    Node *cur = root;
    while (cur && cur->left!=NULL)
    {
        cur = cur->left;
    }
    return cur;
}

Node *del(Node *root, int val){
    if(root->data > val){
        root->left = del(root->left, val);
    }
    else if(root->data <val){
        root->right = del(root->right, val);
    }
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3 
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";

}



int main(){

    int n;
    cin>>n;
    int rt;
    cin>>rt;
    Node *root = new Node(rt);
    for(int i=0; i<n-1; i++){
        int a;
        cin>>a;
        root = insert(root, a);
    }    

    inorder(root);
    cout<<endl;
    int st;
    cin>>st;
    root = del(root, st);
    inorder(root);

    return 0;
}