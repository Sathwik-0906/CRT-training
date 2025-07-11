def qis(l):
    if len(l) <= 1:
        return l
    pi = l.pop()
    lef = []
    ri = []
    for i in l:
        if i < pi:
            lef.append(i)
        else:
            ri.append(i)
    return qis(lef) + [pi] + qis(ri)


l = list(map(int, input().split()))
print("Original list:", l)
s = qis(l)
print("Sorted list:", s)
