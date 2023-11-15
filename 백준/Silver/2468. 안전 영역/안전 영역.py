# 모든 지역에서 시작
# 침수하지 않은 지역이면 방문처리 후 큐에 넣고 시작
# 큐가 빌때까지,
# 큐에서 지역 꺼냄(x, y) 4방향 확인 후 유효하면 방문처리 후 큐에 넣기

from collections import deque

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y, rain, visited):
    # 침수 된 지역이거나 이미 방문한 지역은 안전지대 제외
    if rain >= graph[x][y] or visited[x][y]:
        return False
    # 큐 생성 및 시작 지역 넣고 방문처리
    queue = deque()
    queue.append((x, y))
    visited[x][y] = True
    # 큐가 비어있기 전까지
    while queue:
        # 현재 지역 정보 받기
        x, y = queue.popleft()
        # 현재 지역에서 4방향 확인하기
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 유효하지 않은 지역이면 패스
            if nx < 0 or n <= nx or ny < 0 or n <= ny:
                continue
            # 방문하지 않은 지역이고 침수되지 않았다면 큐에 넣고 방문처리
            if not visited[nx][ny] and rain < graph[nx][ny]:
                queue.append((nx, ny))
                visited[nx][ny] = True
    # 큐가 비었다 -> 지역을 돌며 하나의 안전지대에 방문처리를 완료함
    # draw_graph(visited)
    return True

# def draw_graph(graph):
#     for line in graph:
#         print(line)
#     print()

# 어짜피 최소 높이보다 낮은 강수량엔 침수 없고
# 최대 높이보다 높은 강수량엔 모두 침수
max_rain, min_rain = max(map(max, graph)), min(map(min, graph))

# 최대 안전지대 수
max_safe = 0
# 높이는 1이상 100이하
# 비가 안오는 경우를 고려해서 -1 처리
for rain in range(min_rain - 1, max_rain + 1):
    # 이번 강수량에서 안전지대 수 초기화
    safe = 0
    # 이번 강수량에서 방문필드 초기화
    visited = [[False for _ in range(n)] for _ in range(n)]
    # 모든 지역에서 bfs탐색 시작
    for i in range(n):
        for j in range(n):
            # 해당 지역에서 시작되는 카운트 안된 안전지대가 있을시(True)
            if bfs(i, j, rain, visited):
                # 안전지대 수 추가
                safe += 1
    # 안전지대 최댓값 갱신
    max_safe = max(max_safe, safe)

print(max_safe)
