class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Store frequency
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Max heap
        // {frequency, element}
        priority_queue<pair<int, int>> pq;

        for (auto p : freq) {
            pq.push({p.second, p.first});
        }

        // Step 3: Take top K elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};