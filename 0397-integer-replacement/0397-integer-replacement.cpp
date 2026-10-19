class Solution {
public:
    int integerReplacement(int n) {
        int count =0;
        long long num=n;
        if(num==3)return 2;
        while(num!=1){
        if((num & 1)==0)num=num/2;
        else if((num&3)==1 || num==3)num=num-1;
        else num=num+1;
        count++;
        }
        return count;
    }
};