//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input:
    1 2 3 4 0
    5 6 7 8 0
Output: 1 5 2 6 3 7 4 8 0
*/

/*
Test case 2:
Input:
    1 0
    1 2 3 4 0
Output: 1 1 2 3 4 0
*/

/*
Test case 3:
Input:
    1 2 3 4 0
    1 0
Output: 1 1 2 3 4 0
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

void Input(Node *&pHead1, Node *&pHead2);
void Merge(Node *&pHead, Node *pHead1, Node *pHead2);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Node *pHead1 = nullptr, *pHead2 = nullptr;
    Input(pHead1, pHead2);
    Merge(pHead, pHead1, pHead2);
    Output(pHead);
    delete pHead, pHead1, pHead2;
    return 0;
}

void Input(Node *&pHead1, Node *&pHead2)
{
    Node *cur = nullptr;
    ifstream inp("Input.txt");
    int x;
    while (inp >> x)
    {
        if (x == 0) break;
        Node *newNode = new Node(x);
        if (pHead1 == nullptr)
        {
            pHead1 = cur = newNode;
        }
        else
        {
            cur->pNext = newNode;
            cur = newNode;
        }
    }
    cur = nullptr;
    while (inp >> x)
    {
        if (x == 0) break;
        Node *newNode = new Node(x);
        if (pHead2 == nullptr)
        {
            pHead2 = cur = newNode;
        }
        else
        {
            cur->pNext = newNode;
            cur = newNode;
        }
    }
    inp.close();
}

void Merge(Node *&pHead, Node *pHead1, Node *pHead2)
{
    if (pHead1 == nullptr && pHead2 == nullptr) return;
    if (pHead1 == nullptr)
    {
        pHead = pHead2;
        return;
    }
    if (pHead2 == nullptr)
    {
        pHead = pHead1;
        return;
    }
    pHead = pHead1;
    Node *cur1 = pHead1, *cur2 = pHead2;
    Node *pNext1 = nullptr, *pNext2 = nullptr, *last = nullptr;
    while (cur1 != nullptr && cur2 != nullptr)
    {
        pNext1 = cur1->pNext;
        pNext2 = cur2->pNext;
        cur1->pNext = cur2;
        cur2->pNext = pNext1;
        last = cur2;
        cur1 = pNext1;
        cur2 = pNext2;
    }
    if (cur1 == nullptr && cur2 != nullptr)
    {
        if (last != nullptr) last->pNext = cur2;
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
