class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int firstNode = edges[0][0];
        int secondNode = edges[0][1];

        if (firstNode == edges[1][0] ||
            firstNode == edges[1][1]) {
            return firstNode;
        }

        return secondNode;
    }
};