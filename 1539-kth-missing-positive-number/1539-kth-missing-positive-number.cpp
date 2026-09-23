class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int i = 0;
        int current = 1;
        int missingCount = 0;

        while(true) {

            // current number array mein present hai
            if(i < arr.size() && arr[i] == current) {
                i++;
            }

            // current number missing hai
            else {
                missingCount++;

                if(missingCount == k) {
                    return current;
                }
            }

            current++;
        }
    }
};