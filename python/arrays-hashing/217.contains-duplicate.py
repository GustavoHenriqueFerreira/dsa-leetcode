from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        numeros_vistos = set()
        
        for numero in nums:
            if numero in numeros_vistos:
                return True
            numeros_vistos.add(numero)
        return False

Solution().containsDuplicate([1,2,3,1])