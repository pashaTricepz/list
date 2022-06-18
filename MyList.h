#pragma once
#include <iostream>

template<typename T>
struct Node {
	T date = T();
	Node<T>* next;
	Node<T>* prev;
	Node() : next(nullptr), prev(nullptr) {}
};

template<typename T>
struct iterator {
private:
	Node<T>* ptr = nullptr;
public:
	iterator(Node<T>* ptr);
	T& operator* ();
	T* operator-> ();
	iterator<T>& operator++();
	iterator<T>& operator--();
	iterator<T> operator++(int);
	iterator<T> operator--(int);
	friend std::ostream& operator<<(std::ostream &os, const iterator<T>& it);
	bool operator ==(const iterator & right) const;
	bool operator !=(const iterator & right) const;
};

template<typename T>
class MyList {
private: 
	size_t sz;
	Node<T>* head;
	Node<T>* last;
	friend struct iterator<T>;
	void create_first_node(const T& data);
	void remove_node(Node<T>* node);

public:
	using iterator = iterator<T>;

	MyList() : sz(0), head(nullptr), last(nullptr) {};
	void push_front(const T& data);
	void pop_front();
	void push_back(const T& data);
	void pop_back();
	iterator begin();
	iterator end();
	iterator insert(iterator pos, const T& value);
	iterator erase(iterator pos);
	int size();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void clear();
};