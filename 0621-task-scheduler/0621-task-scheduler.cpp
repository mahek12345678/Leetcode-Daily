
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        int maxi = *max_element(freq.begin(), freq.end());
        int count = 0;

        for (int f : freq) {
            if (f == maxi)
                count++;
        }

        return max((int)tasks.size(),
                   (maxi - 1) * (n + 1) + count);
    }
};
