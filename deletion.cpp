#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node* prev;
    //constructor
    Node(int d)
    {
        this->val=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(Node* &tail, Node* &head, int d)
{
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void deleteNode(int pos, Node* &head)
{
    if(pos==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
    }
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(tail,head, 3);
    insertAtTail(tail,head, 4);
    insertAtTail(tail,head, 5);
    print(head);
    deleteNode(2, head);
    print(head);


    return 0;
}