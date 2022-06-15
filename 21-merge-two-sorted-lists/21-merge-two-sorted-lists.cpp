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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *prev, *temp;
        while(list1  && list2 ){
            
            if(list1->val > list2->val)
            {
                ListNode* node = new ListNode(list2->val);
            
                if(head == NULL){
                    node->next = list1;
                    head = node;
                }
                else{
                    node->next = prev->next;
                    prev->next = node;
                }
                prev = node;
                list2 = list2->next;
            }
            else{
                if(head == NULL)
                    head = list1;
                prev = list1;
                list1 = list1->next;
            }
        }
        
        while(list2){
            
            if(head == NULL){
                return list2;
            }
            else{
                ListNode* node = new ListNode(list2->val);
                node->next = prev->next;
                prev->next = node;
                prev = node;
            }
            
            list2 = list2->next;
        }
        if(head== NULL)
            return list1;
        return head;
    }
};