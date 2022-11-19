#include <iostream>
#include <stdlib.h>

using namespace std;

struct NODE
{
    int LTAG, RTAG;
    int INFO;
    NODE *LLINK;
    NODE *RLINK;
};

struct DATA
{
    NODE *node;
    DATA *next;
};

struct STACK
{
    DATA *top;
    void init()
    {
        top = NULL;
    }
    bool insert(DATA *Y)
    {
        if (top == NULL)
        {
            top = Y;
            top->next = NULL;
            return true;
        }
        Y->next = top;
        top = Y;
        return true;
    }
    bool insertNode(NODE *y)
    {
        DATA *data = (DATA *)malloc(sizeof(DATA));
        data->node = y;
        return this->insert(data);
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    DATA *deleteStack()
    {
        if (this->isEmpty())
            return NULL;
        DATA *result;
        result = (DATA *)calloc(1, sizeof(DATA));
        result->node = top->node;
        DATA *next = top->next;
        delete (top);
        top = next;
        return result;
    }
};

struct UNTHREADTREE
{
    NODE *root;
    void init()
    {
        root = NULL;
    }
    void inorder()
    {
        STACK A;
        A.init();
        NODE *P = this->root;
        while (P != NULL || A.isEmpty() == false)
        {

            if (P == NULL)
            {
                if (A.isEmpty())
                    break;
                P = A.deleteStack()->node;
                cout << P->INFO << ",";
                P = P->RLINK;
            }
            else
            {

                A.insertNode(P);
                P = P->LLINK;
            }

            if (P != NULL)
                continue;
            if (A.isEmpty())
                break;
        }
    }
    void preorder()
    {
        STACK A;
        DATA *data;
        A.init();
        NODE *P = this->root;

        A.insertNode(P);
        while (A.isEmpty() == false)
        {
            P = A.deleteStack()->node;
            cout << P->INFO << ",";
            if (P->RLINK != NULL)
            {
                A.insertNode(P->RLINK);
            }
            if (P->LLINK != NULL)
            {

                A.insertNode(P->LLINK);
            }
        }
    }
    void postorder()
    {
        STACK A;

        A.init();
        NODE *P = this->root;
        NODE *current;

        A.insertNode(P);
        P = NULL;

        while (A.isEmpty() == false)
        {
            current = A.top->node;
            if (P == NULL)
            {
                if (current->LLINK != NULL)
                    A.insertNode(current->LLINK);
                else if (current->RLINK != NULL)
                    A.insertNode(current->RLINK);
                else
                {
                    A.deleteStack();
                    cout << current->INFO << " ,";
                }
            }
            else if (P != NULL)
            {
                if (P->LLINK == current || P->RLINK == current)
                {
                    if (current->LLINK != NULL)
                        A.insertNode(current->LLINK);
                    else if (current->RLINK != NULL)
                        A.insertNode(current->RLINK);
                    else
                    {
                        A.deleteStack();
                        cout << current->INFO << ",";
                    }
                }
                else if (current->LLINK == P)
                {
                    if (current->RLINK != NULL)
                    {
                        A.insertNode(current->RLINK);
                    }
                    else
                    {
                        A.deleteStack();
                        cout << current->INFO << ",";
                    }
                }
                else if (current->RLINK == P)
                {
                    A.deleteStack();
                    cout << current->INFO << ",";
                }
            }

            P = current;
        }
    }
};

struct THREADTREE
{

    NODE *root;
    void init()
    {
        root = NULL;
    }
    NODE *nextNodeInoder(NODE *P)
    {
        NODE *Q = P->RLINK;
        if (P->RTAG == 1)
            return Q;
        while (Q->LTAG == 0)
        {
            Q = Q->LLINK;
        }
        return Q;
    }
    NODE *leftNode()
    {
        NODE *Q = root->LLINK;
        while (Q->LTAG != 1)
        {
            Q = Q->LLINK;
        }
        return Q;
    }
    void inoder()
    {
        NODE *P = leftNode();
        while (P != root)
        {
            cout << P->INFO << ",";
            P = nextNodeInoder(P);
        }
    }
    void preorder()
    {
        NODE*P = root->LLINK;
        while(P != root)
        {
            cout << P->INFO << ",";
            P = nextNodeInoder(P);
        }
    }
     NODE *nextNodePostoder(NODE *P)
    {
        NODE *Q = P->RLINK;
        if (P->RTAG == 1)
            return Q;
        while (Q->LTAG == 0)
        {
            Q = Q->LLINK;
        }
        return Q;
    }
    void postorder()
    {
        NODE*P = leftNode();
        while (P != root)
        {
            cout << P->INFO << ",";
            P = nextNodeInoder(P);
        }
    }
};

UNTHREADTREE *build_unthread_tree()
{
    // inorder D B A E G C H F J
    UNTHREADTREE *tree;
    tree = (UNTHREADTREE *)malloc(sizeof(UNTHREADTREE));
    tree->init();
    NODE *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeJ;
    nodeA = (NODE *)malloc(sizeof(NODE));
    nodeB = (NODE *)malloc(sizeof(NODE));
    nodeC = (NODE *)malloc(sizeof(NODE));
    nodeD = (NODE *)malloc(sizeof(NODE));
    nodeE = (NODE *)malloc(sizeof(NODE));
    nodeF = (NODE *)malloc(sizeof(NODE));
    nodeG = (NODE *)malloc(sizeof(NODE));
    nodeH = (NODE *)malloc(sizeof(NODE));
    nodeJ = (NODE *)malloc(sizeof(NODE));
    nodeA->INFO = 8;
    nodeB->INFO = 3;
    nodeC->INFO = 10;
    nodeD->INFO = 1;
    nodeE->INFO = 6;
    nodeF->INFO = 4;
    nodeG->INFO = 7;
    nodeH->INFO = 14;
    nodeJ->INFO = 13;
    nodeA->LTAG = 0;
    nodeA->RTAG = 0;
    nodeB->LTAG = 0;
    nodeB->RTAG = 0;
    nodeC->LTAG = 0;
    nodeC->RTAG = 0;
    nodeD->LTAG = 0;
    nodeD->RTAG = 0;
    nodeE->LTAG = 0;
    nodeE->RTAG = 0;
    nodeF->LTAG = 0;
    nodeF->RTAG = 0;
    nodeG->LTAG = 0;
    nodeG->RTAG = 0;
    nodeH->LTAG = 0;
    nodeH->RTAG = 0;
    nodeJ->LTAG = 0;
    nodeJ->RTAG = 0;

    tree->root = nodeA;
    tree->root->LLINK = nodeB;
    tree->root->RLINK = nodeC;
    nodeB->RLINK = nodeE;
    nodeB->LLINK = nodeD;
    nodeD->LLINK = NULL;
    nodeD->RLINK = NULL;

    nodeC->LLINK = NULL;
    nodeC->RLINK = nodeH;

    nodeE->LLINK = nodeF;
    nodeE->RLINK = nodeG;
    nodeG->LLINK = NULL;
    nodeG->RLINK = NULL;

    nodeF->LLINK = NULL;
    nodeF->RLINK = NULL;
    nodeH->LLINK = nodeJ;
    nodeH->RLINK = NULL;
    nodeJ->LLINK = NULL;
    nodeJ->RLINK = NULL;
    return tree;
}

THREADTREE *build_thread_tree_inoder()
{
    // inorder D B A E G C H F J
    THREADTREE *tree;
    tree = (THREADTREE *)malloc(sizeof(THREADTREE));
    tree->init();
    NODE *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeJ;
    nodeA = (NODE *)malloc(sizeof(NODE));
    nodeB = (NODE *)malloc(sizeof(NODE));
    nodeC = (NODE *)malloc(sizeof(NODE));
    nodeD = (NODE *)malloc(sizeof(NODE));
    nodeE = (NODE *)malloc(sizeof(NODE));
    nodeF = (NODE *)malloc(sizeof(NODE));
    nodeG = (NODE *)malloc(sizeof(NODE));
    nodeH = (NODE *)malloc(sizeof(NODE));
    nodeJ = (NODE *)malloc(sizeof(NODE));

    nodeA->INFO = 8;
    nodeB->INFO = 3;
    nodeC->INFO = 10;
    nodeD->INFO = 1;
    nodeE->INFO = 6;
    nodeF->INFO = 4;
    nodeG->INFO = 7;
    nodeH->INFO = 14;
    nodeJ->INFO = 13;

    tree->root = (NODE *)malloc(sizeof(tree));

    nodeA->RTAG = 0;    nodeA->RLINK = nodeC;
    nodeA->LTAG = 0;    nodeA->LLINK = nodeB;

    nodeB->LTAG = 0;    nodeB->LLINK = nodeD;
    nodeB->RTAG = 0;    nodeB->RLINK = nodeE;

    nodeC->RTAG = 0;    nodeC->RLINK = nodeH;
    nodeC->LTAG = 1;    nodeC->LLINK = nodeA;

    nodeD->LTAG = 1;    nodeD->LLINK = tree->root;
    nodeD->RTAG = 1;    nodeD->RLINK = nodeB;

    nodeE->RTAG = 0;    nodeE->RLINK = nodeG;
    nodeE->LTAG = 0;    nodeE->LLINK = nodeF;

    nodeG->RTAG = 1;    nodeG->RLINK = nodeA;
    nodeG->LTAG = 1;    nodeG->LLINK = nodeE;

    nodeF->RTAG = 1;    nodeF->RLINK = nodeE;
    nodeF->LTAG = 1;    nodeF->LLINK = nodeB;

    nodeH->RTAG = 1;    nodeH->RLINK = tree -> root;
    nodeH->LTAG = 0;    nodeH->LLINK = nodeJ;

    nodeJ->RTAG = 1;    nodeJ->RLINK = nodeH;
    nodeJ->LTAG = 1;    nodeJ->LLINK = nodeC;

    tree->root->LTAG = 0;    tree->root->LLINK = nodeA;
    tree->root->RTAG = 1;    tree->root->RLINK = tree->root;

    return tree;
}

THREADTREE *build_thread_tree_preoder()
{
    // inorder D B A E G C H F J
    THREADTREE *tree;
    tree = (THREADTREE *)malloc(sizeof(THREADTREE));
    tree->init();
    NODE *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeJ;
    nodeA = (NODE *)malloc(sizeof(NODE));
    nodeB = (NODE *)malloc(sizeof(NODE));
    nodeC = (NODE *)malloc(sizeof(NODE));
    nodeD = (NODE *)malloc(sizeof(NODE));
    nodeE = (NODE *)malloc(sizeof(NODE));
    nodeF = (NODE *)malloc(sizeof(NODE));
    nodeG = (NODE *)malloc(sizeof(NODE));
    nodeH = (NODE *)malloc(sizeof(NODE));
    nodeJ = (NODE *)malloc(sizeof(NODE));

    nodeA->INFO = 8;
    nodeB->INFO = 3;
    nodeC->INFO = 10;
    nodeD->INFO = 1;
    nodeE->INFO = 6;
    nodeF->INFO = 4;
    nodeG->INFO = 7;
    nodeH->INFO = 14;
    nodeJ->INFO = 13;

    tree->root = (NODE *)malloc(sizeof(tree));

    nodeA->RTAG = 1;    nodeA->RLINK = nodeB;
    nodeA->LTAG = 1;    nodeA->LLINK = tree->root;

    nodeB->LTAG = 0;    nodeB->LLINK = nodeD;
    nodeB->RTAG = 0;    nodeB->RLINK = nodeE;

    nodeC->RTAG = 0;    nodeC->RLINK = nodeH;
    nodeC->LTAG = 1;    nodeC->LLINK = nodeG;

    nodeD->LTAG = 1;    nodeD->LLINK = nodeB;
    nodeD->RTAG = 1;    nodeD->RLINK = nodeE;

    nodeE->RTAG = 0;    nodeE->RLINK = nodeG;
    nodeE->LTAG = 0;    nodeE->LLINK = nodeF;

    nodeG->RTAG = 1;    nodeG->RLINK = nodeC;
    nodeG->LTAG = 1;    nodeG->LLINK = nodeF;

    nodeF->RTAG = 1;    nodeF->RLINK = nodeG;
    nodeF->LTAG = 1;    nodeF->LLINK = nodeE;

    nodeH->RTAG = 1;    nodeH->RLINK = nodeJ;
    nodeH->LTAG = 0;    nodeH->LLINK = nodeJ;

    nodeJ->RTAG = 1;    nodeJ->LLINK = nodeH;
    nodeJ->LTAG = 1;    nodeJ->RLINK = tree -> root;

    tree->root->LTAG = 0;    tree->root->LLINK = nodeA;
    tree->root->RTAG = 1;    tree->root->RLINK = tree->root;

    return tree;
}

THREADTREE *build_thread_tree_postoder()
{
    // inorder D B A E G C H F J
    THREADTREE *tree;
    tree = (THREADTREE *)malloc(sizeof(THREADTREE));
    tree->init();
    NODE *nodeA, *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeJ;
    nodeA = (NODE *)malloc(sizeof(NODE));
    nodeB = (NODE *)malloc(sizeof(NODE));
    nodeC = (NODE *)malloc(sizeof(NODE));
    nodeD = (NODE *)malloc(sizeof(NODE));
    nodeE = (NODE *)malloc(sizeof(NODE));
    nodeF = (NODE *)malloc(sizeof(NODE));
    nodeG = (NODE *)malloc(sizeof(NODE));
    nodeH = (NODE *)malloc(sizeof(NODE));
    nodeJ = (NODE *)malloc(sizeof(NODE));

    nodeA->INFO = 8;
    nodeB->INFO = 3;
    nodeC->INFO = 10;
    nodeD->INFO = 1;
    nodeE->INFO = 6;
    nodeF->INFO = 4;
    nodeG->INFO = 7;
    nodeH->INFO = 14;
    nodeJ->INFO = 13;

    tree->root = (NODE *)malloc(sizeof(tree));

    nodeA->RTAG = 1;    nodeA->RLINK = tree->root;
    nodeA->LTAG = 0;    nodeA->LLINK = nodeB;

    nodeB->LTAG = 0;    nodeB->LLINK = nodeD;
    nodeB->RTAG = 0;    nodeB->RLINK = nodeE;

    nodeC->RTAG = 0;    nodeC->RLINK = nodeH;
    nodeC->LTAG = 1;    nodeC->LLINK = nodeH;

    nodeD->LTAG = 1;    nodeD->LLINK = tree->root;
    nodeD->RTAG = 1;    nodeD->RLINK = nodeF;

    nodeE->RTAG = 0;    nodeE->RLINK = nodeG;
    nodeE->LTAG = 0;    nodeE->LLINK = nodeF;

    nodeG->RTAG = 1;    nodeG->RLINK = nodeE;
    nodeG->LTAG = 1;    nodeG->LLINK = nodeF;

    nodeF->RTAG = 1;    nodeF->RLINK = nodeG;
    nodeF->LTAG = 1;    nodeF->LLINK = nodeD;

    nodeH->RTAG = 1;    nodeH->RLINK = nodeC;
    nodeH->LTAG = 0;    nodeH->LLINK = nodeJ;

    nodeJ->RTAG = 1;    nodeJ->RLINK = nodeH;
    nodeJ->LTAG = 1;    nodeJ->LLINK = nodeB;

    tree->root->LTAG = 0;    tree->root->LLINK = nodeA;
    tree->root->RTAG = 1;    tree->root->RLINK = tree->root;

    return tree;
}

int main()
{

    UNTHREADTREE *tree1 = build_unthread_tree();
    tree1->inorder();
    cout << endl;
    tree1->preorder();
    cout << endl;
    tree1->postorder();

    cout << endl;
    cout << endl;
    THREADTREE *tree2 = build_thread_tree_inoder();
    cout << endl;
    tree2->inoder();

    THREADTREE *tree3 = build_thread_tree_preoder();
    cout << endl;
    tree3->preorder();

    THREADTREE *tree4 = build_thread_tree_postoder();
    cout << endl;
   // tree4->postorder();
    return 0;
}
