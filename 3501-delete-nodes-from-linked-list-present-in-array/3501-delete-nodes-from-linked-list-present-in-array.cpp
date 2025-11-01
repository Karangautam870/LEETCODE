class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* ans = new ListNode(0);  
        ListNode* temp = ans;             

        while (head) {                    
            if (st.count(head->val) == 0) { 
                temp->next = head;         
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;                 
        
        return ans->next;
    }
};
