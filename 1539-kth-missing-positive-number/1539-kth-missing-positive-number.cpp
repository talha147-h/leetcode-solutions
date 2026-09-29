class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //[2,3,4,7,11]  k=5 ---> {1,5,6,8,9} 
        int number=1;
        for(int i=0;i<arr.size();i++){
            while(arr[i]!=number){
                k--;
                if(k==0)return number;
                 number++;
            }
            number++;
        }
        return number+k-1;
        
    }
};