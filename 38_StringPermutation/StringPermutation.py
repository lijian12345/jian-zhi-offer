class Solution:
    def Permutation(self, ss):
        # write code here
        if len(ss) <= 0:
            return []
        res = []
        self.perm(ss, res, '')
        return sorted(list(set(res)))

    def perm(self, ss, res, path):
        if ss == '':
            res.append(path)
        else:
            for i in range(len(ss)):
                self.perm(ss[:i] + ss[i + 1:], res, path + ss[i])
