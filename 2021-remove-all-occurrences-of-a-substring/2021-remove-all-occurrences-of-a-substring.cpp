class Solution {
int removeOneOccurrence(std::string &s, const std::string &sub) {
    size_t pos = s.find(sub); 
    if (pos != std::string::npos) {
        s.erase(pos, sub.size()); 
    }
    return s.size();
}

std::string removeAllOccurrences(std::string s, const std::string &sub) {
    while (s.find(sub) != std::string::npos) {
        removeOneOccurrence(s, sub);
    }
    return s;
}

public:
    std::string removeOccurrences(std::string s, std::string part) {
        return removeAllOccurrences(s, part);
    }
};
