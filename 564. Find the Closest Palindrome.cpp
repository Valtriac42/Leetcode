#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long num;
    long long ten[19] = {1};

    inline void compute_10pow() {
        for (int i = 1; i < 19; i++) {
            ten[i] = ten[i - 1] * 10;
        }
    }

    inline long long pal_with_half(long long half, int sz) {
        // build palindrome from the 1st half
        long long ans = half * ten[sz / 2], head = half, tail = 0;
        if (sz & 1) head /= 10;
        for (int i = 0; i < sz / 2; i++) {
            auto [q, r] = lldiv(head, 10);
            tail = 10 * tail + r;
            head = q;
        }
        ans += tail;
        return ans;
    }

    inline bool isPal(string& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }

    string nearestPalindromic(string& n) {
        int sz = n.size();
        num = stoll(n);
        if (num <= 10) return to_string(num - 1); // edge case
        if (num == 11) return "9"; // edge case

        int hz = (sz & 1) ? sz / 2 + 1 : sz / 2;
        long long half = stoll(n.substr(0, hz));
        compute_10pow();

        if (num == ten[sz - 1]) {
            // Special case for numbers like 1000, 10000, etc.
            return to_string(num - 1);
        }
        if (num == ten[sz] - 1) {
            return to_string(ten[sz] + 1);
        }

        long long pal[3], d[3] = {LLONG_MAX, LLONG_MAX, LLONG_MAX};
        pal[0] = pal_with_half(half, sz); // center palindrome
        d[0] = num - pal[0];
        if (d[0] >= 0) { // right palindrome
            if (half + 1 == ten[sz / 2 + 1])
                pal[1] = ten[sz] + 1;
            else
                pal[1] = pal_with_half(half + 1, sz);
            d[1] = pal[1] - num;
        }
        if (d[0] <= 0) { // left palindrome
            d[0] = -d[0];
            if (half == ten[sz / 2]) {
                pal[2] = ten[sz - 1] - 1;
            } else {
                pal[2] = pal_with_half(half - 1, sz);
            }
            d[2] = num - pal[2];
        }
        if (d[0] == 0) d[0] = LLONG_MAX; // exclude central palindrome when = num
        long long minD = *min_element(d, d + 3);
        if (d[2] == minD) return to_string(pal[2]);
        if (d[0] == minD) return to_string(pal[0]);
        return to_string(pal[1]);
    }
};

int main() {
    Solution solution;
    string n;
    cout << "Enter a number: ";
    cin >> n;
    string result = solution.nearestPalindromic(n);
    cout << "The nearest palindromic number is: " << result << endl;
    return 0;
}
