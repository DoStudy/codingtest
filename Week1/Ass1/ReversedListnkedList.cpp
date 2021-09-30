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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currentNode = head;
        
        while (currentNode != nullptr) {           
            ListNode* nextNode = currentNode->next;
            
            currentNode->next = prevNode;
            
            prevNode = currentNode;
            currentNode = nextNode;
        }
        
        return prevNode;
    }
};
