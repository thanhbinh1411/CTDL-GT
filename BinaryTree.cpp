#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>

using namespace std;

//stack
#pragma region Stack_pointer

typedef node item;
struct Node // khai bao node du lieu
{
    item Data;  // du lieu
    Node *Next; // con tri lien ket
};

typedef struct Stack
{
    Node *Top;
} Stack; // dinh nghia Stack thanh Stack

// ham khoi tao stack
void Newstack(Stack &S)
{
    S.Top = NULL;
}

int IsEmpty(Stack &S)
{
    return (S.Top == NULL);
}
// ham kiem tra do dai stack
int LenStack(Stack S)
{
    Node *P = S.Top; // Khai báo con tro P tro toi S
    int i = 0;
    while (P != NULL)
    {
        i++;
        P = P->Next;
    }
    return i;
}
// ham tao mot Node
Node *NewNode(item X)
{
    Node *P = new Node;
    // code C: Node *P = (Node*)malloc(sizeof(node))
    P->Data = X;
    P->Next = NULL;
    return P;
}
// ham push them vao dau danh sach
void push(Stack &S, item X)
{
    Node *P = NewNode(X); // tao node P chua gia tri X
    P->Next = S.Top;
    S.Top = P;
}
// ham pop lay gia tri phan tu dau tin danh sach
item pop(Stack &S)
{
    if (S.Top != NULL)
    {
        item X = S.Top->Data;
        S.Top = S.Top->Next;
        return X;
    }
}
// ham chen gia tri x vao vi tri k
void Insert_K(Stack &S, item x, int k)
{
    if (k < 1 || k > LenStack(S))
        cout << "vi tri khong hop le";
    else
    {
        Stack temp;
        Newstack(temp);
        int t = LenStack(S) - k;
        while (t >= 0)
        {
            push(temp, pop(S));
            t--;
        }
        push(S, x);
        while (!(IsEmpty(S)))
        {
            push(S, pop(temp));
        }
    }
}

#pragma endregion

//binary tree
// dinh nghia kieu du lieu cho cay
struct node
{
    int data;
    node *left;
    node *right;
}; // dinh nghia node thanh node

// ham giai phong du lieu
void Free(node *root)
{
    if (root == NULL)
        return;
    Free(root->left);
    Free(root->right);
    Free(root);
}

// ham tao 1 node moi
node *CreateNode(int data)
{
    node *newnode = new node();
    if (!newnode)
    {
        cout << "memory error" << endl;
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
// ham chen 1 node moi vao cay
node *InsertNode(node *root, int data)
{
    // neu cay rong thi tao mot root moi
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }
    // tim tu tai qua phai nde naof = null thi insert
    // float s;
    Stack S;
    Newstack(S);
    push(S, root);
    while (!IsEmpty(S))
    {
        node *temp = pop(S);
        if (temp->left != NULL)
            push(S, temp->left);
        else
        {
            temp->left = CreateNode(data);
            return root;
        }
        if (temp->right != NULL)
            push(S, temp->right);
        else
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
// ham duyet preOder
void PreOder(node *root)
{
    if (root != NULL)
    {
        cout << root->data < " ";
        PreOder(root->left);
        PreOder(root->right);
    }
}
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}
void PostOder(node *root)
{
    if (root != NULL)
    {
        PostOder(root->left);
        PostOder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    InOrder(root);
    cout << endl;
 
    int key = 12;
    root = InsertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    InOrder(root);
    cout << endl;
 
    return 0;
}