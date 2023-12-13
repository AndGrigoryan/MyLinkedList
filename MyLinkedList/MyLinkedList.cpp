#include <iostream>

template <typename T>
class MyList
{
public:
	MyList();
	~MyList();

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void clear();
	int get_size();
	T& operator[](const int index);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head;
};

template<typename T>
MyList<T>::MyList()
{
	size = 0;
	head = nullptr;
}

template<typename T>
MyList<T>::~MyList()
{
	clear();
}

template<typename T>
void MyList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
T& MyList<T>::operator[](const int index)
{
	int cnt = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (cnt == index)
		{
			return current->data;
		}
		current = current->pNext;
		cnt++;
	}
}

template<typename T>
void MyList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void MyList<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void MyList<T>::clear()
{
	while (size) 
	{
		pop_front();
	}
}

template<typename T>
int MyList<T>::get_size()
{
	return this->size;
}


template<typename T>
void MyList<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{

		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext);

		size++;
	}

}

template<typename T>
void MyList<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else if (index == this->size - 1)
	{
		pop_back();
	}
	else if (index > 0 && index < this->size)
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}
}

template<typename T>
void MyList<T>::pop_back()
{
	removeAt(size - 1);
}

int main()
{
	MyList<int> lst;

	int numbers_count = 0;
	std::cout << "Enter count of numbers: ";
	std::cin >> numbers_count;

	for (int i = 0; i < numbers_count; i++)
	{
		lst.push_back(rand() % 10);
	}

	for (int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << " ";
	}

	std::cout << std::endl << lst.get_size() << std::endl;

	lst.removeAt(6);

	std::cout << std::endl;

	for (int i = 0; i < lst.get_size(); i++)
	{
		std::cout << lst[i] << " ";
	}

	std::cout << std::endl << lst.get_size() << std::endl;

	return 0;

}
