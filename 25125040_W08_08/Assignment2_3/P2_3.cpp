//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input: 1 2 1 1 1 0
Output: 1 1 1 2 1 0
*/

/*
Test case 2:
Input: 1 2 3 4 2 1 0
Output: 1 2 4 3 2 1 0
*/

/*
Test case 3:
Input: 1 2 3 4 5 6 0
Output: 6 5 4 3 2 1 0
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
Node* reverseList(Node *pHead);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    pHead = reverseList(pHead);
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

Node* reverseList(Node *pHead)
{
    if (pHead == nullptr || pHead->pNext == nullptr) return pHead;
    Node *ans = reverseList(pHead->pNext);
    pHead->pNext->pNext = pHead;
    pHead->pNext = nullptr;
    return ans;
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
