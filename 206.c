/** 206. Reverse Linked List:
Given the head of a singly linked list, reverse the list, and return the reversed list.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    // defining pointers
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    // traversing the list
    while (current != NULL) {
        next = current -> next;
        current -> next = prev;

        prev = current;
        current = next;
    
    }
    return prev;
}
