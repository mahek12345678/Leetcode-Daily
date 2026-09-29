class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxDepth = 0;

        for(char ch : s){
            if(ch == '('){
                count++;
                maxDepth = max(maxDepth, count);
            }
            else if(ch == ')'){
                count--;
            }
        }

        return maxDepth;
    }
};