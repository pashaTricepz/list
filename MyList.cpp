#include "MyList.h"
template<typename T>
void MyList<T>::create_first_node(const T& date) {
	head = new Node<T>;
	head->date = date;
	last = head;
}

template<typename T>
void MyList<T>::remove_node(Node<T>* node) {
	Node* prev = node->prev;
	Node* next = node->next;
	// указатель у предыдущей, на следующую (после удаляемой), становится слудующей у удаляемой
	if (prev != nullptr) prev->next = next;
	// указатель у следующей, после удаляемой, на предыдущую, становится предыдущий у удаляемой
	if (next != nullptr) next->prev = prev;

	//если удаляем голову, то следующий элемент становится головой
	if (node == head) head = next;
	//если удаляемый элемент последний, то предыдущий становится последним
	if (node == last) last = prev;

	delete node;
	--sz;
}

template<typename T>
void MyList<T>::push_front(const T& data) {
	//если лист не пуст
	if (head) {
		Node<T>* newNode = new Node<T>;
		newNode->date = data;

		//следующая нода равна старому хеду
		newNode->next = head;
		//для старой головы(первой ноды) предыдущей будет являтся новая нода
		head->prev = newNode;
		//голова равна новой ноде
		head = newNode;
	}
	else {
		create_first_node(data);
	}
	sz++;
}

template<typename T>
void MyList<T>::pop_front() {
	//если лист пуст
	if (!head) return;
	//если лист не состоит из одного элемента(после головы есть элемент)
	if (head->next) {
		Node* next = head->next;
		//у следующей ноды, которая после головы, затираем указатель на предыдущую ноду(т.е на голову)
		next->prev = nullptr;

		delete head;
		//новая голова равна следующей ноде
		head = next;
	}
	//иначе лист состоит из одного элемента
	else {
		delete head;
		head = last = nullptr;
	}
	--sz;
}

template<typename T>
void MyList<T>::push_back(const T& data) {
	//если лист не пуст
	if (last) {
		Node<T>* newNode = new Node<T>;

		newNode->date = data;
		//предыдущая нода для новой, будет старый ласт
		newNode->prev = last;
		//для старого ласт новая нода будет next
		last->next = newNode;
		//последним элементом становится новая нода
		last = newNode;
	}
	else {
		create_first_node(data);
	}
	++sz;
}

template<typename T>
void MyList<T>::pop_back() {
	//если нет последнего элемента
	if (!last) return;
	//если список состоит не из одного элемента
	if (last->prev) {
		Node* prev = last->prev;
		//у предыдущей ноды теперь нет следующего элемента
		prev->next = nullptr;

		delete last;
		//новый ласт
		last = prev;
	}
	else {
		delete last;
		last = head = nullptr;
	}
	--sz;
}

template<typename T>
iterator<T>::iterator(Node<T>* ptr) : ptr(ptr) {}

template<typename T>
T& iterator<T>::operator*() {
	return ptr->date;
}

template<typename T>
T* iterator<T>::operator->() {
	return &(ptr->date);
}

template<typename T>
typename iterator<T>& iterator<T>::operator++() {
	ptr = ptr->next;
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const iterator<T>& it) {
	return os << it.date;
}

template<typename T>
typename iterator<T>& iterator<T>::operator--() {
	ptr = ptr->prev;
	return *this;
}

template<typename T>
bool iterator<T>::operator==(iterator<T> const& right) const {
	return ptr == right.ptr;
}

template<typename T>
bool iterator<T>::operator!=(iterator<T> const& right) const {
	return !(ptr == right.ptr);
}

template<typename T>
typename MyList<T>::iterator MyList<T>::begin() {
	return head;
}

template<typename T>
typename MyList<T>::iterator MyList<T>::end() {
	return last->next;
}

template<typename T>
typename MyList<T>::iterator MyList<T>::insert(iterator pos, const T& value) {
	if (head == pos.ptr) {
		push_front(value);
		return this->begin();
	}
	if (last == pos.ptr) {
		push_back(value);
		return this->end();
	}
	if (!head) {
		create_first_node(value);
		return this->begin();
	}
	Node<T>* newNode = new Node<T>;
	Node<T>* next = pos.ptr->next;
	Node<T>* prev = pos.ptr->prev;

	newNode->prev = prev->next;
	newNode->next = pos.ptr;
	newNode->date = value;
	//у предыдущей новый некст
	prev->next = newNode;
	//у данной позиции новый предыдущий
	pos.ptr->prev = newNode;
	++sz;
	return newNode;
}

template<typename T>
typename MyList<T>::iterator MyList<T>::erase(iterator pos) {
	if (head == pos.ptr) {
		pop_front();
		return this->begin();
	}
	if (last == pos.ptr) {
		pop_back();
		return this->end();
	}
	if (!head) {
		return nullptr;
	}
	if (head == last) {
		pop_back();
		return nullptr;
	}
	Node<T>* next = pos.ptr->next;
	Node<T>* prev = pos.ptr->prev;
	//у предыдущего относительно удаляемого, меняем некст
	prev->next = next;
	//у следующего относительно удаляемого, меняем предыдущий
	next->prev = prev;

	delete pos.ptr;
	--sz;
	return prev;
}

template<typename T>
int MyList<T>::size() {
	return sz;
}

template <typename T>
bool MyList<T>::empty() const {
	return head == nullptr;
}

template <typename T>
const T& MyList<T>::front() const
{
	if (empty()) {
		throw std::out_of_range("List<Type>::top: empty stack");
	}
	return head->date;
}

template <typename T>
const T& MyList<T>::back() const
{
	if (empty())
	{
		throw std::out_of_range("List<Type>::top: empty stack");
	}
	return last->date;
}

template <typename T>
void MyList<T>::clear()
{
	while (--sz) {
		pop_back();
	}
}