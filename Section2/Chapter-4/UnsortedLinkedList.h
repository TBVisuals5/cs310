#include "UnsortedLinkedList.h"

class SortedLinkedList : public UnsortedLinkedList {

    public:
        SortedLinkedList(): UnsortedLinkedList() {}
        // ~SortedLinkedList();
        void Insert(ItemType* item) overide {

            Node* newNode = new Node(item);
            Node* current = listData;
            Node* prev = nullptr;

            while (current != nullptr && current->item->LessThan(*item)) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                newNode->next = listData;
                listData = newNode
            }
            else{
                newNode->next = current;
                prev->next = newNode;
            }
        }

        void Remove(ItemType & item ) override{
            
        }
};