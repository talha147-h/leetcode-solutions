class Solution {
public:

    // Checks whether adding x to the current window
    // creates any invalid triplet a + b = c
    bool bad(int x,vector<int>&freq){

        // Try every value a that currently exists
        for(int a=1;a<=500;a++){

            if(freq[a]==0)continue;

            // -------------------------------
            // Case 1:
            // a + b = x
            //
            // x is the result of the addition.
            // So b = x-a.
            // -------------------------------

            int b=x-a;

            if(b>=1&&b<=500&&freq[b]>0){

                // If a and b are different,
                // they automatically represent
                // two different indices.
                //
                // If a == b, we need TWO occurrences
                // of that value because indices must be distinct.
                if(a!=b||freq[a]>=2){
                    return true;
                }
            }

            // -------------------------------
            // Case 2:
            // a + x = b
            //
            // x is one of the two numbers being added.
            // So b = a+x.
            // -------------------------------

            b=a+x;

            if(b<=500&&freq[b]>0){
                return true;
            }
        }

        // No invalid triplet was found
        return false;
    }


    int maxSubarray(vector<int>& nums) {

        int n=nums.size();

        // freq[v] = number of times v occurs
        // in the current window [left...right-1]
        vector<int>freq(501,0);

        int left=0;
        int ans=0;

        for(int right=0;right<n;right++){

            int x=nums[right];

            // Keep removing elements from the left
            // until adding x becomes safe.
            while(bad(x,freq)){

                freq[nums[left]]--;
                left++;
            }

            // Now x can safely be added
            freq[x]++;

            // Update maximum window length
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};