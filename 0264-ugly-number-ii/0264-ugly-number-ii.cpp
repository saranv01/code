class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n);
        arr[0]=1;
        int l1=2,l2=3,l3=5;
        int i1=0,i2=0,i3=0;
        for(int i=1;i<n;i++){
            int temp=min({l1,l2,l3});
            arr[i]=temp;
            if(l1==temp){
                l1=arr[++i1]*2;
            }
            if(l2==temp){
                l2=arr[++i2]*3;
            }
            if(l3==temp){
                l3=arr[++i3]*5;
            }
        }
        return arr[n-1];
    }
};