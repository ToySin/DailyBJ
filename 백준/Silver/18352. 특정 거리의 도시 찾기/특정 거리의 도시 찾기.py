import heapq

INF = int(1e9)

n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

distance = [INF] * (n+1)

def dijkstra(start):
    pq = []
    distance[start] = 0
    heapq.heappush(pq, (distance[start], start))

    while pq:
        dist, node = heapq.heappop(pq)
        if distance[node] < dist:
            continue
        for n in graph[node]:
            cost = dist + 1
            if cost < distance[n]:
                distance[n] = cost
                heapq.heappush(pq, (cost, n))

dijkstra(x)

result = []
for i in range(1, n+1):
    if distance[i] == k:
        result.append(i)

if result:
    for city in sorted(result):
        print(city)
else:
    print(-1)
