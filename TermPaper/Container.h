#ifndef TERM_PAPER_CONTAINER_H
#define TERM_PAPER_CONTAINER_H

#include "Turbojet.h"
#include "Piston.h"

struct Node
{
	Engine* data;
	Node* next, * prev;
};

class List
{
private:
	Node* head;
	int size;
public:
	List();
	~List();

	void insert(Engine* data);
	void del();
	void del_all();
	int get_size() const;
	void display();
	void search();
	Engine* operator[](int id);
};

#endif