
#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    auto p = head;
    cout << "[";
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }//end while
    cout <<  "]" << endl; 
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return nullptr;
    }

    ListNode *prior = nullptr;
    ListNode *current = head;
    ListNode *p = nullptr;
    p = current->next;

    while(p != nullptr){
        prior = current;
        p = current->next;
        
        current->next = prior;
        p = p->next;
    }//end while
    return nullptr;
}

int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    ListNode *head = &node1;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;

    printList(head);


    return 0;
}