t = int(input())
for i in range(t):
    peaks = 0
    last2 = 0
    last = 0
    n = int(input())
    heights = map(int, input().split())
    count = 0
    for h in heights:
        if count > 1:
            if last > last2 and last > h:
                peaks += 1
        last2 = last
        last = h
        count += 1
    print("Case #"+str(i+1)+": "+str(peaks))
