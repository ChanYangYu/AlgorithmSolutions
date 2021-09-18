def solution(gems):
    answer_list = []
    mp = {}
    
    # gem 종류 Search
    for gem in gems:
        mp[gem] = 0

    total = len(mp)
    start = 0
    end = 0
    cur = 1
    mp[gems[0]] += 1
    
    # Jem이 하나인 경우
    if cur == total:
        return [1, 1]
    
    # 예시) D B C C C A B C D
    for i in range(1, len(gems)):
        end = i
        
        if gems[start] == gems[end]:
            start += 1
        else:
            if mp[gems[end]] == 0:
                cur += 1
            mp[gems[end]] += 1
        
        # start에 해당하는 jem이 범위내에 여러개 인경우
        while mp[gems[start]] > 1:
            mp[gems[start]] -= 1
            start += 1
        
        # jem이 다 있는 경우
        if cur == total:
            answer_list.append([end-start+1, start+1, end+1])
    
    # Sort 
    answer_list.sort(key=lambda x : (x[0],x[1],x[2])) 
    return [answer_list[0][1], answer_list[0][2]]