class Solution {
public:
    bool isRobotBounded(string instructions) {
        int lefts=0;
        int rights=0;
        int x=0;
        int y=0;
        int dir=0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(char ch:instructions){
        if(ch=='L')dir=(dir+3)%4;
        if(ch=='R')dir=(dir+1)%4;
        if(ch=='G'){x=x+dx[dir];y=y+dy[dir];}
        }
        if(dir!=0)return true;
        if(dir==0 && (x!=0 || y!=0) )return false;
        return true;
    }
};