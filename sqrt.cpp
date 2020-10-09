class Solution {
public:
    int mySqrt(int x) 
    {
           int prev,k = 0; 
        int kmax = 1000; 
        double s = 1; 
        for(k=0;k<kmax;k++) 
        { 
                prev = s; 
                s = (s + x/s)/2; 
                if(prev == s) 
                { 
                        break; 
                } 
        } 
        return s; 
    }
};
