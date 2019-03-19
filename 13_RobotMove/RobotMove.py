class Solution:
    def movingCount(self, threshold, rows, cols):
        if threshold < 0 or rows <= 0 or cols <= 0:
            return 0
        visited = [False] * (rows * cols)
        count = self.movingCountCore(0, rows, 0, cols, threshold, visited)
        return count

    def movingCountCore(self, row, rows, col, cols, threshold, visited):
        count = 0
        if self.check(row, rows, col, cols, threshold, visited):
            visited[row * cols + col] = True
            count = 1 + self.movingCountCore(
                row + 1, rows, col, cols,
                threshold, visited) + self.movingCountCore(
                    row - 1, rows, col, cols,
                    threshold, visited) + self.movingCountCore(
                        row, rows, col + 1, cols, threshold,
                        visited) + self.movingCountCore(
                            row, rows, col - 1, cols, threshold, visited)
        return count

    def check(self, row, rows, col, cols, threshold, visited):
        if row >= 0 and row < rows and col >= 0 and col < cols and self.getDigitSum(
                row) + self.getDigitSum(col) <= threshold and not visited[
                    row * cols + col]:
            return True
        return False

    def getDigitSum(self, number):
        sum = 0
        while number > 0:
            sum += number % 10
            number //= 10 # 此处有坑
        return sum
