#pragma once
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

template<typename Item_Type>
class LinkedList {
public:

	struct Node {
		Item_Type data;
		Node* next;

		Node(const Item_Type& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}          //constructor
	};

	Node* head;
	Node* tail;
	size_t numItems;

public:
	LinkedList() : head(nullptr), tail(nullptr), numItems(0) {}
	~LinkedList() {
		clear();
	}

	void clear();
	void push_front(const Item_Type& item);
	void push_back(const Item_Type& item);
	void pop_front();
	void pop_back();
	Item_Type front() const;
	Item_Type back() const;
	bool empty() const;
	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);
};



