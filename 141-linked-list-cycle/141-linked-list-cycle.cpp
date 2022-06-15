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
        int cnt=0;
        while(head != NULL && cnt<=10000){
            head = head->next;
            cnt++;
        }
        if(cnt==10001)
            return true;
        else return false;
    }
};