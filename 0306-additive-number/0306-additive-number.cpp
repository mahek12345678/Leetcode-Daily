
class Solution {
public:
    string add(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += char('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= n - i; j++) {
                string a = num.substr(0, i);
                string b = num.substr(i, j);

                if (a.size() > 1 && a[0] == '0') break;
                if (b.size() > 1 && b[0] == '0') break;

                int k = i + j, count = 2;

                while (k < n) {
                    string c = add(a, b);

                    if (num.substr(k, c.size()) != c)
                        break;

                    k += c.size();
                    a = b;
                    b = c;
                    count++;
                }

                if (k == n && count >= 3)
                    return true;
            }
        }

        return false;
    }
};
