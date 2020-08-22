t = int(input())

progs = {}

def solvepos(startx, starty, program, repeat):
    x = startx
    y = starty
    for r in range(repeat):
        if program in progs.keys():
            xdiff, ydiff = progs[program]
            x += xdiff
            y += ydiff
        else:
            lprog = ""
            reps = 0
            recording = False
            opens = 0
            closes = 0
            for p in program:
                if recording:
                    if p == "(":
                        opens += 1
                    elif p == ")":
                        closes += 1
                    if opens == closes:
                        recording = False
                        x, y = solvepos(x, y, lprog, reps)
                    else:
                        lprog += p
                else:
                    if p == "S":
                        y += 1
                    elif p == "N":
                        y -= 1
                    elif p == "E":
                        x += 1
                    elif p == "W":
                        x -= 1
                    elif p == "(":
                        opens = 1
                        closes = 0
                        lprog = ""
                        recording = True
                    elif p.isdigit():
                        reps = int(p)

            progs[program] = [x-startx, y-starty]

        if x < 1:
            x = (10**9)-x
        elif x > (10**9):
            x = x-(10**9)
        if y < 1:
            y = (10**9)-y
        elif y > (10**9):
            y = y-(10**9)
    return x, y

for i in range(t):
    program = input()
    x, y = solvepos(1, 1, program, 1)
    print("Case #"+str(i+1)+": "+str(x)+" "+str(y))
