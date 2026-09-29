class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long ans = 1;

        while(exp > 0) {
            if(exp % 2 == 1) {
                ans = (ans * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = modPow(5, even, MOD);
        long long oddWays = modPow(4, odd, MOD);

        return (evenWays * oddWays) % MOD;
    }
};