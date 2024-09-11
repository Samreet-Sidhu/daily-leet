class Solution {
public:
    int minBitFlips(int start, int goal) {
// lets take start=10(1010) and goal =7(0111)
        int count=0;
// num will be 13(1101)
        int num = start^goal;
        while(num!=0){
 // following step se hum uski saari bit le rahe hai and we are comparing ki kya voh 1 hai kyunki 1 tabhi hota hai jab xor me dono different ho 
            int x= num%2;
            if (x==1) count ++;
            num/=2;
        }
        return count;
    }
};
