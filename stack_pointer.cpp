#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct item
{
    /* data */
    int data;
};
 
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
// nhap stack
// void Input(Stack &S)
// {
//     // nhap den khi nao x = 0 thi ket thuc
//     item x;
//     do
//     {
//         cin >> x;
//         if (x != 0)
//             push(S, x);
//     } while (x != 0);
// }
// void Output(Stack S)
// {
//     cout << endl;
//     while (!(IsEmpty(S)))
//         cout << pop(S) << " ";
// }

int main()
{
    Stack S;
    Newstack(S);
    //Input(S);
    //Output(S);
    return 0;
}