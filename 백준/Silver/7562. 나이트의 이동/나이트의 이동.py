from collections import deque

di = [-2, -1, 1, 2, 2, 1, -1, -2]
dj = [1, 2, 2, 1, -1, -2, -2, -1]

def bfs(
        board,
        start_i,
        start_j,
        end_i,
        end_j):
    queue = deque([(start_i, start_j)])
    board[start_i][start_j] = 0
    while queue:
        (cur_i, cur_j) = queue.popleft()
        if cur_i == end_i and cur_j == end_j:
            return board[cur_i][cur_j]
        for k in range(8):
            next_i = cur_i + di[k]
            next_j = cur_j + dj[k]
            if not 0 <= next_i < len(board) or not 0 <= next_j < len(board):
                continue
            if board[next_i][next_j] == -1:
                board[next_i][next_j] = board[cur_i][cur_j] + 1
                queue.append((next_i, next_j))



n = int(input())

for _ in range(n):
    l = int(input())

    start_i, start_j = map(int, input().split())
    end_i, end_j = map(int, input().split())

    board = [[-1 for _ in range(l)] for _ in range(l)]

    print(bfs(board, start_i, start_j, end_i, end_j))
