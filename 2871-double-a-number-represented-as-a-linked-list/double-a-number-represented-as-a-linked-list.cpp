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
private:
    int solve(ListNode *head)
    {
        if(head==nullptr)
            return 0;
        int ans=(head->val)*2 + solve(head->next);
        head->val=ans%10;
        return ans/10;
    }
public:
    ListNode* doubleIt(ListNode* head)
    {
        int carry=solve(head);
        if(carry!=0)
        {
            ListNode *dummy=new ListNode();
            dummy->val=carry;
            dummy->next=head;
            return dummy;
        }
        return head;
    }
};