class Solution {
public:
    bool xday(int x, vector<int>& bloomDay, int m, int k,int n){
        int cnt=0;//no . of bouquets makde
        int cntflowers=0;//consecutive flowers bloomed
        for(int i =0; i<n; i++){
            cntflowers=0;
            if(bloomDay[i]<=x){
                cntflowers++;
                if(k==1)cnt++;
                else{
                int j=i+1;
                while( j<n && bloomDay[j]<=x){
                    cntflowers++;
                    if(cntflowers==k){
                        cnt++;break;
                    }
                    j++;
                }
                i=j;
            
            }
            }  
        }
        return (cnt>= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n= bloomDay.size();
       if(1LL*m*k> n) return -1;
       int low= *min_element(bloomDay.begin(), bloomDay.end());
       int high= *max_element(bloomDay.begin(), bloomDay.end());
       int ans=-1;
       while(low<high){
           int mid= low+(high-low)/2;
           bool y= xday(mid, bloomDay, m, k,n);
           if(y){
             ans=mid;
             high=mid;
           }
           else{
            low=mid+1;
           }
       }
       return low;
    }   
};