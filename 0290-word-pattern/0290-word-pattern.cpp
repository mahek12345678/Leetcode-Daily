
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;
        stringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word) {
            if (i >= pattern.size())
                return false;

            char ch = pattern[i];

            if (mp.count(ch)) {
                if (mp[ch] != word)
                    return false;
            }
            else {
                if (used.count(word))
                    return false;

                mp[ch] = word;
                used.insert(word);
            }

            i++;
        }

        return i == pattern.size();
    }
};
