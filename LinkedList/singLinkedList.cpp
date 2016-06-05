#include<iostream>
#include<vector>

using namespace std;

struct Node{
	int val;
	Node * next;
	Node(int val):val(val),next(NULL){}
};


Node* createListByHead(){
	int v=0;
	Node *dummy = new Node(0);
	Node *curr = dummy,*node;
	for(int i=0;i<16;i++){
		node = new Node(i);	
		curr->next = node;
		curr = node;
	}	
	return dummy->next;
}

Node* createListByTail(){
	return NULL;
}

void printList(Node* head){
	Node* tmp = head;
	while(tmp != NULL){
		cout<<tmp->val<<",";
		tmp = tmp->next;
	}
	cout<<endl;
}

Node* reverseList(Node *head){
	Node *prev = NULL,*curr= head,*next;		
	while(curr != NULL){
		next = curr->next;	
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;	
}

Node* findMidNode(Node *head){
	if(head == NULL) return head;
	Node *slow = head,*fast = head;
	while(slow->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;	
	}
	return slow;
}

Node* merge(Node *head1,Node *head2){
	Node *p1 = head1,*p2 = head2;
	Node *dummy = new Node(0),*curr = dummy,*node; 
	while(p1 != NULL && p2 != NULL){
		if(p1->val > p2->val){
			node = new Node(p2->val);
			p2 = p2->next;
		}else{
			node = new Node(p1->val);
			p1 = p1->next;
		}
		curr->next = node;
		curr = node;
	}
	if(p1 != NULL) curr->next = p1;
	if(p2 != NULL) curr->next = p2;
	return dummy->next;		
}
int main(){
	Node* head = createListByHead();
	Node* head2 = createListByHead();
	Node* head3 = merge(head,head2);
	printList(head3);
	return 0;
}
