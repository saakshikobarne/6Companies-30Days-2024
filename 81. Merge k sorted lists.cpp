/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/


//code:

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minh;
     int n=lists.size();
    for(int i=0;i<n;i++){
        if(lists[i]!=NULL) minh.push({lists[i]->val,lists[i]});
    }
    ListNode*newlistHead=NULL,*newtemp=NULL;
    while(!minh.empty()){
        if(newlistHead==NULL){
            newlistHead=newtemp=minh.top().second;
            ListNode*temp=minh.top().second;
            minh.pop();
            if(temp->next!=NULL){
                minh.push({temp->next->val,temp->next});
            }
        }
        else{
           newtemp->next=minh.top().second;
           newtemp=newtemp->next;
            ListNode*temp=minh.top().second;
            minh.pop();
            if(temp->next!=NULL){
                minh.push({temp->next->val,temp->next});
            }
        }
    }
    return newlistHead;
    }
};
