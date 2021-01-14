#include <iostream>
using namespace std;

struct queue
{
	int data;
	queue* next;
};

void push(queue** head, queue** tail, int data)
{
	queue* element = new queue;
	element->data = data;
	element->next = NULL;
	if (*tail)
		(*tail)->next = element;
	if (!*head)
		*head = element;
	*tail = element;
}

void pop(queue** head, queue** tail)
{
	if (*head != NULL)
	{
		queue* temp = *head;
		*head = (*head)->next;
		delete temp;
		if (*head == NULL)
			*tail = NULL;
	}
}

void random_queue(queue** head, queue** tail)
{
	int element = 0;
	for (int i = 0; i < 10; i++)
	{
		element = rand() % 51 - 25;
		push(head, tail, element);
	}
}

void calculate(queue** head, queue** tail)
{
	queue* head_tmp = NULL, * tail_tmp = NULL;
	for (; *head != NULL; )
	{
		int data = (*head)->data;
		pop(head, tail);
		if (data % 2 != 0)
			push(&head_tmp, &tail_tmp, data);
	}
	*head = head_tmp;
	*tail = tail_tmp;
}

void print(queue* head)
{
	for (; head != NULL; head = head->next)
		cout << head->data << "  ";
}

void delete_queue(queue** head, queue** tail)
{
	while (*head != NULL)
		pop(head, tail);
}
/*-------------------------------------------------*/
void main()
{
	queue* head = NULL;
	queue* tail = NULL;
	random_queue(&head, &tail);
	print(head);
	calculate(&head, &tail);
	cout << endl;
	print(head);
	delete_queue(&head, &tail);
}