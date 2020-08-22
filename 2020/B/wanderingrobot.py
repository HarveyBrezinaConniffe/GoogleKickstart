t = int(input())
for i in range(t):
    grid = {}
    W, H, L, U, R, D = map(int, input().split())
    grid[(0, 0)] = 1
    for h in range(H):
        for w in range(W):
            cprob = 0
            if w == 0 and h == 0:
                continue
            else:
                hm1 = (w, h-1) in grid
                wm1 = (w-1, h) in grid 
                if w == W-1 and h == H-1:
                    if w != 0 and wm1:
                        cprob += grid[(w-1, h)] 
                    if h != 0 and hm1:
                        cprob += grid[(w, h-1)] 
                elif h == H-1:
                    if h != 0 and hm1:
                        cprob += grid[(w, h-1)]/2 
                    if w != 0 and wm1:
                        cprob += grid[(w-1, h)] 
                elif w == W-1:
                    if w != 0 and wm1:
                        cprob += grid[(w-1, h)]/2 
                    if h != 0 and hm1:
                        cprob += grid[(w, h-1)] 
                else:
                    if w != 0 and wm1:
                        cprob += grid[(w-1, h)]/2 
                    if h != 0 and hm1:
                        cprob += grid[(w, h-1)]/2

            if (not (h <= D-1 and h >= U-1 and w <= R-1 and w >= L-1)) and cprob != 0:
                grid[(w, h)] = cprob
    if (W-1, H-1) not in grid:
        grid[(W-1, H-1)] = 0
    print("Case #"+str(i+1)+": "+str(grid[(W-1, H-1)]))
