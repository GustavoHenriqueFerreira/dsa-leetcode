from typing import List

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        frequencia_s = {}
        frequencia_t = {}

        for char in s:
            if char in frequencia_s:
                frequencia_s[char] += 1
            else:
                frequencia_s[char] = 1
        
        for char in t:
            if char in frequencia_t:
                frequencia_t[char] += 1
            else:
                frequencia_t[char] = 1

        if frequencia_s == frequencia_t:
            return True
        
        return False