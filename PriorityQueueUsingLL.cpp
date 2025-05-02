#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
	int data;
    	int priority;
    	Node* next;
	Node(int d, int p)
	{
    		data = d;
    		priority = p;
    		next = NULL;
	}
};

int peek(Node** head) 
	{ 
	return (*head)->data; 
	}

void dequeue(Node** head){
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}
void enqueue(Node** head, int d, int p)
{
    Node* start = *head;
    Node* temp = new Node(d, p);
    if (start->priority < p) {
        temp->next = *head;
        *head = temp;
    }
    else {
        while (start->next != NULL && start->next->priority > p) {
            start = start->next;
        }
        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node* head) { 
	return head==NULL; 
	}

int main()
{
    Node* pq = NULL;
    enqueue(&pq, 5, 2);
    enqueue(&pq, 6, 3);
    enqueue(&pq, 7, 0);

    while (!isEmpty(pq)) {
        cout <<"Value to be deleted:"<<peek(&pq)<<endl;
        dequeue(&pq);
    }
    return 0;
}
