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
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;
        while(temp!=NULL) {
            node->val=temp->val;
            
            temp=temp->next;
            if(temp==NULL) {
                break;
            }
            node=node->next;
        }
        node->next=NULL;
    }
};
