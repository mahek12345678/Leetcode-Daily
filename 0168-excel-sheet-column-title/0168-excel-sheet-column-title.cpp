class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            columnNumber--;  // convert 1-26 to 0-25

            int rem = columnNumber % 26;
            ans += char('A' + rem);

            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};