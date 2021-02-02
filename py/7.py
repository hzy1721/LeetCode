class Solution:
    def reverse(self, x: int) -> int:
        pre = 1
        s = str(x)
        if x < 0:
            pre = -1
            s = s[1:]
        s = s[::-1]
        if int(s) > (2147483648 if pre == -1 else 2147483647):
            return 0
        else:
            return pre * int(s)