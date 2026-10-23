
class Allocator {
public:
    vector<int>arr;
    Allocator(int n) {
        arr.resize(n,0); 
    }
    
    int allocate(int size, int mID) {
        int j=0;
        int count=0;
        int flag=0;
        for(int i=0;i<arr.size();i++)
        {
           if(arr[i]==0) 
           {
               count++;
               if(count==size)
               {
                   flag=1;
                   break;
               }
           }
            else {
                count=0;
                j=i+1;
            }
        }
        if(flag)
        {
            for(int i=j;i<=j+size-1;i++)
                arr[i]=mID;
            
            return j;
        }
        else return -1;
    }
    
    int freeMemory(int mID) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==mID)
            {
                count++;
                arr[i]=0;
            }
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */