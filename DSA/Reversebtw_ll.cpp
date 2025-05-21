#include <iostream>
#include <cmath> // for pow, optional here

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    // print function
    void printList() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "empty";
        } else {
            while (temp != nullptr) {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }

    int getLength() {
        return length;
    }

    void makeEmpty() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
        length = 0;
    }
    // append node at end of list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
        length++;
    }
    // delete first node
    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }
    // reverse between m and n
    void reverseBetween(int m, int n) {
        if (length == 0) {
            return;
        }
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;
        for (int i = 0; i < m; i++) {
            prev = prev->next;
        }
        Node* current = prev->next;
        for (int i = 0; i < (n - m); i++) {
            Node* temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        head = dummy->next;
        delete dummy;
    }
};


int main() {
    // Create a linked list with a binary number: 1 -> 0 -> 1 (binary for 5)
    LinkedList myList(1);
    myList.append(0);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    cout << "Linked List: ";
    myList.printList();
    myList.reverseBetween(2, 4);
    myList.printList();

    return 0;
}
