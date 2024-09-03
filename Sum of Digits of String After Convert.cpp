class Solution {
public:
// sum nikalne k liye function
    int totalSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getLucky(string s, int k) {
        string numStr = "";
        // Convert each character in the string to its position and concatenate
        for (char n : s) {
            numStr += to_string(n - 'a' + 1);
        }
        // Convert the concatenated string to an integer sum of its digits
        int num = 0;
        for (char digit : numStr) {
            num += digit - '0';
        }
        // Apply the digit sum process k times
        k--;
        while (k > 0 && num >= 10) {
            num = totalSum(num);
            k--;
        }
        return num;
    }
};
