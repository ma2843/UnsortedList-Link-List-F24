

template<class T>
UnsortedList<T>::UnsortedList() {
    head = nullptr;
    currPos = nullptr;
    length = 0;


}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    while (currPos != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    length = 0;

}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    Node *currN = head;

    while (currN != nullptr)
    {
        if(someItem == currN->item)
        {
            return true;
        }
        currN = currN->next;
    }

    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {

    Node *newNode = new Node;   // hey computer, give me a memory address on the heap
                                // big enough to store a node
    newHead->value = item;
    newHead->next = head;

    head = newHead;
    ++length;  // bookkeeping variable

}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node *currN = head;
    Node *prevN = nullptr;

    while (currN != nullptr) {
        if(item == currN->item) {
            if (currN != head)
                prevN->next = currN->next;
            else
                head = currN->next;

            delete currN;
            length--;
            return;
        }
        prevN = currN;
        currN = currN->next;
    }

}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;  //Start the iterator at the front of the list
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T currValue = currPos->value;       // get curr value
    currPos = currPos->next;            // move to next item
    return currValue;                   // return curr value
}
