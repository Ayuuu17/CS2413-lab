/* 203. Remove Linked List Elements:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL){
        return NULL;
    }
    
    //creating temp node
    struct ListNode temp;
    temp.next = head;
    struct ListNode* prev = &temp;
    struct ListNode* current = head;

    //traversing the list
    while (current != NULL){
        if (current -> val == val){
            prev -> next = current -> next;

            current = current -> next;

        } else{
            prev = current;
            current = current -> next;
        }
    }

    return temp.next;
}
