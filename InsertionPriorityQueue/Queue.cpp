#include "Queue.h"

void Queue::Print()
{
	Node* current = head;
	for (int i = 0; current != nullptr; i++)
	{
		printf("%d: %d (priority %d)\n", i + 1, current->data, current->priority);
		current = current->next;
	}
}

void Queue::Push(int val, int priority)
{
	Node* _curr = head;
	Node* _prev = nullptr;

	Node* newnode = new Node();
	newnode->priority = priority;
	newnode->data = val;

	while (true)
	{
		/*first queue element*/
		if (head == nullptr)
		{
			head = newnode;
			tail = newnode;
			return;
		}

		/*add element with existing priority*/
		else if (priority == _curr->priority)
		{
			if (_curr == head)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				_prev->next = newnode;
				newnode->next = _curr;
			}
			return;
		}

		/*add new priority to back*/
		else if (priority > tail->priority)
		{
			tail->next = newnode;
			tail = newnode;
			return;
		}

		/*add element with new priority in middle*/
		else if (priority < _curr->priority)
		{
			_prev->next = newnode;
			newnode->next = _curr;
			return;
		}

		/*continue loop*/
		_prev = _curr;
		_curr = _curr->next;
	}
}

void Queue::Pop()
{
	Node* _curr = head;

	if (head == nullptr)
		return;

	head = head->next;
	delete _curr;
	return;
}

void Queue::Pop(int priority)
{
	Node* _curr = head;
	Node* _prev = nullptr;

	while (_curr != nullptr)
	{
		if (_curr == head && priority == head->priority)
		{
			head = head->next;
			delete _curr;
			return;
		}
		else if (priority == _curr->priority)
		{
			_prev->next = _curr->next;
			delete _curr;
			return;
		}
		else
			return;

		_prev = _curr;
		_curr = _curr->next;
	}
}