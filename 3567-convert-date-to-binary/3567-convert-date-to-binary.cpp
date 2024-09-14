class Solution {
public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string time;
        string result = "";
        

        while(getline(ss, time, '-')) {
            int n = stoi(time);
            string binary = "";
            

            if (n == 0) {
                binary = "0";
            } else {
    
                while (n > 0) {
                    binary.push_back((n % 2) + '0');
                    n /= 2;
                }
                reverse(binary.begin(), binary.end());
            }
            
    
            if (!result.empty()) {
                result += "-";  // Add space between binary parts
            }
            result += binary;
        }

        return result;
    }
};
