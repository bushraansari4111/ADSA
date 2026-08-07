#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left; 
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
bool search(Node*root,int key){
    if(root==NULL)
        return false;
    if(root->data==key){
        return true;
    }
    if(key< root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }

}

int main()
{
    Node* root = NULL;

    int arr[] = {70,30,80,20,60,40,50};

    for(int x : arr)
        root = insert(root, x);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    int key;
    cout<<"\nEnter element to search: ";
    cin>>key;

    if(search(root,key)){
        cout<<"\nElement Found";
    }else{
        cout<<"\nElement NOT Found";
    }

    return 0;
} 
/*
OUTPUt:
Preorder: 70 30 20 60 40 50 80 
Postorder: 20 50 40 60 30 80 70 
Enter element to search: 50

Element Found

/******************************/
/*
Inorder: 20 30 40 50 60 70 80 
Preorder: 70 30 20 60 40 50 80 
Postorder: 20 50 40 60 30 80 70 
Enter element to search: 10

Element NOT Found
*/