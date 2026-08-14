class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;

        // Put all numbers in max heap
        for (int num : nums) {
            pq.push(num);
        }

        // Remove first k-1 largest elements
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        // Now top is kth largest
        return pq.top();
    }
};