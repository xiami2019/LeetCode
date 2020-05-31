class Solution:
    def countDigitOne(self, n: int) -> int:
        counts = 0
        i = 1
        while i <= n:
            divider = i * 10
            counts += (n // divider) * i + min(max(n % divider - 10 + 1, 0), i)
            i *= 10
        return counts