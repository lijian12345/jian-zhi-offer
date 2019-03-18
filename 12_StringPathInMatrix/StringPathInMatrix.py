class Solution:
    def hasPath(self, matrix, rows, cols, path):
        if matrix is None or path is None or rows < 1 or cols < 1:
            return False
        visited = [False] * (rows * cols)
        pathLength = 0
        for row in range(rows):
            for col in range(cols):
                if self.hasPathCore(matrix, row, rows, col, cols, pathLength,
                                    path, visited):
                    return True
        return False

    def hasPathCore(self, matrix, row, rows, col, cols, pathLength, path,
                    visited):
        if pathLength == len(path):
            return True
        hasPath = False
        if row >= 0 and row < rows and col >= 0 and col < cols and matrix[
                row * cols +
                col] == path[pathLength] and not visited[row * cols + col]:
            pathLength += 1
            visited[row * cols + col] = True
            hasPath = self.hasPathCore(
                matrix, row + 1, rows, col, cols,
                pathLength, path, visited) or self.hasPathCore(
                    matrix, row - 1, rows, col, cols,
                    pathLength, path, visited) or self.hasPathCore(
                        matrix, row, rows, col + 1, cols, pathLength,
                        path, visited) or self.hasPathCore(
                            matrix, row, rows, col - 1, cols, pathLength, path,
                            visited)
            if not hasPath:
                pathLength -= 1
                visited[row * cols + col] = False
        return hasPath
