class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        record =  {0:1}
        curSum = 0
        ans = 0

        for number in A:
            curSum += number
            modulus = (curSum % K + K) % K
            if modulus not in record:
                record[modulus] = 1
            else:
                record[modulus] += 1

        for key in record:
            ans += record[key] * (record[key] - 1) // 2

        return ans