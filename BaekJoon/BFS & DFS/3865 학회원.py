def get_elements(key):
  for element in keys[key]:
    if element in keys:
      if element not in visit:
        visit[element] = True
        get_elements(element)
    else:
      elements[element] = True

while True:
  n = int(input())

  if n == 0:
    break
  
  target = ''
  keys = {}
  visit = {}
  elements = {}

  for i in range(n):
    arr = input().replace('.','').replace(':',',').split(',')
    if target == '':
      target = arr[0]
    
    element = []
    for j in range(1, len(arr)):
      element.append(arr[j])
    keys[arr[0]] = element
  
  get_elements(target)
  print(len(elements))
