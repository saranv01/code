class Solution {

std::string removeAllOccurrences(std::string s, const std::string &sub) {
    while (s.find(sub) != std::string::npos) {
    size_t pos = s.find(sub); 
    if (pos != std::string::npos) {
        s.erase(pos, sub.size()); 
    }
    }
    return s;
}

public:
    std::string removeOccurrences(std::string s, std::string part) {
        return removeAllOccurrences(s, part);
    }
};
