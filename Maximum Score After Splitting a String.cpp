class Solution {
public:
    int maxScore(string s) {
        int onecount=0;
        int zerocount=0;
     for (char c : s){
        if (c == '1'){
            onecount++; 
        }
     }
     int sum = 0;
     int maxscore=0;
     for (int i = 0; i < s.size() - 1; i++){
        if(s[i]=='0'){
            zerocount++;
        }
        else {
            onecount --;
        }
        sum = zerocount + onecount;
        maxscore = max(sum, maxscore);
     } 
     return maxscore;  
    }

};
