class Solution {
public:
    int findComplement(int num) {
        unsigned int m=~0;
        while(num&m){
            m=m<<1;
        }
        return ~m&~num;
    }
};