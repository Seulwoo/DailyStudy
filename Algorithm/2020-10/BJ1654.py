import sys
read = sys.stdin.readline

K, N = map(int, read().split(' '))
inputs = []
for i in range(K):
    inputs.append(int(read()))

left = 0
# right = max(inputs)
right = pow(2,31)-1
answer = 0
while left <= right:
    mid = int((left+right)/2)
    cur = 0
    for i in range(K):
        cur += (inputs[i]//mid)
    if cur >= N:
        answer = max(answer, mid)
        left = mid+1
    else:
        right = mid-1

print(answer)
