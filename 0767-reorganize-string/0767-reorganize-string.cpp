class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
          mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        if(pq.top().first>(s.size()-pq.top().first)+1)return "";
        string ans="";
        while(!pq.empty()){
           auto[freq,ch]=pq.top();
           pq.pop();
           freq--;
           ans+=ch;
           if(!pq.empty()){
            auto[freq2,ch2]=pq.top();
            pq.pop();
            freq2--;
            ans+=ch2;
            if(freq2!=0)pq.push({freq2,ch2});
           }
           if(freq!=0)pq.push({freq,ch});
        }
        return ans;
    }
};