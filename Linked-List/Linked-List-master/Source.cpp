#include<bits/stdc++.h>
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

Node* insert_Node(Node* head,int i,int data)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    if(i==0)
    {
        newNode -> next = head;
        head = newNode;
        return head;
    }
    for(int j=0;j<i-1 && temp!=nullptr;j++)
    {
        temp = temp -> next;
    }
    Node* temp2 = temp -> next;
    temp -> next = newNode;
    newNode -> next = temp2;
    return head;
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

Node* deleteNode(Node* head,int pos)
{
    Node* temp = head;
    if(pos == 0)
    {
        head = head -> next;
        delete temp;
        return head;
    }
    for(int i=0;i<pos-1;i++)
    {
        temp = temp -> next;
    }
    Node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    temp2 -> next = nullptr;
    delete temp2;
    return head;
}
Node* deletenode(Node* head, int i)
{
    Node* temp = head;
    int p = length(head);
    if(i<=p)
    {
       if(i==0)
        {
            Node* a = head;
            head = temp -> next;
            delete a;
            return head;
        }
    for(int j=0;j<i-1;j++)
    {
        temp = temp -> next;
    }
    Node* a = temp -> next;
    if(a == NULL)
    {
        return head;
    }
    Node* b = a -> next;
    temp -> next = b;
    delete a;
    return head;
    }
    return head;
}


Node* RemoveNpowNodes(Node* head)
{
	int p = length(head);
	int j = 0;
	bool flag = true;
	while(flag)
    {
        if(pow(2,j)>p)
        {
            j--;
            flag = false;
            break;
        }
        j++;
    }
    Node* temp = head;
    Node* new_head = nullptr;
    for(int i=0;i<=j;i++)
    {
         new_head = deleteNode(temp,i);
    }
    head = deleteNode(new_head,0);
    return head;
}

Node* insertInMiddle(Node* head, int x)
{
	if(head == nullptr)
	{
	    return head;
	}
	Node* temp = head;
	int p = length(head);
	int pos;
	if(p%2==0)
    {
        pos = (p/2)-1;
    }
    else
    {
        pos = (p/2);
    }
    cout << pos << endl;
	for(int i=0;i<pos;i++)
	{
	    temp = temp -> next;
	}
	Node* newnode = new Node(x);
	Node* temp2 = temp -> next;
	temp -> next = newnode;
	newnode -> next = temp2;
	return head;
}
bool areIdentical(Node *head1, Node *head2)
{
    int n1 = length(head1);
    int n2 = length(head2);
    if(n1 != n2)
    {
        return false;
    }
    Node* temp1 = head1;
    Node* temp2 = head2;
    bool equal = true;
    int i=0;
    while(equal && i<n1)
    {
        if(temp1->data != temp2-> data)
        {
            equal = false;
            break;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
        i++;
    }
    return equal;
}

Node* removeDuplicates(Node* head)
{
    unordered_set<int> seen;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
    return head;
}

Node* sortedMerge(Node* head1, Node* head2)
{
    Node* final_head = nullptr;
    Node* final_tail = nullptr;
    if(head1 -> data < head2 -> data)
    {
        final_head = head1;
        final_tail = head1;
        head1 = head1 -> next;
    }
    else
    {
        final_head = head2;
        final_tail = head2;
        head2 = head2 -> next;
    }
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1 -> data < head2 -> data)
        {
            final_tail -> next = head1;
            final_tail = final_tail -> next;
            head1 = head1 -> next;
        }
        else
        {
            final_tail -> next = head2;
            final_tail = final_tail -> next;
            head2 = head2 -> next;
        }
    }
    while(head1 != NULL)
    {
        final_tail -> next = head1;
        final_tail = final_tail -> next;
        head1 = head1 -> next;
    }
    while(head2 != NULL)
    {
        final_tail -> next = head2;
        final_tail = final_tail -> next;
        head2 = head2 -> next;
    }
    return final_head;
}

int getNthFromLast(Node *head, int n)
{
    int count = 0;
    Node* temp = head;
    int p = length(head);
    while(temp != nullptr && count<p-n)
    {
        temp = temp -> next;
        count++;
    }
    return temp -> data;
}
Node* swapkthnode(Node* head, int num, int K)
{
    if(K>num)
    {
        return head;
    }
    if(K==(num-K) && num %2 != 0)
    {
        return head;
    }
    Node* front_node = head;
    Node* front_prev;
    if(K==1 || K==num)
    {
        while(front_node->next != nullptr)
        {
            front_prev = front_node;
            front_node = front_node -> next;
        }
        front_node -> next = head -> next;
        front_prev -> next = head;
        head -> next = nullptr;
        head = front_node;
        return head;
    }
    Node* end_node = head;
    Node* end_prev;
    int count = 0;
    int p = num;
    while((front_node -> next != nullptr) && count<K-1)
    {
        front_prev = front_node;
        front_node = front_node -> next;
        count++;
    }
    count = 0;
    while((end_node -> next != nullptr) && count<(p-K))
    {
        end_prev = end_node;
        end_node = end_node -> next;
        count++;
    }
    if(K==(num-K) && num %2 == 0)
    {
        Node* a = front_prev -> next;
        front_prev -> next = front_node -> next;
        front_node -> next = end_node -> next;
        end_node -> next = a;
        return head;
    }
    if(K>(num/2))
    {
        Node* a = front_node;
        front_node = end_node;
        end_node = a;
        Node* b = front_prev;
        front_prev = end_prev;
        end_prev = b;
    }
    front_prev -> next = end_node;
    end_prev -> next = front_node;
    Node* b = end_node -> next;
    end_node -> next = front_node -> next;
    front_node -> next = b;
    return head;
}
Node* reverseList(Node* head)
{
    if((head==nullptr) || (head -> next == nullptr))
    {
        return head;
    }
    Node* temp2 = head;
    Node* new_head = reverseList(head -> next);
    Node* temp = new_head;
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = temp2;
    temp2 -> next = nullptr;
    head = new_head;
    return head;
}
int detectloop(Node *h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return 1;
        s.insert(h);
        h = h->next;
    }
    return 0;
}
int countNodes(Node* head)
{
    Node* temp = head;
    int res = 1;
    while(temp -> next != head)
    {
        res++;
        temp = temp -> next;
    }
    return res;
}
int countNodesinLoop(Node* head)
{
     Node* slow_p = head;
     Node* fast_p = head;
     while(slow_p && fast_p && fast_p -> next)
     {
         slow_p = slow_p -> next;
         fast_p = fast_p -> next -> next;
         if(slow_p == fast_p)
         {
             return countNodes(slow_p);
         }
     }
     return 0;
}
void remove_loop(Node* head)
{
    Node* fast_p = head->next;
    Node* slow_p = head;
    while (fast_p != slow_p)
    {
        fast_p = fast_p->next;
        slow_p = slow_p->next;
        fast_p = fast_p->next;

        if (fast_p == slow_p)
            break;
    }
    Node* temp = head;
    slow_p = slow_p->next;
    while (temp != slow_p)
    {
        temp = temp->next;
        if (slow_p->next == temp)
        {
            slow_p->next = nullptr;
            return;
        }
        slow_p = slow_p->next;
    }
}

Node* rotate(Node* head, int k)
{
    if(head == nullptr)
    {
        return head;
    }
    Node* temp = head;
    Node* prev_temp = nullptr;
    if(k==length(head))
    {
        prev_temp = head;
        while(temp -> next != nullptr)
        {
            prev_temp = temp;
            temp = temp -> next;
        }
        temp -> next = head;
        prev_temp -> next = nullptr;
        return temp;
    }
    for(int i=0;i<k;i++)
    {
        prev_temp = temp;
        temp = temp -> next;
    }
    Node* temp_head = temp;
    while(temp->next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = head;
    prev_temp -> next = nullptr;
    return temp_head;
}
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void swapPointer( Node** a, Node** b )
{
    Node* t = *a;
    *a = *b;
    *b = t;
}

Node* addSameSize(Node* head1, Node* head2,int carry)
{
    if(head1==nullptr)
    {
        return nullptr;
    }
    Node* result = head1;
    int sum;

    result -> next = addSameSize(head1 -> next, head2 -> next,carry);

    sum = head1 -> data + head2 -> data + carry;
    carry = sum/10;
    sum = sum % 10;

    result -> data = sum;

    return result;
}

void addCarryToRemaining(Node* head1, Node* cur, int carry, Node** result)
{
    int sum;
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);

        sum = head1->data + carry;
        carry = sum/10;
        sum %= 10;
        push(result, sum);
    }
}

void addList(Node* head1, Node* head2, Node** result)
{
    Node *cur;
    if (head1 == NULL)
    {
        *result = head2;
        return;
    }
    else if (head2 == NULL)
    {
        *result = head1;
        return;
    }

    int size1 = length(head1);
    int size2 = length(head2) ;

    int carry = 0;
    if (size1 == size2)
        *result = addSameSize(head1, head2,carry);

    else
    {
        int diff = abs(size1 - size2);
        if (size1 < size2)
            swapPointer(&head1, &head2);
        for (cur = head1; diff--; cur = cur->next);
        *result = addSameSize(cur, head2, carry);
        addCarryToRemaining(head1, cur, carry, result);
    }
    if (carry)
        push(result, carry);
}

Node* addTwoLists(Node* first, Node* second)
{
   Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first? first->data: 0) +
                      (second? second->data: 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        temp = new Node(sum);
        if(res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0)
    temp->next = new Node(carry);
    return res;
}

int main()
{
    Node* head1 = take_input();
    Node* head2 = take_input();
    Node* result = nullptr;
    addList(head1,head2,&result);
    print_ll(result);
}
