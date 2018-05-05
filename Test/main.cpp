#include <iostream>
using namespace std;
template <class T>
class Node {
public:
	Node<T>* next;
	Node<T>* prev;
	T elem;
};

template <class T>
class Linked_List {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Linked_List() {
		front = nullptr;
		rear = nullptr;
	}
	void push_back(T elem) {
		Node<T>* temp = nullptr;
		if (front == nullptr) {
			temp = new Node<T>;
			temp->next = temp;
			temp->prev = temp;
			temp->elem = elem;
			front = temp;
			rear = temp;
		} else {
			temp = new Node<T>;
			temp->next = front;
			temp->prev = rear;
			temp->elem = elem;
			rear->next = temp;
			rear = temp;
		}
	}
	void push_front(T elem) {
		Node<T>* temp = nullptr;
		if (front == nullptr) {
			temp = new Node<T>;
			temp->next = temp;
			temp->prev = temp;
			temp->elem = elem;
			front = temp;
			rear = temp;
		} else {
			temp = new Node<T>;
			temp->prev = rear;
			temp->next = front;
			temp->elem = elem;
			front->prev = temp;
			front = temp;
		}
	}
	void print() {
		Node<T>* temp = front;
		do {
			cout << temp->elem << ' ';
			temp = temp->next;
		} while (temp != front);
		cout << '\n';
	}
};

int main() {
	Linked_List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.print();
	return 0;
}