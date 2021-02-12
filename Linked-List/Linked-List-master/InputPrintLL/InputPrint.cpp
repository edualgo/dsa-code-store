#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

class helper
{
public:
    int length(Node* head)
    {
        Node* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            count++;
        }
        return count;
    }
    void print_ll(Node* head)
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
    Node* take_input()
    {
        int data;
        cin >> data;
        Node* head = nullptr;
        Node* tail = nullptr;
        while(data != -1)
        {
            Node* n = new Node(data);
            if(head==nullptr)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail -> next = n;
                tail = tail -> next;
            }
            cin >> data;
        }
        return head;
    }

};
int main()
{
    helper help_object;
    Node* head = help_object.take_input();
    help_object.print_ll(head);
    return 0;
}
