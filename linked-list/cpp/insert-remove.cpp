/* Linked List Implementation in C++
 * Author: Shruti Gandhi
 * Functions: Insert and delete */
#include <iostream>

using namespace std;

//Definition of a singly linked-list
class ListNode {
  int val;
  ListNode* next;
  friend class LinkedList;  //provide LinkedList class access to ListNode
public:
  ListNode(int x); //constructor declaration
};

ListNode::ListNode(int x) : val(x), next(NULL) {} // constructor definition for ListNode

class LinkedList {
  ListNode* head; // private pointer for linkedlist
public:
  LinkedList(); //empty linkedlist constructor declaration
  ~LinkedList(); //destructor declaration
  bool empty() const; //is linkedlist empty
  int listLength() const; //length of linkedlist declaration
  ListNode* insertAtTail(int data); //insert data at tail of linkedlist declaration
  ListNode* insertAtIndex(int data, int index); //inserts data at index of linkedlist declaration
  ListNode* removeVal(int data); //deletes data from linkedlist declaration
  ListNode* removeAtHead(); //deletes element from head of linkedlist declaration
  ListNode* removeAtTail(); //deletes element from tail of linkedlist declaration
  ListNode* removeAtIndex(int index); // deletes element from index if exists declaration
  void printList(); //prints LinkedList declaration
};

// linkedlist constructor definition
LinkedList::LinkedList() : head(NULL) {}

// linkedlist destructor definition
LinkedList::~LinkedList() {
  while(!empty()) {
    removeAtTail();
  }
}

// returns true if head is NULL else false
bool LinkedList::empty() const {
  if(!head) {
    return true;
  } else {
    return false;
  }
}

// returns length of linkedlist
int LinkedList::listLength() const {
  int length = 0;
  if(!empty()) {
    ListNode* curr = head;
    // increment curr pointer till the tail is reached
    while(curr) {
      length++;
      curr = curr->next;
    }
  }
  return length;
}

// insert element at tail
ListNode* LinkedList::insertAtTail(int data) {
  ListNode* curr = head;
  // create a new node if linkedlist is empty
  if(empty()){
    head = new ListNode(data);
  } else {
    while(curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new ListNode(data);
  }
  return head;
}

ListNode* LinkedList::insertAtIndex(int data, int index) {
  if(empty()) {
    return head;
  }
  if(index == 0) {
    ListNode* temp = head;
    head = new ListNode(data);
    head->next = temp;
    return head;
  } else if (index == listLength() - 1) {
    insertAtTail(data);
  } else {
    ListNode* curr = head;
    int curr_index = 0;
    while(curr_index < index - 1) {
      curr = curr->next;
      curr_index++;
    }
    ListNode* temp = curr->next;
    curr->next = new ListNode(data);
    curr->next->next = temp;
    return head;
  }
}

ListNode* LinkedList::removeAtTail() {
  if(!head || !head->next) {
    head = NULL;
    return head;
  }
  // removes the element at tail in a linkedlist
  if(!empty() && listLength() > 1) {
    ListNode* curr = head;
    ListNode* temp;
    while(curr->next) {
      temp = curr;
      curr = curr->next;
    }
    temp->next = NULL;
    curr = temp;
    return head;
  }

}

ListNode* LinkedList::removeAtHead() {
  // removes the element at head in a LinkedList
  if(!empty() && listLength() > 1) {
    ListNode* curr = head;
    head = curr->next;
    return head;
  }
  if(listLength() == 1) {
    head = NULL;
    return head;
  }
}

ListNode* LinkedList::removeAtIndex(int index) {
  if(empty()) {
    return NULL;
  } else if(index == 0) {
    removeAtHead();
  } else if(index == listLength() - 1) {
    removeAtTail();
  } else {
    ListNode* curr = head;
    int curr_index = 0;
    while(curr_index < index - 1) {
      curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
  }
}

ListNode* LinkedList::removeVal(int data) {
  ListNode* curr = head;
  if(empty()) {
    return NULL;
  } else if(head->val == data) {
    removeAtHead();
  } else {
    while(curr->next) {
      if(curr->next->val == data) {
        curr->next = curr->next->next;
        return head;
      } else {
        curr = curr->next;
      }
    }
  }
}

// Prints all elements in the list
void LinkedList::printList() {
  ListNode* temp = head;
  int index = 0;
  while(temp && temp->next) {
    cout << temp->val << "->";
    index++;
    temp = temp->next;
  }
  // print the last element in the list
  if(temp) {
    cout << temp->val << endl;
  } // print the message if list empty
  else if(empty()) {
    cout << "List is empty\n";
  }
  return;
}

int main() {
  LinkedList test_list;
  test_list.insertAtTail(1);
  test_list.insertAtTail(100);
  test_list.insertAtIndex(200,0);
  test_list.insertAtIndex(500,3);
  test_list.printList();
  test_list.removeVal(500);
  test_list.removeAtHead();
  test_list.removeAtTail();
  test_list.printList();
  test_list.removeAtIndex(0);
  test_list.printList();
}
