/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp=head;
        
        while(temp != NULL && head !=NULL){
            head = head->next;
            temp = temp->next;
            if(temp){
                temp = temp->next;
            }
            else break;
            if(temp==head)
                return true;
        }
        
        return false;
    }
};