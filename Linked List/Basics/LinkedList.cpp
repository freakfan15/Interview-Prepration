#include <iostream>
using namespace std;
#include "Node.cpp"

//reverse ll
Node* reverse(Node* head){
    if(head == NULL ||head->next==NULL){
        return head;
    }
    
    Node* newHead = reverse(head->next);
	head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

//INSERT node at ith index
Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}

//IN O(n) time
Node* takeInpu_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}

//in O(n2) time
Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
		}
		else {
			Node *temp = head;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			temp -> next = newNode;
		}

		cin >> data;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

//length recursive
int length(Node *head) {
    // Write your code here
    if(head==NULL){
        return 0;
    }
    
    return 1 + length(head->next);
}

//length iterative
int lengthI(Node *head)
{
    //Write your code here
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    
    return len;
}

//delete node at ith index
Node *deleteNode(Node *head, int pos)
{
    
    Node* temp = head;
    int cnt = 0;

    if(temp!=NULL && pos == 0){
        head = head->next;
        delete temp;
        return head;
    }

    while(temp!=NULL && cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp!=NULL && temp->next!=NULL){
        Node* a = temp->next;
        temp->next = a->next;
        delete a; 
    }

    return head;
}

int main() {

	Node *head = takeInpu_Better();
	head = reverse(head);
	print(head);

	// int i, data;
	// cin >> i >> data;
	// head = insertNode(head, i, data);
	// print(head);

	
	/*
	// Statically
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);

ee	print(head);
	*/
	/*
	// Dynamically
	Node *n3 = new Node(10);
	Node *head = n3;
	
	Node *n4 = new Node(20);
	n3 -> next = n4;

	*/

}

