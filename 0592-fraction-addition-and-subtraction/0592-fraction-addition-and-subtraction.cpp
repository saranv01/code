class Solution {
public:
    int findGcd(int a,int b){
        if(a==0){
            return b;
        }
        return findGcd(b%a,a);
    }
    string fractionAddition(string expression) {
       int i=0;
       int numerator=0;
       int denomenator=1;

       while(i<expression.size()){
       int tempNumerator=0;
       int tempDenomenator=0;
       bool sign=false;
        if(expression[i]=='-'||expression[i]=='+'){
            if(expression[i]=='-')sign=true;
            i++;
        }
       while(isdigit(expression[i])){
            tempNumerator=tempNumerator*10+(int)(expression[i]-'0');
            i++;
       }
       i++;
       while(i<expression.size()&&isdigit(expression[i])){
            tempDenomenator=tempDenomenator*10+(int)(expression[i]-'0');
            i++;
       }
       if(sign) tempNumerator*=-1;
       numerator=numerator*tempDenomenator+denomenator*tempNumerator;
       denomenator=tempDenomenator*denomenator;

       }
        int gcd=abs(findGcd(numerator,denomenator));
        numerator=numerator/gcd;
        denomenator=denomenator/gcd;
        return to_string(numerator)+"/"+to_string(denomenator);
    }
};