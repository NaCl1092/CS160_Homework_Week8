//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input: 1 2 1 1 1 0
Output: 2 1 4 2 6 1 8 1 10 1 0
*/

/*
Test case 2:
Input: 1 2 3 4 2 1 0
Output: 2 1 4 2 6 3 8 4 10 2 12 1 0
*/

/*
Test case 3:
Input: 0
Output: 0
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
void InsertEven(Node *&pHead);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    InsertEven(pHead);
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

void InsertEven(Node *&pHead)
{
    if (pHead == nullptr) return;
    Node *cur = pHead->pNext, *pPrev = pHead;
    Node *newNode = new Node(2);
    newNode -> pNext = pHead;
    pHead = newNode;
    int curVal = 4;
    while (cur != nullptr)
    {
        Node *newNode = new Node(curVal);
        pPrev->pNext = newNode;
        newNode->pNext = cur;
        curVal += 2;
        pPrev = cur;
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
