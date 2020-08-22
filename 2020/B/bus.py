t = int(input())
for i in range(t):
    n, d = map(int, input().split())
    day = d
    buses = list(map(int, input().split()))
    for b in reversed(buses):
        penalty = day%b
        day -= penalty
    print("Case #"+str(i+1)+": "+str(day))
