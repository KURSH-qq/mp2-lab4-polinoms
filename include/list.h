#pragma once
#include <iostream>
using namespace std;

template <class T>
class TList {
private:
	struct node
	{
		node* next;
		T data;
		node(T _data, node* next = nullptr) :data(_data), next(next) {}
		
		node(const node& n) :next(n.next), data(n.data) {}

		node& operator=(const node& n) {
			if (n == this) {
				return *this;
			}
			next = n.next;
			data = n.data;
			return *this;
		}
	};

	node* head;
	node* tail;
	int size;

public:
	TList():head(nullptr), tail(nullptr),size(0){}
	

	TList(const TList& l) {
		size = l.size;
		head = new node(l.head->data, l.head->next);
		node* cur = head;
		node* tmp = l.head->next;
		while (tmp != nullptr) {
			cur->next = new node(tmp->data, tmp->next);
			cur = cur->next;
			tmp = tmp->next;
		}
		tail = cur;
	}

	TList& operator=(const TList& l) {
		if (this == &l) {
			return *this;
		}
		size = l.size;
		node* cur = head;
		node* tmp;
		while (cur != nullptr) {
			tmp = cur->next;
			delete cur;
			cur->next = tmp;
		}
		head = new node(l.head->data, l.head->next);
		cur = head;
		tmp = l.head->next;
		while (tmp != nullptr) {
			cur->next = new node(tmp->data, tmp->next);
			cur = cur->next;
			tmp = tmp->next;
		}
		tail = cur;
		return *this;
	}

	void pop(int index) {
		node* cur = head;
		node* tmp;
		int count = 0;
		if (index<0 || index>=size) {
			throw exception("wrong idnex");
		}
		else if (index == 0) {
			head = head->next;
			delete cur;
			size -= 1;
		}
		else {
			while (cur != nullptr) {
				if (index != 1) {
					cur = cur->next;
					index -= 1;
				}
				else {
					tmp = cur->next->next;
					delete cur->next;
					size -= 1;
					cur->next = tmp;
					return;
				}
			}
		}
	}


	T& operator[](int index) {
		node* cur = head;
		while (cur != nullptr) {
			if (index != 0) {
				cur = cur->next;
				index -= 1;
			}
			else {
				return cur->data;
			}
		}
	}

	const T& at(int index) const{
		node* cur = head;
		if (index < 0 || index >= size) {
			throw exception("wrong index");
		}
		while (cur != nullptr) {
			if (index != 0) {
				cur = cur->next;
				index -= 1;
			}
			else {
				return cur->data;
			}
		}
	}

	inline bool isEmpty() const {
		return head == nullptr;
	}

	inline int getSize() const {
		return size;
	}

	void push(T data) {
		node* cur = head;
		node* tmp;
		if (isEmpty()) {
			head = new node(data);
			tail = head;
			size += 1;
		}
		else if (data <= tail->data) {
			tail->next = new node(data);
			tail = tail->next;
			size += 1;
		}
		else {
			while (cur != nullptr) {
				if (cur->data < data) {
					if (cur == head) {

						tmp = cur;
						cur = new node(data);
						cur->next = tmp;
						head = cur;
						size += 1;
						while (cur->next != nullptr) {
							cur = cur->next;
						}
						tail = cur;
						break;
					}
					else {

						tmp = new node(cur->data, cur->next);
						cur->data = data;
						cur->next = tmp;
						size += 1;
						while (cur->next != nullptr) {
							cur = cur->next;
						}
						tail = cur;
						break;
					}
				}
				else {
					cur = cur->next;
				}
			}
		}
	}

	class iterator
	{
	private:
		node* cur;
	public:
		iterator(node* node): cur(node){}
		iterator(const iterator& i):cur(i.cur){}
		T& operator*() {
			return cur->data;
		}
		bool operator ==(iterator i) {
			return cur == i.cur;
		}
		bool operator !=(iterator i) {
			return cur != i.cur;
		}
		iterator operator+(const int i) {
			iterator result(*this);
			return result++;
		}
		iterator& operator++(int) {
			cur = cur->next;
			return *this;
		}
		iterator& operator++() {
			cur = cur->next;
			return *this;
		}
	};

	iterator begin() const {
		return iterator(head);
	}

	iterator end() const {
		return iterator(nullptr);
	}
	
	friend ostream& operator<<(ostream& ostr, const TList& l) {
		node* cur = l.head;
		while (cur != nullptr) {
			ostr << cur->data << " ";
			cur = cur->next;
		}
		ostr << endl;
		return ostr;
	}
	
	~TList() { 
		node* cur = head;
		node* tmp;
		while (cur != nullptr) {
			tmp = cur->next;
			delete cur;
			cur = tmp;
		}
	}
};