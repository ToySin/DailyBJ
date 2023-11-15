def solution(bridge_length, weight, truck_weights):
    time = 0
    bridge = [0] * bridge_length
    cur_weight = 0
    trucks = truck_weights[::-1]
    while trucks:
        time += 1
        cur_weight -= bridge.pop(0)
        w = trucks.pop() if cur_weight + trucks[-1] <= weight else 0
        cur_weight += w
        bridge.append(w)

    # 마지막으로 트럭을 보낸 뒤, 다리 길이만큼 시간이 소요되므로.
    return time + len(bridge)

print(solution(2, 10, [7, 4, 5, 6]))
print(solution(100, 100, [10,10,10,10,10,10,10,10,10,10]))
