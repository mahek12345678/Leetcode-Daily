class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        // nums2 ke har number ka next greater find karo
        for (int num : nums2) {

            while (!st.empty() && num > st.top()) {

                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // Jo stack mein bach gaye unka next greater nahi hai
        while (!st.empty()) {

            mp[st.top()] = -1;
            st.pop();
        }

        // nums1 ka answer banao
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};