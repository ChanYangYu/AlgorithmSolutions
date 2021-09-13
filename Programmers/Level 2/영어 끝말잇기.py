def solution(n, words):
    mp = {}
    turn = 0
    for i, w in enumerate(words):
        if i % n == 0:
            turn += 1
        if w in mp:
            return [i%n + 1, turn]
        if i != 0 and words[i-1][-1] != words[i][0]:
            return [i%n + 1, turn]
        mp[w] = 1

    return [0,0]