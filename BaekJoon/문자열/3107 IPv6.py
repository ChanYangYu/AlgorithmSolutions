ipv6 = input()
a = ipv6.split(":")
cnt = 0

for s in a:
  if s != '':
    cnt += 1

res = []
check = False

for s in a:
  if s == '' and check == False:
    for i in range(8 - cnt):
       res.append('0000')
    check = True
  elif s != "" :
    hex = s
    for i in range(4 - len(s)):
      hex = "0" + hex
    res.append(hex)
print(':'.join(res))
