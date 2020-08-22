t = int(input())

def visit(tree, node, visited, visiting, border):
    # We have already processes this node
    if node in visited:
        return 0
    # We have looped back to here, Graph is not acyclic and blocks not stackable
    if node in visiting:
        return -1

    visiting.add(node)

    # Visit each child
    for cnode in tree[node]:
        v = visit(tree, cnode, visited, visiting, border)
        if v == -1:
            return -1

    # All lower nodes have now been visited( And added to the order ), Add this node to the order and mark it as visited
    border.append(node)
    visited.add(node)
    return 0


for i in range(t):
    order = {}
    R, C = map(int, input().split())
    strs = []

    # Take in each row of input
    for k in range(R):
        cstr = input()
        strs.append(cstr)

    
    rules = []
    # Build up the order of each column
    for k in range(C):
        cstr = ''
        last = '!'
        # Loop through each column from bottom to top. Collapsing repeated characters. E.G. AAGDDD -> AGD
        for r in range(1, R+1):
            index = R-r 
            cchar = strs[index][k]
            if cchar != last:
                cstr += cchar
            last = cchar
        rules.append(cstr)

    # Build up a graph where each node is a block and each vertex UV is a dependancy that U must be place before V.
    for rule in rules:
        last = -1
        for cc in rule:
            if cc not in order:
                order[cc] = []
            if last != -1:
                if cc not in order[last]:
                    order[last].append(cc)
            last = cc

    # Keep track of all the nodes we have visited and have not visited
    blockorder = []
    valid = True
    unvisited = set(order.keys())
    visited = set()
    while len(unvisited) > 0:
        # Get a node we have not yet visited and initialize a set to keep track of everything we visit in this "session"
        visiting = set()
        cnode = unvisited.pop()
        r = visit(order, cnode, visited, visiting, blockorder)
        if r == -1:
            valid = False
            break
    if not valid:
        print("Case #"+str(i+1)+": -1")
    else:
        out = ""
        for b in reversed(blockorder):
            out += b
        print("Case #"+str(i+1)+": "+out)

