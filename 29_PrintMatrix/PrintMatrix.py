class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        res = []
        rows = len(matrix)
        cols = len(matrix[0])
        if rows == 1 and cols == 1:
            res = [matrix[0][0]]
            return res
        for o in range((min(cols, rows) + 1) // 2):
            [res.append(matrix[o][i]) for i in range(o, cols - o)]
            [
                res.append(matrix[j][cols - 1 - o])
                for j in range(o, rows - o)
                if matrix[j][cols - 1 - o] not in res
            ]
            [
                res.append(matrix[rows - 1 - o][k])
                for k in range(cols - 1 - o, o - 1, -1)
                if matrix[rows - 1 - o][k] not in res
            ]
            [
                res.append(matrix[l][o])
                for l in range(rows - 1 - o, o - 1, -1)
                if matrix[l][o] not in res
            ]
        return res
