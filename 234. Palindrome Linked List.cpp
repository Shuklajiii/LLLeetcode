234. Palindrome Linked List  

Diff -> Easy

/* Given the head of a singly linked list, return true if
   it is a palindrome.

   Example-1:

   1 -> 2 -> 2 -> 1

   Input: head = [1,2,2,1]
   Output: true

   Example-2:

   1 -> 2

   Input: head = [1,2]
   Output: false 


   Constraints:
    - The number of nodes in the list is in the range [1, 10^5].
    - 0 <= Node.val <= 9

 */



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
    bool isPalindrome(ListNode* head) {
       vector<int> n;
        while(head != NULL){
            n.push_back(head->val);
            head = head->next;
        }
        vector<int>h(n);
        reverse(h.begin(), h.end());
        return n == h;
    }
};



/* C++ Solution with O(n) and O(1) complexity  */


   class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)  return true;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;//12(2)1
            fast=fast->next->next;
        }
        //123(4)321
        ListNode *temp=slow;
        if(fast!=NULL){
            slow=slow->next;
        }
        ListNode *slowfast=slow->next;
        if(slowfast){
            ListNode *slowfaster=slowfast->next;
            slow->next=NULL;
            while(slowfaster){
                slowfast->next=slow;
                slow=slowfast;
                slowfast=slowfaster;
                slowfaster=slowfaster->next;
            }
            slowfast->next=slow;
            slow=slowfast;
        }
        fast=head;
        while(slow!=NULL){
            if(fast->val!=slow->val)    return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};










