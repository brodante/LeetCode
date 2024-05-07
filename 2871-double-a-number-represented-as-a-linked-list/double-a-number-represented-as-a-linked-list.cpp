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
    ListNode* doubleIt(ListNode* head)
    {
        stack<int> st;
        int curr=0;
        while(head)
        {
            st.push(head->val);
            head=head->next;
        }
        //ListNode *tmp=new ListNode(0); adds an extra 0 node in the end
        ListNode *tmp=nullptr;
        while(!st.empty()||curr!=0)
        {
            tmp=new ListNode(0, tmp);
            if(!st.empty())
            {
                curr+=st.top()*2;
                st.pop();
            }
            tmp->val=curr%10;
            curr/=10;
        }
        return tmp;
    }
};