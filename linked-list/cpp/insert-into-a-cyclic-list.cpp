/* Given a node from a cyclic linked list which is sorted in ascending order,
   write a function to insert a value into the list such that it remains a
   cyclic sorted list. The given node can be a reference to any single node in
   the list, and may not be necessarily the smallest value in the cyclic list.
   If there are multiple suitable places for insertion, you may choose any
   place to insert the new value. After the insertion, the cyclic list should
   remain sorted.
   If the list is empty (i.e., given node is null), you should create a new
   single cyclic list and return the reference to that single node. Otherwise,
   you should return the original given node.
   LC 708. Insert into a Cyclic Sorted List
   Author: Shruti
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:

    Node* insert(Node* head, int insertVal) {
        if(!head) {
            Node* temp = new Node(insertVal, NULL);
            head = temp;
            return head;
        }
        Node* curr = head;
        while(curr) {
            if(curr->val > curr->next->val && (insertVal < curr->next->val || insertVal > curr->val)) {
                Node* temp = curr->next;
                curr->next = new Node(insertVal, temp);
                return head;
            }
            if(curr->val <= insertVal && curr->next->val >= insertVal) {
                Node* temp = curr->next;
                curr->next = new Node(insertVal, temp);
                return head;
            }
            curr = curr->next;
            if(curr == head) {
                curr->next = new Node(insertVal, curr->next);
                return head;
            }
        }
        return head;
    }
};
