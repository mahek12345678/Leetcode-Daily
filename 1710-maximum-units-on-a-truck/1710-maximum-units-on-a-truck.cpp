class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), compare);

        int ans = 0;

        for (auto box : boxTypes) {

            int boxes = box[0];
            int units = box[1];

            int take = min(boxes, truckSize);

            ans += take * units;
            truckSize -= take;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};