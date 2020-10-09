class Solution {
public:
    double myPow(double x, int n) {
     float power=1;
        int i=1;
        for(i=1;i<=n;i++)
        {
            power =power*x;
        }
        return power;
    }
};
