t = int(input())
for i in range(t):
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    last = -1
    kcounts = 0
    counting = False
    index = 0
    length = len(nums)
    while index < length:
        n = nums[index]
        if not counting:
            if n == 1 and K == 1:
                kcounts += 1
            elif n == K:
                counting = True
            index += 1
        elif counting:
            if last-1 != n:
                counting = False
            elif n == 1:
                counting = False
                kcounts += 1
                index += 1
            else:
                index += 1
        last = n
    print("Case #"+str(i+1)+": "+str(kcounts))
