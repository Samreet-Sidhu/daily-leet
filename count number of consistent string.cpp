class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {  
        int count = 0; 
        // Iterate over each word in the vector
        for (int i = 0; i < words.size(); i++) {
            bool isConsistent = true;  // Assume the word is consistent  
            // Check each character in the current word
            for (char c : words[i]) {
                if (allowed.find(c) == string::npos) {// Character not in allowed
                    isConsistent = false;
                    break;  // Exit the loop as the word is inconsistent
                }
            }  
            if (isConsistent) count++;
        }
        return count;
    }
};
