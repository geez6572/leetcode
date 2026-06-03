class Solution:
    def isPalindromeSub(self,s:str) -> bool:
        left: int = 0
        right: int = len(s) - 1
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -=1
        return True
    def removePalindromeSub(self, s: str) -> int:
        return 1 if self.isPalindromeSub(s) else 2
