/*Code to remove duplicates from an unsorted linked list
  Author: Shruti*/

#include <iostream>
#include <unordered_set>

using namespace std;

// Definition of a singly linkedlist
class ListNode {
  int val;
  ListNode* next;
  friend class LinkedList;
 public:
  ListNode(int x);
};

ListNode::ListNode(int x) : val(x), next(NULL) {};

class LinkedList {
    ListNode* head;
  public:
    LinkedList();
    ~LinkedList();
    ListNode* insertAtTail(int data);
    ListNode* removeAtTail();
    ListNode* removeDups();
    ListNode* removeDupsWithoutBuffer();
    void printList();
};

LinkedList::LinkedList() : head(NULL) {};

LinkedList::~LinkedList() {
  while(head) {
    removeAtTail();
  }
}

ListNode* LinkedList::insertAtTail(int data) {
  ListNode* curr = head;
  if(!head) {
    head = new ListNode(data);
  } else {
    while(curr->next) {
      curr = curr->next;
    }
    curr->next = new ListNode(data);
  }
  return head;
}

ListNode* LinkedList::removeAtTail() {
  if(!head || !head->next) {
    head = NULL;
    return head;
  } else {
    ListNode* prev = head;
    ListNode* curr = head->next;
    while(curr->next) {
      curr = curr->next;
      prev = prev->next;
    }
    prev->next = NULL;
  }
  return head;
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
  else if(!head) {
    cout << "List is empty\n";
  }
  return;
}

// Remove dups using a temporary buffer
ListNode* LinkedList::removeDups() {
  if(!head || !head->next) {
    return head;
  }
  // use unordered_set to store unique elements in the list
  // all the subsequent elements that can be found in the set are duplicates
  unordered_set<int> temp;
  ListNode* curr = head->next;
  ListNode* prev = head;
  temp.insert(head->val);
  while(curr) {
    if(temp.find(curr->val) == temp.end()) {
      temp.insert(curr->val);
      curr = curr->next;
      prev = prev->next;
    } else {
      prev->next = curr->next;
      curr = curr->next;
    }
  }
  return head;
}

// Remove dups without a temp buffer
ListNode* LinkedList::removeDupsWithoutBuffer() {
  if(!head || !head->next) {
    return head;
  }
  // use slow pointer that iterates through the list
  // use curr pointer to check for duplicates
  // use prev pointer to update the list after node removal
  ListNode* slow = head;
  ListNode* prev = head;
  ListNode* curr = head->next;
  while(slow) {
    while(curr){
      if(curr->val != slow->val) {
        curr = curr->next;
        prev = prev->next;
      } else {
        prev->next = curr->next;
        curr = curr->next;
      }
    }
    if(!slow->next) {
      break;
    } else {
      slow = slow->next;
      curr = slow->next;
      prev = slow;
    }
  }
  return head;
}

int main() {
  LinkedList test_list;
  test_list.insertAtTail(3);
  test_list.insertAtTail(2);
  test_list.insertAtTail(1);
  test_list.insertAtTail(2);
  test_list.insertAtTail(1);
  test_list.insertAtTail(3);
  test_list.printList();
  //test_list.removeDups();
  test_list.removeDupsWithoutBuffer();
  test_list.printList();
}
