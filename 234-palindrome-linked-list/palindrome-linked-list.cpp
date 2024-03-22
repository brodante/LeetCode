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
    bool isPalindrome(ListNode* head)
    {
        bool odd=false;
        if(head->next==nullptr)
            return true;
        if(head->next->next==nullptr&&head->val!=head->next->val)
            return false;
        ListNode *fast=head, *slow=head;
        stack<int> tmp;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            tmp.push(slow->val);
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=head;
        while(fast!=nullptr)
        {
            odd=!odd;
            fast=fast->next;
        }
        if(odd)
            slow=slow->next;
        while(slow!=nullptr)
        {
            if(tmp.empty()||slow->val!=tmp.top())
                return false;
            tmp.pop();
            slow=slow->next;
        }
        return true;
    }
};