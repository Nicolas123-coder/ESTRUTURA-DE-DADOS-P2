// Nicolas de Barros 
// TIA : 32070837

#include <iostream>
#include <clocale>
#include "DoublyCircularLinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{

	Node* tmp = list->GetHead();

	for (int i = 0; i < list->Count(); i++)
	{
		cout << "[" << tmp->id << "]  " << tmp->name << "\n";
		tmp = tmp->next;
	}

	cout << "\n";

}

void PrintListInfo(const LinkedList* list)
{
	if (list->IsEmpty())
	{
	cout << "Lista vazia! (" << list->Count() << ")\n\n";
	}
	else
	{
	cout << "Lista (" << list->Count() << "): \n";
	Print(list);
	}
}

void PrintListInfoAfterInsertion(const LinkedList* list, bool didInsert)
{
	if (didInsert)
	{
	PrintListInfo(list);
	}
	else
	{
	cout << "Não foi possível inserir novo nó na lista!\n\n";
	}
}

void PrintListInfoAfterRemoval(const LinkedList* list, Node* node)
{
 if (node != nullptr)
 {
	cout << "Nó removido -> id: " << node->id << ", name: " << node->name << "\n\n";
	PrintListInfo(list);
 }
 else
 {
	cout << "Não foi possível remover o nó da lista!\n\n";
 }
}

int main()
{
	setlocale(LC_ALL, "pt_BR"); 
	
	cout << "*** ESTRUTURA DE DADOS I - Avaliação Parcial 2 (P2) ***\n\n";

	LinkedList* list = new LinkedList();

	PrintListInfo(list);

	list->Append(1, "Carol");
	list->Append(2, "Eric");
	list->Append(3, "John");

	PrintListInfo(list);

	bool didInsert = list->InsertAfter(5, 4, "Leo");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = list->InsertAfter(2, 4, "Leo");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = list->InsertAfter(2, 5, "Julia");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = list->InsertBefore(4, 6, "Lisa");
	PrintListInfoAfterInsertion(list, didInsert);
	
	Node* temp = list->RemoveNode(99);
	PrintListInfoAfterRemoval(list, temp);
	list->DestroyNode(temp);
	temp = list->RemoveNode(2);

	PrintListInfoAfterRemoval(list, temp);
	list->DestroyNode(temp);
	temp = list->RemoveHead();

	PrintListInfoAfterRemoval(list, temp);
	list->DestroyNode(temp);
	temp = list->RemoveTail();

	PrintListInfoAfterRemoval(list, temp);
	list->DestroyNode(temp);
	list->Clear();

	PrintListInfo(list);
	didInsert = list->InsertAfter(44, 33, "Olga");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = list->InsertBefore(11, 22, "Thomas");
	PrintListInfoAfterInsertion(list, didInsert);

	list->Append(44, "Bia");
	PrintListInfo(list);
	didInsert = list->InsertAfter(44, 55, "Angela");
	PrintListInfoAfterInsertion(list, didInsert);
	didInsert = list->InsertBefore(44, 66, "Karen");
	PrintListInfoAfterInsertion(list, didInsert);

	delete list;
	
	cout << "Fim.\n";

}