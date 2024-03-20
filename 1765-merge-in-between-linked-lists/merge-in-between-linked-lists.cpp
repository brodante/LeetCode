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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode *head1 = list1;
        ListNode *tmp = list1;
        ListNode *head2 = list2;
        // Traverse b nodes from the beginning of list1 to find tmp
        for (int i = 0; i < b; ++i)
        {
            tmp = tmp->next;
        }
        // Traverse a-1 nodes from the beginning of list1 to find head1
        for (int i = 0; i < a - 1; ++i) {
            head1 = head1->next;
        }
        // Connect the a-1th node of list1 to the head of list2
        head1->next = head2;
        // Traverse list2 to find its tail
        while (head2->next != nullptr)
        {
            head2 = head2->next;
        }
        // Connect the ath node of list1 to the tail of list2
        head2->next = tmp->next;
        return list1;
    }
};