from collections import defaultdict

def solution(survey, choices):
    answer = []
    
    result = defaultdict(int)
    
    for s, c in zip(survey, choices):
        if c == 7:
            result[s[1]] += 3
        elif c == 6:
            result[s[1]] += 2
        elif c == 5:
            result[s[1]] += 1
            
        elif c == 3:
            result[s[0]] += 1
        elif c == 2:
            result[s[0]] += 2
        elif c == 1:
            result[s[0]] += 3
    
    if result['R'] >= result['T']:
        answer.append('R')
    else:
        answer.append('T')
    
    if result['C'] >= result['F']:
        answer.append('C')
    else:
        answer.append('F')
        
    if result['M'] > result['J']:
        answer.append('M')
    else:
        answer.append('J')
        
    if result['A'] >= result['N']:
        answer.append('A')
    else:
        answer.append('N')
    
    return ''.join(answer)