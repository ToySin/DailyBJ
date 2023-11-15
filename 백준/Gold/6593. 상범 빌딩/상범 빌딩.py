from collections import deque

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

def bfs(sx, sy, sz, ex, ey, ez):
    queue = deque()
    queue.append((sx, sy, sz))
    building[sx][sy][sz] = 1
    while queue:
        cx, cy, cz = queue.popleft()
        for i in range(6):
            nx = cx + dx[i]
            ny = cy + dy[i]
            nz = cz + dz[i]
            # 유효한 위치인가?
            if nx < 0 or ny < 0 or nz < 0 or l <= nx or r <= ny or c <= nz:
                continue
            # 아직 안지나갔거나 출구인 경우만 지나갈 수 있다.
            # 지나갈 수 없는 목록은 이미 지나와서 소요시간이 적힌 지점 + 벽 지점
            if building[nx][ny][nz] in ['.', 'E']:
                queue.append((nx, ny, nz))
                building[nx][ny][nz] = building[cx][cy][cz] + 1

    # building의 end_pos가 E로 남아있으면 실패, 숫자로 채워졌으면 소요시간
    if building[ex][ey][ez] == 'E':
        return False
    else:
        return building[ex][ey][ez]


while True:
    # 건물 정보 입력받기
    l, r, c = map(int, input().split())
    if l == 0 and r == 0 and c == 0:
        break
    building = []
    for _ in range(l):
        layer = [list(input()) for _ in range(r)]
        building.append(layer)
        input()

    # 시작 지점과 끝 지점 찾기
    start_pos = ()
    end_pos = ()
    for i in range(l):
        for j in range(r):
            for k in range(c):
                if building[i][j][k] == 'S':
                    start_pos = (i, j, k)
                if building[i][j][k] == 'E':
                    end_pos = (i, j, k)

    result = bfs(start_pos[0], start_pos[1], start_pos[2], end_pos[0], end_pos[1], end_pos[2])
    if result:
        print(f"Escaped in {result - 1} minute(s).")
    else:
        print("Trapped!")


