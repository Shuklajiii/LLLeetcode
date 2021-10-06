19. Remove Nth Node From End of List

Diff -> Medium 

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:
Q. 1 -> 2 -> 3 -> 4 -> 5
A. 1 -> 2 -> 3 ----> 5

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


/* TWO POINTER APPROACH  */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* fast=head, *slow=head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            head = head->next;
            delete slow,fast;
        }
        else{
            while(fast->fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            ListNode* tmp = slow->next;
            slow->next = slow->next->next;
            delete tmp,slow,fast;
        }
        return head;
    }
};


/* One Pass Only */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* temp1 = temp;
        ListNode* temp2 = temp;
        n++;
        while(n--)
        {
            temp1 = temp1->next;
        }
        while(temp1)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = temp2->next;
        temp2->next = temp1->next;
        delete temp1;
        return temp->next;
    }
};
