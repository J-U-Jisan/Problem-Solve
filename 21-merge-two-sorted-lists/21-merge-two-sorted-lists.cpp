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
        ListNode *head = NULL, *temp;
        while(list1  && list2 ){
            ListNode* node = new ListNode();
            if(list1->val > list2->val)
            {
                node->val = list2->val;
                if(head == NULL){
                    head = node;
                    temp = head;
                }
                else{
                    temp->next = node;
                    temp = temp->next;
                }
                list2 = list2->next;
            }
            else{
                node->val = list1->val;
                if(head == NULL){
                    head = node;
                    temp = head;
                }
                else{
                    temp->next = node;
                    temp = temp->next;
                }
                
                list1 = list1->next;
            }
        }
        while(list1){
            ListNode* node = new ListNode(list1->val);
            if(head == NULL){
                head = node;
                temp = head;
            }
            else{
                temp->next = node;
                temp = temp->next;
            }
            
            list1 = list1->next;
        }
        while(list2){
            ListNode* node = new ListNode(list2->val);
            if(head == NULL){
                head = node;
                temp = head;
            }
            else{
                temp->next = node;
                temp = temp->next;
            }
            list2 = list2->next;
        }
        return head;
    }
};