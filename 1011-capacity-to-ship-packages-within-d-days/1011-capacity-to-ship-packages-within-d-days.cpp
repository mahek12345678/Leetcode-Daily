class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        // Find maximum weight and total weight
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }

        while (low < high) {

            int mid = low + (high - low) / 2;

            int daysNeeded = 1;
            int currentLoad = 0;

            // Check how many days are needed
            // if capacity = mid
            for (int weight : weights) {

                if (currentLoad + weight > mid) {
                    daysNeeded++;
                    currentLoad = 0;
                }

                currentLoad += weight;
            }

            // Binary search
            if (daysNeeded <= days) {
                high = mid;        // works → try smaller
            }
            else {
                low = mid + 1;     // too small → try bigger
            }
        }

        return low;
    }
};