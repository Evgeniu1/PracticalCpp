#include "Container.h"
/*----------default constructor---------------*/
List::List() : head(NULL), size(0) {}
/*--------------destructor------------------*/
List::~List()
{
	del_all();
}
/*----------Function to insert new element in list---------------*/
void List::insert(Engine* data)
{
	size++;
	if (head == NULL)
	{
		Node* new_node = new Node;
		new_node->data = data;
		new_node->next = new_node->prev = new_node;
		head = new_node;
		return;
	}
	Node* last = head->prev;
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = head;
	head->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
}
/*----------Function to delete element from list---------------*/
void List::del()
{
	Node* curr = head;
	if (head == NULL)
	{
		cout << "List is empty!" << endl;
		return;
	}
	if (size == 1)
		head = NULL;
	else
	{
		Node* new_node = head->next;
		head = head->prev;
		head->next = new_node;
		new_node->prev = head;
	}
	size--;
	delete curr;
}
/*----------Function to clear list elements---------------*/
void List::del_all()
{
	while (size)
		del();
}
/*----------Function to get size of list---------------*/
int List::get_size() const
{
	return size;
}
/*----------Function to display list elements---------------*/
void List::display()
{
	if (head == NULL)
	{
		cout << "\nContainer is empty!" << endl;
		return;
	}
	Node* temp = head;
	while (temp->next != head)
	{
		temp->data->Print();
		temp = temp->next;
	}
	temp->data->Print();
}

void List::search()
{
	struct Node* temp = head;
	int count = 0, flag = 0;

	if (temp == NULL)
	{
		cout << "List is empty! Nothing to search." << endl;
		return;
	}
	else
	{
		string name;
		cout << "Input marking of engine you wanted to search: ";
		cin >> name;
		while (temp->next != head)
		{
			count++;
			if (temp->data->getMarking() == name)
			{
				flag = 1;
				count--;
				break;
			}
			temp = temp->next;
		}
		if (temp->data->getMarking() == name)
		{
			count++;
			flag = 1;
		}
		if (flag == 1)
			temp->data->Print();
		else
			cout << "\nObject not found" << endl;
	}
}

Engine* List::operator[](int id)
{
	Node* current = head;

	for (int i = 0; i <= id; i++)
	{
		if (i != id)
			current = current->next;
		else
			return current->data;
	}
    return current->data;
}
