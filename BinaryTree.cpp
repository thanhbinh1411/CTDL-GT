#include <iostream>
using namespace std;

#pragma region Stack
typedef int item;
 
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

#pragma region Tree
struct tNode
{
    int data;
    tNode *Left, *Right;
};

tNode *root;

// create new node
tNode *newNode(int data)
{
    tNode *node = new tNode;
    node->data = data;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

void PreOder(tNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOder(root->Left);
        PreOder(root->Right);
    }
}
void InOrder(tNode *root)
{
    if (root != NULL)
    {
        InOrder(root->Left);
        cout << root->data << " ";
        InOrder(root->Right);
    }
}
void PostOder(tNode *root)
{
    if (root != NULL)
    {
        PostOder(root->Left);
        PostOder(root->Right);
        cout << root->data << " ";
    }
}
#pragma endregion
int main()
{
    root = newNode(1);
    tNode *node2 = newNode(2);
    tNode *node3 = newNode(3);
    tNode *node4 = newNode(4);
    tNode *node5 = newNode(5);
    tNode *node6 = newNode(6);
    tNode *node7 = newNode(7);
    // assign childnodes
    root->Left = node2;
    root->Right = node3;
    node2->Left = node4;
    node2->Right = node5;
    node5->Left = node6;
    node5->Right = node7;

    cout << "\nBinary tree with PreOrder:";
    PreOder(root);

    cout << "\nBinary tree with InOrder:";
    InOrder(root);

    cout << "\nBinary tree with PostOrder:";
    PostOder(root);

    return 0;
}
