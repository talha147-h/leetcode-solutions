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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int cnt=0;
       ListNode* temp=head;
       while(temp!=NULL){
        temp=temp->next;
        cnt++;
       } 
       if(cnt==1)return NULL;
          if (cnt == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
       cnt=cnt-n-1;
     
       ListNode* curr=head;
       while(cnt--){
       curr=curr->next;
       }
       ListNode* del=curr->next;
       curr->next=del->next;
       delete(del);
       return head;
    }
};