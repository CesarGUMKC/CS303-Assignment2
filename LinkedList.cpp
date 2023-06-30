#include "LinkedList.h"

using namespace std;


template<typename Item_Type>
void LinkedList<Item_Type>::push_front(const Item_Type& item) {
    Node* newNode = new Node(item);                                           //if list is empty, will have item be head and tail
    if (empty()) {
        head = newNode;
        tail = newNode;
    }
    else {                                                                     //if not empty, new item is at head and points to previous head
        newNode->next = head;
        head = newNode;
    }
    
    numItems += 1;
}

template<typename Item_Type>
void LinkedList<Item_Type>::push_back(const Item_Type& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        head = newNode;
        tail = newNode;                                              //similar to push_front , checks for emptiness, if not new item push to the back of list
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    numItems += 1;
}

template<typename Item_Type>
void LinkedList<Item_Type>::pop_front() {
    if (!empty()) {                                     
        Node* temp = head;                         //checks for emptiness, if not empty, creates temp Node and copies head, node that head pointed to is new head, temp node is deleted
        head = head->next;
        delete temp;
        numItems -= 1;

        if (empty()) {
            tail = nullptr;
        }
    }
}

template<typename Item_Type>
void LinkedList<Item_Type>::pop_back() {
    if (!empty()) {                                    //similar to pop_back, but from the reverse order
        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        numItems -= 1;
    }
}

template<typename Item_Type>
Item_Type LinkedList<Item_Type>::front() const {
    if (!empty()) {                                        //returns element at front of list if not empty
        return head->data;
    }
    return Item_Type();
}

template<typename Item_Type>
Item_Type LinkedList<Item_Type>::back() const {            //returns element at back of list if not empty
    if (!empty()) {
        return tail->data;
    }
    return Item_Type();
}

template<typename Item_Type>
bool LinkedList<Item_Type>::empty() const {                     //will return true or flase depending if numItems is 0 or not
    return numItems == 0;
}

template<typename Item_Type>
void LinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {        //function used to insert item at specific position of list, if empty push it, if index greater than size, push to back, else traverse list to insert into specific position                        
    if (index >= numItems) {
        push_back(item);
    }
    else if (index == 0) {
        push_front(item);
    }
    else {
        Node* newNode = new Node(item);
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        numItems += 1;
    }
}

template<typename Item_Type>
bool LinkedList<Item_Type>::remove(size_t index) {                            //similar to insert buy with inverse functionality
    if (index >= numItems || empty()) {
        return false;
    }

    if (index == 0) {
        pop_front();
    }
    else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = temp->next;
        temp->next = newNode->next;
        delete newNode;
        numItems -= 1;
    }
    return true;

}

template<typename Item_Type>
size_t LinkedList<Item_Type>::find(const Item_Type& item) {                     //function to find item in list, create temp node and compares it data to item parameter passeds
    Node* temp = head;
    size_t index = 0;
    while (temp != nullptr) {
        if (temp->data == item) {
            return index;
        }
        temp = temp->next;
        index += 1;
    }
    return numItems;
}

template<typename Item_Type>
void LinkedList<Item_Type>::clear() {                   //function to clear allocated memory, used in deconstructora
	while (!empty()) {
		pop_front();
	}
}
