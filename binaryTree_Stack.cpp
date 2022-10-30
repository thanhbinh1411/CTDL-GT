#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_SIZE 100
int i = 500;
// Khai bao cau truc Node
typedef struct Node
{
    char data;
    struct Node *P_L, *P_R;
} Node;

// Khai bao cau truc Stack
typedef struct Stack
{
    int size;
    int top;
    struct Node **array;
} Stack;

// Ham tao cau truc Node moi
Node *newNode(char data)
{
    Node *node = new Node;
    node->data = data;
    node->P_L = node->P_R = NULL;
    return node;
}

// Ham tao cau truc Stack moi
Stack *createStack(int size)
{
    Stack *stack = new Stack();
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node **)malloc(stack->size * sizeof(struct Node *));
    return stack;
}

// Hoat dong cua Stack
int isFull(Stack *stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, Node *node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

Node *pop(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
// lay gia tri o dinh nhung kh xoa no
Node *peek(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void postOrderIterative(Node *root)
{
    string s1;

    if (root == NULL)
        return;

    Stack *stack = createStack(MAX_SIZE);
    do
    {
        // Di chuyen den node ngoai cung ben trai
        while (root)
        {
            // Dat goc con ben phai va cho goc vao ngan xep Stack
            if (root->P_R)
                push(stack, root->P_R);
            push(stack, root);

            // Dat goc la goc con ben trai
            root = root->P_L;
        }

        // Lay ra khoi ngan xep va dat lam goc
        root = pop(stack);

        // Neu lay ra node con ben phai va no chua duoc xu ly
        // thi node con ben phai phai duoc xu ly truoc goc root
        if (root->P_R && peek(stack) == root->P_R)
        {
            pop(stack);        // lay goc con ben phai ra khoi Stack
            push(stack, root); // dat goc root vao ngan xep Stack
            root = root->P_R;  // thay doi goc den node con ben phai xu ly tiep theo
        }
        else // Nguoc lai in ra gia tri cua goc root va dat goc root la trong NULL
        {
            s1 = s1 + root->data + " ";

            root = NULL;
        }
    } while (!isEmpty(stack));
    cout << s1 << endl;
}

void preOrderIterative(Node *root)
{
    string s1;

    if (root == NULL)
        return;

    Stack *stack = createStack(MAX_SIZE);
    push(stack, root);
    while (!isEmpty(stack))
    {
        Node *temp = pop(stack);
        s1 = s1 + temp->data + " ";

        if (temp->P_R != NULL)
            push(stack, temp->P_R);
        if (temp->P_L != NULL)
            push(stack, temp->P_L);
    }
    cout << s1 << endl;
}

void inOrderIterative(Node *root)
{
    string s1;

    if (root == NULL)
        return;

    Stack *stack = createStack(MAX_SIZE);
    push(stack, root);
    while (!isEmpty(stack))
    {
        Node *temp = peek(stack);
        if( temp -> P_R != NULL)
        {
            push(stack, temp ->P_R);
        }
        if(temp -> P_L != NULL) 
        {
            push(stack, temp -> P_L);
        }
        else
        {
            cout<<temp -> data <<" ";
            pop(stack);
        }
    }
    //cout << s1 << endl;
}

void PreOder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        PreOder(p->P_L);
        PreOder(p->P_R);
    }
}
void InOrder(Node *p)
{
    if (p != NULL)
    {
        InOrder(p->P_L);
        cout << p->data << " ";
        InOrder(p->P_R);
    }
}
void PostOder(Node *p)
{
    if (p != NULL)
    {
        PostOder(p->P_L);
        PostOder(p->P_R);
        cout << p->data << " ";
    }
}

int main()
{
    // TAO CAC NODE MOI CHO CAY
    Node *root = NULL;
    root = newNode('A');
    root->P_L = newNode('C');
    root->P_R = newNode('B');
    root->P_L->P_L = newNode('G');
    root->P_L->P_R = newNode('F');
    root->P_L->P_R->P_L = newNode('I');
    root->P_R->P_L = newNode('E');
    root->P_R->P_R = newNode('D');
    root->P_R->P_R->P_R = newNode('H');

    postOrderIterative(root);
    PostOder(root);
    cout << endl;
    cout << endl;

    preOrderIterative(root);
    PreOder(root);
    cout << endl;
    cout << endl;

    InOrder(root);
    cout << endl;
    //inOrderIterative(root);
    return 0;
}
