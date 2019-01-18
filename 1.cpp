//Library
#include <iostream>
using namespace std;
class Node {
    public:
    //Data 
    int data;
    //Pointer to the next Node
    Node * next;
    //Construct that makes the ptr to NULL
    Node() {
        next = NULL;
    }
}
class LinkedList {
    //Head + Circles inside linked with each other
    public:
    //Head -> Node type ptr
    Node * head;
    Node * tail;
    //Construct
    LinkedList() {
        head = NULL;
        tail = NULL;
    } 
    //Circles inside linked with each other
    //Rules how circles will be linked
    //Insert
  int countItems() {
        //Counter
        int i = 1;
        Node * current = head;
        //Running till last element and incrementing counter for every element
        while (current -> next != NULL) {
            i++;
            current = current -> next;
        }
	//Returning count value of last element
        return i;
    }
    void insert(int value) {
       //If 1st Node is added
       Node * temp = new Node; 
       //Insert value in the node
       temp -> data = value;
       //1st Node only
       if(head == NULL) {
            head = temp;
       }
       //Any other Node only
       else {
            tail -> next = temp;
       }
       tail = temp;
    } 
    void insertAt(int pos, int value) {
        //Put it in position only if position exists in linked list;
        if (pos <= countItems() + 1) {
        //Reach place before pos
        Node * current = head;
        int i = 1;
        current = head;
        while(i < pos - 1) {
            i++;
            current = current -> next;
            }
        //Create node
        Node * temp = new Node;
        temp -> data = value;
        // Moving ptrs like magic ! if not head
        temp -> next = current -> next;
        current -> next = temp;
        // Update code for 1st position
        }
       else {
            cout << "There is no such position in the linked list." << endl;
        }
    }
    // Deletion of last element
    void delete() {
        //Store tail in temp
        Node * temp = tail;
        //Before tail has to point to null
        Node * current = head;
        while(current -> next != tail) {
            current = current -> next;
        }
        current -> next = NULL; 
        //Update tail
        tail = current;
        //Delete temp
         delete temp;
    }
  //Deletion of particuar element
    void deleteAt(int pos) {
        Node * current = head;
        for (int i = 1; i < pos - 1; i++) {
            current = current -> next;
        }
        Node * temp = current -> next;
        current -> next = temp -> next;
    }
    //Display
    void display() {
        Node * current = head;
        while(current != NULL){
            cout << current -> data << "->";
            current = current -> next;
        }
        cout << endl;
    }
}
int main() {
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();
    l1.deleteAt(2);
    l1.display();
    cout << l1.countItems() << endl;
    l1.insertAt(2, 8);
    l1.display();
    return 0;
}
