
def solution(enter, leave):
    n = len(enter)
    answer = [0] * n
    room = []
    pos = 0
    
    for l in leave :
        check = False
        cur_room = []
        for r in room :
            if r == l :
                check = True
            else:
                cur_room.append(r)
        
        room = cur_room
        
        if check :
            continue
        
        while pos < n:
            for r in room :
                answer[enter[pos]-1] += 1
                answer[r-1] += 1
            if enter[pos] == l :
                pos +=1
                break
            room.append(enter[pos])
            pos +=1
    return answer