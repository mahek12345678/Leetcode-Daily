class Solution {
public:
    int divide(int dividend, int divisor) {

if(dividend == INT_MIN && divisor == -1){
    return INT_MAX;
}

if(dividend == INT_MAX && divisor == -1){
    return -INT_MAX;
}
        bool negative = false;

        if((dividend < 0 && divisor > 0) ||
           (dividend > 0 && divisor < 0)){
            negative = true;
        }

        long long a = dividend;
        long long b = divisor;

        if(a < 0) a = -a;
        if(b < 0) b = -b;

        long long count = 0;

        while(a >= b){
            a = a - b;
            count++;
        }

        if(negative){
            return -count;
        }

        return count;
    }
};