//25125040
//Le Hong Dang
//25A02

#include<iostream>
using namespace std;

/*
Test case 1:
Input:
    1
    0
Output: 1 0
*/

/*
Test case 2:
Input:
    2
    3 4 5 0
Output: 2 3 4 5 0
*/

/*
Test case 3:
Input:
    2
    1 2 3 4 0
Output: 1 2 2 3 4 0
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
void InserttoSorted(Node *&pHead, int v);
void Output(Node *pHead);

int main()
{
    int val;
    cin >> val;
    Node *pHead = nullptr;
    Input(pHead);
    InserttoSorted(pHead, val);
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

void InserttoSorted(Node *&pHead, int v)
{
    if (pHead == nullptr)
    {
        pHead = new Node(v);
        return;
    }
    if (pHead->val > v)
    {
        Node *newNode = new Node(v);
        newNode->pNext = pHead;
        pHead = newNode;
        return;
    }
    Node *cur = pHead;
    while (cur->pNext != nullptr && cur->pNext->val < v) cur = cur->pNext;
    Node *newNode = new Node(v);
    newNode->pNext = cur->pNext;
    cur->pNext = newNode;
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
