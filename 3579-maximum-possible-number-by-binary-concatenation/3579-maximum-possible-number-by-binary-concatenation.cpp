class Solution {
public:
    std::string generateBinary(int num) {
        if (num == 0) return "0";
        std::string binary = "";
        while (num > 0) {
            binary = std::to_string(num % 2) + binary;
            num /= 2;
        }
        return binary;
    }

    int maxGoodNumber(std::vector<int>& nums) {
        vector<std::string> binaries;
        for (int num : nums) {
            binaries.push_back(generateBinary(num));
        }

        sort(binaries.begin(), binaries.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        string concatenated = "";
        for (const auto& binary : binaries) {
            concatenated += binary;
        }


        return std::stoi(concatenated, nullptr, 2);
    }
};
