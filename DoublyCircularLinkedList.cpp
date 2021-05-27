// Nicolas de Barros 
// TIA : 32070837

#include "DoublyCircularLinkedList.h"

LinkedList::LinkedList()
	: count(0)
	, head(nullptr)
	, tail(nullptr)
{
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Insert(int id, std::string name)
{
	Node* node = CreateNode(id, name, head, nullptr);
	if (IsEmpty())
	{
		tail = node;
		head = node;
	}
	else
	{
		head->previous = node;
		head = node;
	}
	count++;
}

void LinkedList::Append(int id, std::string name)
{
	Node* node = CreateNode(id, name, nullptr, tail);
	if (IsEmpty())
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
	count++;
}

bool LinkedList::InsertBefore(int beforeId, int id, std::string name) // O (n)
//O tempo de execução deste algoritmo, usando a notação Big-O, é de O (n), pois existe apenas um loop
//no código (for/while, etc...) fazendo com que o tempo dele dependa do numero de vezes que o loop rpda.
//Se tivesse um loop encadeado, o tempo iria mudar para n.n, ou seja, O (n^2).
{
	if (IsEmpty())
		return false;

	Node* node = CreateNode(id, name, nullptr, nullptr);
	Node* aux = head;

	while (aux != tail)
	{
		if (aux->id == beforeId)
		{
			break;
		}
		
		aux = aux->next;	
	}

	if (aux == tail && aux->id != beforeId)
	{
		delete node;
		return false;
	}

	node->previous = aux->previous;
	aux->previous = node;
	node->next = aux;
	if (node->previous != nullptr)
		node->previous->next = node;
	else
		head = node;
	count++;
	return true;
}

bool LinkedList::InsertAfter(int afterId, int id, std::string name) // O (n)

//O tempo de execução deste algoritmo, usando a notação Big-O, é de O (n), pois existe apenas um loop
//no código (for/while, etc...) fazendo com que o tempo dele dependa do numero de vezes que o loop rpda.
//Se tivesse um loop encadeado, o tempo iria mudar para n.n, ou seja, O (n^2).
{
if (IsEmpty())
		return false;
	
	Node* node = CreateNode(id, name, nullptr, nullptr);
	Node* aux = head;

	while (aux != tail)
	{
		if (aux->id == afterId)
		{
			break;
		}

		aux = aux->next;
	}

	if (aux == tail && aux->id != afterId)
	{
		delete node;
		return false;
	}

	node->next = aux->next;
	aux->next = node;
	node->previous = aux;
	if (node->next != nullptr)
		node->next->previous = node;
	else
		tail = node;
	count++;
	return true;
}

Node* LinkedList::RemoveHead()
{
	if (IsEmpty())
	{
		return nullptr;
	}

	Node* toRemove = head;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		head->previous = tail;
	}
	count--;

	toRemove->next = toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveTail()
{
	if (head == tail)
		return RemoveHead();

	Node* toRemove = tail;
	tail->previous->next = head;
	tail = tail->previous;
	head->previous = tail;

	count--;
	toRemove->next = toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveNode(int value)
{
	Node* toRemove = head;
	Node* previous = nullptr;
	while (toRemove != nullptr && toRemove->id != value)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == head)
		return RemoveHead();
	else if (toRemove == tail)
		return RemoveTail();
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;
		toRemove->next->previous = previous;

		--count;

		toRemove->next = toRemove->previous = nullptr;
		return toRemove;
	}

	return nullptr;
}

Node* LinkedList::GetHead() const
{
	return head;
}

Node* LinkedList::GetTail() const
{
	return tail;
}

Node* LinkedList::GetNode(int value) const
{
	Node* node = head;
	while (node != nullptr)
	{
		if (node->id == value)
			return node;
		node = node->next;
	}
	return nullptr;
}

int LinkedList::Count() const
{
	return count;
}

bool LinkedList::IsEmpty() const
{
	return ((head == nullptr) && (tail == nullptr)) || (count == 0);
}

void LinkedList::Clear()
{
	Node* node = head;
	Node* next = nullptr;

	for (int i = 0; i < count; ++i)
	{
		next = node->next;
		delete node;
		node = next;
	}
	head = tail = nullptr;
	count = 0;
}

Node* LinkedList::CreateNode(int id, std::string name, Node* next, Node* previous)
{
	Node* node = new Node;
	node->id = id;
	node->name = name;
	node->next = next;
	node->previous = previous;
	return node;
}

void LinkedList::DestroyNode(Node* node)
{
	delete node;
}