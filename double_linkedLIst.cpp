#include <bits/stdc++.h>
using namespace std;


struct node{
	int val;
	node* next;
	node* back;

	node(int data){
		val = data;
		next = NULL;
		back = NULL;
	}
};

node* convertDll(vector<int> &v){
	node* head = new node(v[0]);

	node* prev = head;

	for(int i=1;i<v.size();i++){
		node* t = new node(v[i]);
		t->back = prev;
		prev->next = t;
		prev = t;
	}

	return head;
}

node* deleteTail(node* head){
	if(head == NULL || head->next == NULL){
		return NULL;
	}

	node* tail = head;

	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->back->next = NULL;
	tail->back = NULL;

	return head;
}

node* remove(node* head,int k){
	if(head == NULL){
		return NULL;
	}
	if(k == 1){
		head = head->next;
		head->back = NULL;
		return head;
	}
	else{
		int ct  = 0;
		node* t = head;
		while(t != NULL){
			ct++;
			if(ct == k){
				if(t->next == NULL){
					t->back->next = NULL;
					t->back = NULL;
					delete t;
					return head;
				}
				else{
					t->back->next = t->next;
					t->next->back = t->back;

					t->back = NULL;
					t->next = NULL;
					delete t;
					return head;
				}
			}
			t = t->next;
		}
		return head;
	}
}

node* insertBeforeHead(node* head,int x){
	node* newHead = new node(x);
	newHead->next = head;
	head->back = newHead;
	return newHead;
}

void printll(node* head){
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
}

int main(){
	vector<int> v = {4,3,2,6};

	node* head = convertDll(v);
	// head = deleteTail(head);
	// head = remove(head,3);

	head = insertBeforeHead(head,1);
	printll(head);
}
