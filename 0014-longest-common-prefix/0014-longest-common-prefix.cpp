class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = "";

        for(int j = 0; j < strs[0].size(); j++){

            char ch = strs[0][j];

            for(int i = 1; i < strs.size(); i++){

                // string khatam OR character different
                if(j >= strs[i].size() || strs[i][j] != ch){
                    return prefix;
                }
            }

            // sab strings mein same character mila
            prefix += ch;
        }

        return prefix;
    }
};