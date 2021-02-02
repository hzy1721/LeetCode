class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        result = 0
        start = 0
        end = 1
        while start < length-result:
            while end < length and s[start:end].find(s[end]) == -1:
                end += 1
            result = max(result, end-start)
            start += 1
        return result
