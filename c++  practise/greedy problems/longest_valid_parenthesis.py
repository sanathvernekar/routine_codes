def solve(parenthesis):
    stack = []
    cur = 0
    ret = 0
    for i, e in enumerate(parenthesis):
        if e == '(':
            stack.append(cur)
            cur = 0
        elif e == ')' and len(stack) > 0:
            cur += stack.pop() + 2
            ret = max(ret, cur)
        elif e == ')' and len(stack) == 0:
            cur = 0
    return ret


t=int(input())
while(t):
    s=input()
    x=solve(s)
    print(x)
    t=t-1
