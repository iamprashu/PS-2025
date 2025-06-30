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
    int getLength(ListNode* &head){
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //step 1 : Get Size of listr
        int size = getLength(head);
        if(size==0){
            return NULL;
        }
        //step 2:
        int actualRotation = k % size;

        if(actualRotation == 0){ // when no rotations needed
            return head;
        }
        //
        int count =  1;

        ListNode* temp = head;

        while((size-count) > actualRotation ){
            temp = temp->next;
            count++;
        } 
        //yaha pe ab mere pas temp just us node se pahle h jise rotate karna hai 
        ListNode* toRotate = temp->next;// null nahi ho sakta as length nikali hui hai

        temp->next = NULL; 

        temp = toRotate;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = head;

        return toRotate;
    }
};