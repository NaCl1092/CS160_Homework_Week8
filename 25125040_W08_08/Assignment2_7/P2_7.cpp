//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input: 1 2 1 1 1 0
Output:
    1 1 1 0
    2 1 0

*/

/*
Test case 2:
Input: 1 2 3 4 2 1 0
Output:
    1 3 2 0
    2 4 1 0
*/

/*
Test case 3:
Input: 0
Output:
    0
    0
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
void Split(Node *pHead, Node *&pHeadOdd, Node *&pHeadEven);
void Output(Node *pHead1, Node *pHead2);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    Node *pHeadOdd = nullptr, *pHeadEven = nullptr;
    Split(pHead, pHeadOdd, pHeadEven);
    Output(pHeadOdd, pHeadEven);
    delete pHead, pHeadOdd, pHeadEven;
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

void Split(Node *pHead, Node *&pHeadOdd, Node *&pHeadEven)
{
    if (pHead == nullptr || pHead->pNext == nullptr)
    {
        pHeadOdd = pHead;
        pHeadEven = nullptr;
        return;
    }
    pHeadOdd = pHead;
    pHeadEven = pHead->pNext;
    Node *curOdd = pHeadOdd, *curEven = pHeadEven;
    while (curEven != nullptr && curEven->pNext != nullptr)
    {
        curOdd->pNext = curEven->pNext;
        curOdd = curOdd->pNext;

        curEven->pNext = curOdd->pNext;
        curEven = curEven->pNext;
    }
    if (curOdd != nullptr) curOdd->pNext = nullptr;
}

void Output(Node *pHead1, Node *pHead2)
{
    ofstream out("Result.txt");
    Node *cur = pHead1;
    while (cur != nullptr)
    {
        out << cur->val << ' ';
        cur = cur->pNext;
    }
    out << "0\n";
    cur = pHead2;
    while (cur != nullptr)
    {
        out << cur->val << ' ';
        cur = cur->pNext;
    }
    out << "0\n";
    out.close();
}
