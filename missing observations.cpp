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
//explaination
Vector Initialization (remaining(n, req_sum / n)):

Purpose: This step initializes the remaining vector, which will store the missing rolls. It sets each element to the average value that the missing rolls need to take to achieve the required sum.
remaining(n, req_sum / n): This initializes the remaining vector with n elements, where each element is set to req_sum / n. This is essentially distributing the required sum as evenly as possible across the n missing rolls.
Example: If req_sum = 22 and n = 4, then req_sum / n = 5. So, initially, remaining = [5, 5, 5, 5].
Why?: This ensures that the rolls are distributed evenly, and we start with a valid distribution. We will handle any leftover sum (i.e., the remainder) in the next step.
Calculate the Remainder (int remainder = req_sum % n):

Purpose: After dividing the req_sum by n, there might be a leftover sum (remainder) that wasn't evenly distributed among the n rolls.
req_sum % n: This calculates the remainder when req_sum is divided by n. If there is any remainder, it means we still need to distribute a few more points across the rolls.
Example: If req_sum = 22 and n = 4, then 22 % 4 = 2. This remainder of 2 needs to be distributed across some of the rolls.
Why?: Without this step, the sum of the missing rolls might not exactly match the required sum. We need to account for the remainder to ensure the total is correct.
Distribute the Remainder (for (int i = 0; i < remainder; ++i)):

Purpose: This loop distributes the remainder across the first remainder elements of the remaining vector. It increments the value of the first remainder rolls by 1 to account for the leftover sum.
How it works: The loop runs remainder times, and in each iteration, it increments the value of remaining[i] by 1.
Example: Continuing from the previous example where remaining = [5, 5, 5, 5] and remainder = 2, the loop will increment the first two elements by 1. So, after this loop, remaining = [6, 6, 5, 5].
Why?: By adding 1 to the first few elements, we ensure that the total sum of the rolls is exactly equal to the required sum (req_sum). This step guarantees that the sum is correctly distributed while keeping each roll within the valid range (i.e., between 1 and 6).
