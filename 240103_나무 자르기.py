# https://www.acmicpc.net/problem/2805
import sys
n, m=map(int,sys.stdin.readline().split())
lst=list(map(int, sys.stdin.readline().split()))
end=max(lst)
total=0
start=0
result=0
while start<=end:
    answer=(start+end)//2
    total=sum(tree - answer for tree in lst if tree > answer)
    if total>=m:
        result=answer
        start=answer+1
    else:
        end=answer-1

print(result)
