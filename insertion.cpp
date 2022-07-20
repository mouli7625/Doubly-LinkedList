#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//traversing a linked list
void print(Node* head) {
    Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
void insertAtHead(Node* &tail, Node* &head, int d) {

    //empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(Node* &tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
int main()
{
    Node* head=NULL;
    Node *tail=NULL;
    //insert at tail
    insertAtTail(tail,head, 10);
    insertAtTail(tail,head, 30);
    insertAtTail(tail,head, 40);
    print(head);
    //insert at pos
    insertAtPosition(tail,head , 2,20);
    print(head);
    insertAtPosition(tail,head , 1, 50);
    print(head);
    return 0;
}
