class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def recursive(postorder: List[int], left: int, right: int) -> bool:
            if right - left < 0:
                return True

            rootValue = postorder[right]
            index = left
            while index < right and postorder[index] < rootValue:
                index += 1

            for i in range(index, right):
                if postorder[i] < rootValue:
                    return False

            return recursive(postorder, left, index - 1) and recursive(postorder, index, right - 1)

        return recursive(postorder, 0, len(postorder) - 1)