
struct ListNode {
    int val;    
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. 
The list should be made by splicing together the nodes 
of the first two lists.

Return the head of the merged linked list.
*/

/* Pseudocode:
    Simple:
        Recursively compare the first element of each list, put in a new ListNode
        Find the bottom of the list, 
    Advanced:
        

*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        //Recursion - put all into list 1
        if (list1->next == nullptr){
            if (list2->next != nullptr){
                list1->next = list2->next;
            } 
            return list1;
        } else if (list2->next == nullptr){
            return list1;
        }
        
        ListNode* tmpTopL1, *tmpTopL2;
        if (list1->val <= list2->val) {
            if (list1->next->val <= list2->val) {
                tmpTopL1 = list1->next;
                tmpTopL2 = list2;    
            } else {
            tmpTopL1->next = list1->next;
            tmpTopL2->next = list2->next;
            list1->next = list2;
            list2->next = tmpTopL1->next;
            tmpTopL1->next = list2;
            //tmpTopL1->next = list1->next;
            //tmpTopL2->next = list2;
            }
        } else {
            tmpTopL1->next = list1->next;
            //tmpTopL2->next = list2->next;
            //list1->next = list2;
            //list2->next = tmpTopL1->next;
            //tmpTopL1->next = list2;
        }


        return mergeTwoLists(tmpTopL1->next, tmpTopL2->next);

    }

};