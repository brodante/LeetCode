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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode *ans=new ListNode(0);
        ListNode *beg=ans;
        head=head->next;
        while(head!=nullptr)
        {
            int tmp=0;
            while(head!=nullptr&&head->val!=0)
            {
                tmp+=head->val;
                head=head->next;
            }
            ans->next=new ListNode(tmp);
            ans=ans->next;
            head=head->next;
        }
    return beg->next;
    }
};