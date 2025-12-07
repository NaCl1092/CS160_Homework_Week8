//25125040
//Le Hong Dang
//25A02

#include<iostream>
using namespace std;

/*
Test case 1:
Input: 1 2 1 1 1 0
Output: 1 3 4 5 6 0
*/

/*
Test case 2:
Input: 1 2 3 4 2 1 0
Output: 1 3 6 10 12 13 0
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
Node* Sum(Node *pHead);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    Node *pAns = Sum(pHead);
    Output(pAns);
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

Node* Sum(Node *pHead)
{
    if (pHead == nullptr) return nullptr;
    int S = 0;
    Node *pAns = nullptr, *curAns = nullptr;
    Node *cur = pHead;
    while (cur != nullptr)
    {
        S += cur->val;
        Node *newNode = new Node(S);
        if (pAns == nullptr)
        {
            pAns = curAns = newNode;
        }
        else
        {
            curAns->pNext = newNode;
            curAns = curAns->pNext;
        }
        cur = cur->pNext;
    }
    return pAns;
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
