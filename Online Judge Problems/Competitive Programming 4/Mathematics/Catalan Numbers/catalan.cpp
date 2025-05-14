// catalan (https://open.kattis.com/problems/catalan)
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
 
using namespace std;
 
// Time: O(N)
// Space: O(N)

class BigInteger {
public:
    vector<int> digits; // Least significant digit first

    BigInteger() {
        digits.push_back(0);
    }

    BigInteger(const string &num) {
        for (int i = num.size() - 1; i >= 0; --i)
            digits.push_back(num[i] - '0');
        removeLeadingZeros();
    }

    BigInteger(int num) {
        if (num == 0) digits.push_back(0);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }

    string toString() const {
        string result;
        for (int i = digits.size() - 1; i >= 0; --i)
            result += (char)(digits[i] + '0');
        return result;
    }

    void print() const {
        cout << toString() << '\n';
    }

    bool isSmaller(const BigInteger &other) const {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false;
    }

    bool isEqual(const BigInteger &other) const {
        return digits == other.digits;
    }

    // Addition
    BigInteger operator+(const BigInteger &other) const {
        BigInteger result;
        result.digits.clear();
        int carry = 0;

        int n = max(digits.size(), other.digits.size());
        for (int i = 0; i < n || carry; ++i) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }

    // Subtraction (assumes a >= b)
    BigInteger operator-(const BigInteger &other) const {
        if (this->isSmaller(other)) {
            cerr << "Error: Negative result not supported.\n";
            return BigInteger(0);
        }

        BigInteger result;
        result.digits.clear();

        int borrow = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int sub = digits[i] - borrow;
            if (i < other.digits.size())
                sub -= other.digits[i];

            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else
                borrow = 0;

            result.digits.push_back(sub);
        }

        result.removeLeadingZeros();
        return result;
    }

    // Multiplication
    BigInteger operator*(const BigInteger &other) const {
        BigInteger result;
        result.digits.assign(digits.size() + other.digits.size(), 0);

        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 0; j < other.digits.size(); ++j) {
                result.digits[i + j] += digits[i] * other.digits[j];
                if (result.digits[i + j] >= 10) {
                    result.digits[i + j + 1] += result.digits[i + j] / 10;
                    result.digits[i + j] %= 10;
                }
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    // Integer Division: this / other (returns floor division)
    BigInteger operator/(const BigInteger &other) const {
        if (other.isEqual(BigInteger(0))) {
            cerr << "Error: Division by zero\n";
            return BigInteger(0);
        }

        BigInteger dividend = *this;
        BigInteger divisor = other;
        BigInteger result;
        result.digits.resize(dividend.digits.size(), 0);
        BigInteger curr;

        for (int i = dividend.digits.size() - 1; i >= 0; --i) {
            curr.digits.insert(curr.digits.begin(), dividend.digits[i]);
            curr.removeLeadingZeros();
            int x = 0, l = 0, r = 9;
            while (l <= r) {
                int m = (l + r) / 2;
                BigInteger t = divisor * BigInteger(m);
                if (!t.isSmaller(curr) || t.isEqual(curr)) {
                    x = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            result.digits[i] = x;
            curr = curr - divisor * BigInteger(x);
        }

        result.removeLeadingZeros();
        return result;
    }
};

const int MAX_X = 5000;

BigInteger factorial(BigInteger x, unordered_map<string,BigInteger>& dp) {
    x.print();
    if (stoi(x.toString()) == 0)
        return BigInteger(1);
    if (dp.find(x.toString()) != dp.end())
        return dp[x.toString()];

    return dp[x.toString()] = x * factorial(x-BigInteger(1), dp);
}

void solve(BigInteger x, unordered_map<string,BigInteger>& dp) {
    BigInteger catalan = (factorial(BigInteger(2)*x, dp) / (factorial(x, dp) * factorial(x, dp))) / (x + BigInteger(1));
    catalan.print();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int query_cnt;
    cin >> query_cnt;

    unordered_map<string, BigInteger> dp;
    
    while (query_cnt > 0) {
        int x;
        cin >> x;

        BigInteger big_x(x);
        solve(big_x, dp);

        query_cnt--;
    }
    
    return 0;
}