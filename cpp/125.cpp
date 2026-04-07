class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        if (s.empty()) 
            return true;

        while (left < right) {
            if (!isalnum(s[left]))
                left++;
            else if (!isalnum(s[right]))
                right--;
            else {
                if (tolower(s[right]) != tolower(s[left]))
                    return false;

                right--;
                left++;
            }
        }

        return true;
    }
};

/* class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for (char c : s) {
            if (isalnum(c)) 
                t += tolower(c);
        }

        string rev = t;
        reverse(rev.begin(), rev.end());

        return t == rev;
    }
}; */