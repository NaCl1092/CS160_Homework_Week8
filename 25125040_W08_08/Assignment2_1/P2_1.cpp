//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
using namespace std;

/*
Test case 1:
Input:
    1 1 1 1 1 0
    1
Output: 0
*/

/*
Test case 2:
Input:
    1 2 3 4 2 1 0
    1
Output: 2 3 4 2 0
*/

/*
Test case 3:
Input:
    1 2 3 4 2 1 0
    10
Output: 1 2 3 4 2 1 0
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
void deleteAllVal(Node *&pHead, int v);
void Output(Node *pHead);

int main()
{
    Node *pHead = nullptr;
    Input(pHead);
    int x;
    cout << "Please enter a value to remove from the list: ";
    cin >> x;
    deleteAllVal(pHead, x);
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

void deleteAllVal(Node *&pHead, int v)
{
    while (pHead != nullptr && pHead->val == v)
    {
        Node *cur = pHead;
        pHead = pHead->pNext;
        delete cur;
    }
    if (pHead == nullptr) return;
    Node *cur = pHead;
    while (cur->pNext != nullptr)
    {
        if (cur->pNext->val == v)
        {
            Node *temp = cur->pNext;
            cur->pNext = temp->pNext;
            delete temp;
        }
        else cur = cur->pNext;
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
