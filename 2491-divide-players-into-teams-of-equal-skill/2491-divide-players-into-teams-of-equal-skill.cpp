class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum=0;
        for(int i=0;i<skill.size();i++){
            sum+=skill[i];
        }
        int n=skill.size();
        int teams=n/2;
        if(sum%teams!=0)return -1;
        long long chemistry=0;
        sort(skill.begin(),skill.end());
        int left=0;
        int right=n-1;
        while(left<right){
            if(skill[left]+skill[right]!=sum/teams)return -1;
            chemistry+=skill[left]*skill[right];
            left++;
            right--;
        }
        return chemistry;
    }
};