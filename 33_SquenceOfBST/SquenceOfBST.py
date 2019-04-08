class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        return self.bst(sequence, 0, len(sequence) - 1)

    def bst(self, sequence, begin, end):
        if not sequence or begin > end:
            return False
        root = sequence[end]
        i = begin
        while i < end:
            if sequence[i] > root:
                break
            i += 1
        j = i
        while j < end:
            if sequence[j] < root:
                return False
            j += 1
        left = True
        if i > begin:
            left = self.bst(sequence, begin, i - 1)
        right = True
        if j < end:
            right = self.bst(sequence, i, end - 1)
        return left and right
