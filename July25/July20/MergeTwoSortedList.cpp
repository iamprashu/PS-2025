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
    ListNode* helper(ListNode* &list1, ListNode* &list2,ListNode* &p1,ListNode* &p2){

        if(p1 == NULL && p2 == NULL){
            return NULL;
        }else if(p1 == NULL){
            return p2;
        }else if(p2 == NULL){
            return p1;
        }

        ListNode* head = NULL;
        ListNode* temp = NULL;
        
        int p1_value = p1->val;
        int p2_value = p2->val;

        if(p1_value < p2_value){
            head = new ListNode(p1_value);
            temp = head;
            p1 = p1->next;            
        }else{
            head = new ListNode(p2_value);
            temp = head;
            p2 = p2->next;
        }

        temp->next = helper(list1,list2,p1,p2);

        return head;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* m1 =  helper(list1,list2,p1,p2);

        return m1;
        
    }
};