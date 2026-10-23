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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        if(cnt<k)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* ahead=NULL;
         for(int i=0;i<k;i++)
         {
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
         }
        head->next=reverseKGroup(curr,k);
         return prev;
    }
};