class StringIterator {
public:
    StringIterator(string compressedString) {
        char ch = compressedString[0];
        string num_str = "";
        for (int i = 1; i < compressedString.length() - 1; ++i) {
            if (compressedString[i] >= '0' && compressedString[i] <= '9')
                num_str.push_back(compressedString[i]);
            
            if ((compressedString[i] >= 'a' && compressedString[i] <= 'z') ||
                (compressedString[i] >= 'A' && compressedString[i] <= 'Z')) {
                data.push_back({ch, stoi(num_str)});
                num_str.clear();
                ch = compressedString[i];
            }
        }
        num_str.push_back(compressedString.back());
        data.push_back({ch, stoi(num_str)});
        
        it = data.begin();
    }
    
    char next() {
        char next = ' ';
        if (it == data.end() && !it->second) return next;
        
        next = it->first;
        --it->second;
        if (it != data.end() && !it->second) ++it;
        
        return next;
    }
    
    bool hasNext() {
        if (it == data.end() && !it->second) return false;
        else return true;
    }
private:
    list<pair<char, int>> data;
    list<pair<char, int>>::iterator it;

};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Runtime: 12 ms, faster than 49.11% of C++ online submissions for Design Compressed String Iterator.
// Memory Usage: 14.3 MB, less than 8.04% of C++ online submissions for Design Compressed String Iterator.