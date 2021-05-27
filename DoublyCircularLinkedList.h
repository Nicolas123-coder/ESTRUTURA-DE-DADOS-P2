// Nicolas de Barros 
// TIA : 32070837

#ifndef __DOUBLY_CIRCULAR_LINKED_LIST_H__
#define __DOUBLY_CIRCULAR_LINKED_LIST_H__

#include <string>

struct Node
{
	int id;
	std::string name;
	Node* next;
	Node* previous;
};

class LinkedList
{
public:
	LinkedList();  
	~LinkedList(); 

	void Insert(int id, std::string name);
	void Append(int id, std::string name);

	bool InsertBefore(int beforeId, int id, std::string name);
	bool InsertAfter(int afterid, int id, std::string name);

	Node* RemoveHead();
	Node* RemoveTail();
	Node* RemoveNode(int value);

	Node* GetHead() const;
	Node* GetTail() const;
	Node* GetNode(int value) const;

	int Count() const;
	bool IsEmpty() const;
	void Clear();

	Node* CreateNode(int id, std::string name, Node* next, Node* previous);
	void DestroyNode(Node* node);

private:
	int count;
	Node* head;
	Node* tail;
};
#endif