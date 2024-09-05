class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i=0;i<rolls.size();i++){
            sum += rolls[i]; }

        int req_sum = (rolls.size()+n) * mean - sum;

         if (req_sum > 6 * n || req_sum < n) {
            return {};  // Impossible to achieve, return empty vector
        }

        vector<int> remaining(n, req_sum / n);
        int remainder = req_sum % n;  // Handle the remainder

        // Distribute the remainder by adding 1 to the first 'remainder' elements
        for (int i = 0; i < remainder; ++i) {
            remaining[i]++;
        }

        return remaining; 
    }
};
