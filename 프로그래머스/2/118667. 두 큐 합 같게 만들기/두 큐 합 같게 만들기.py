# 큐의 길이는 같다.
# pop -> push 를 통해서 두 큐의 합이 같도록 하면 됨
# 필요한 작업의 최소 횟수? -> pop & push 각각 1회로 침
# 앞쪽에서 pop 해야함 -> popleft & append 사용

# 작업 중에 큐의 길이를 같게 유지 안해도 됨

# 불가능한 경우?
# 원소가 한바퀴 돌아와도 완성 못했을때,
# 내 큐가 상대 큐로 온전히 전달 2n
# 상대 큐에서 내 큐로 온전히 전달 2n -> 총 4n 이후에도 완성 못하면 실패

from collections import deque

def solution(queue1, queue2):
    answer = 0
    
    q1 = deque(queue1)
    q2 = deque(queue2)
    
    s1 = sum(q1)
    s2 = sum(q2)
    
    while s1 != s2:
        
        if answer >= len(queue1) * 4:
            answer = -1
            break
        
        if s1 > s2:
            e = q1.popleft()
            s1 -= e
            s2 += e
            q2.append(e)
        else:
            e = q2.popleft()
            s1 += e
            s2 -= e
            q1.append(e)
        answer += 1
    
    return answer