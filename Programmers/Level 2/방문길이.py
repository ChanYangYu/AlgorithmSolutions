import numpy as np
dy = [-1,1,0,0]
dx = [0,0,1,-1]
mp = {'U':0, 'D':1, 'R':2, 'L':3}

def solution(dirs):
    ch = np.zeros((11,11,11,11))
    answer = 0
    y, x = (5,5)
    for d in dirs:
        yy =  y + dy[mp[d]]
        xx = x + dx[mp[d]]
        
        if yy < 0 or yy > 10 or xx < 0 or xx > 10:
            continue
        elif ch[y][x][yy][xx] == 0:
            ch[y][x][yy][xx] = 1
            ch[yy][xx][y][x] = 1
            answer += 1
        y = yy
        x = xx
    return answer