#include <cstdio>
//BOJ #1406

struct Node {
	Node* next;
	Node* prev;
	char data;
};

class List {
private:	
	Node* cur;
public:
	Node* head;
	Node* tail;
	List() {
		head = new Node;
		head->next = NULL;
		head->prev = NULL;
		head->data = -1;
		tail = head;
		cur = tail;
	}
	void L() {
		if (cur->prev != NULL) {
			cur = cur->prev;
		}
	}
	void D() {
		if (cur->next != NULL) {
			cur = cur->next;
		}
	}
	void B() {
		if (cur->prev == NULL) {
			return;
		}
		Node* tmp = cur->prev;
		cur->prev = NULL;
		if (tmp->prev != NULL) {
			tmp->prev->next = cur;
			cur->prev = tmp->prev;
		}		
		delete tmp;
	}
	void P(char data) {
		Node* tmp = new Node;
		tmp->data = data;
		tmp->prev = NULL;
		tmp->next = cur;
		if (cur->prev != NULL) {
			cur->prev->next = tmp;
			tmp->prev = cur->prev;
		}
		cur->prev = tmp;
	}
};

int main() {
	List l;
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		l.P(c);
		scanf("%c", &c);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char d, m;
		scanf(" %c",&d);
		switch (d) {
		case 'L':
			l.L();
			break;
		case 'D':
			l.D();
			break;
		case 'B':
			l.B();
			break;
		case 'P':
			scanf(" %c", &m);
			l.P(m);
			break;
		}
	}
	Node* temp = l.tail;
	while (temp->prev != NULL) {
		temp = temp->prev;
	}
	while (temp->data != -1) {
		printf("%c", temp->data);
		temp = temp->next;
	}
	return 0;
}