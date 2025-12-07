//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input: 1 1 1 1 1 0
Output: 1 0
*/

/*
Test case 2:
Input: 1 2 3 4 2 1 0
Output: 1 2 3 4 0
*/

/*
Test case 3:
Input: 1 2 3 4 5 6 0
Output: 1 2 3 4 5 6 0
*/

struct Node
{
    int val;
    Node *pNext = nullptr;
    Node(int x)
    {
        val = x;
    }
};

void Input(Node *&pHead);
void deleteNode(Node *&pPrev, Node *&cur);
void deleteDuplicates(Node *pHead);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    deleteDuplicates(pHead);
    Output(pHead);
    return 0;
}

void Input(Node *&pHead)
{
    Node *cur = nullptr;
    ifstream inp("Input.txt");
    int x;
    while (inp >> x)
    {
        if (x == 0) break;
        Node *newNode = new Node(x);
        if (pHead == nullptr)
        {
            pHead = cur = newNode;
        }
        else
        {
            cur->pNext = newNode;
            cur = newNode;
        }
    }
    inp.close();
}

void deleteDuplicates(Node *pHead)
{
    Node *cur = pHead;
    while (cur != nullptr)
    {
        int x = cur->val;
        Node *nxt = cur;
        while (nxt->pNext != nullptr)
        {
            if (nxt->pNext->val == x)
            {
                Node *Next = nxt->pNext;
                nxt->pNext = Next->pNext;
                delete Next;
            }
            else nxt = nxt->pNext;
        }
        cur = cur->pNext;
    }
}

void Output(Node *pHead)
{
    ofstream out("Result.txt");
    Node *cur = pHead;
    while (cur != nullptr)
    {
        out << cur->val << ' ';
        cur = cur->pNext;
    }
    out << "0\n";
    out.close();
}
