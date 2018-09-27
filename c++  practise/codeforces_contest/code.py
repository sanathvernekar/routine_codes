n=int(input())
A=-1
B=-1
C=-1
minA=100001
minB=100001
minC=100001
minAB=100001
minAC=100001
minBC=100001
minABC=100001
terminate_flag=0
for _ in range(n):
    cost,vitamin=input().split(' ')
    cost=int(cost)
    if 'A' in vitamin:
        A=1
    if 'B' in vitamin:
        B=1
    if 'C' in vitamin:
        C=1
    if vitamin == "A":
        if cost<minA:
            minA=cost
    elif vitamin =="B":
        if cost<minB:
            minB=cost
    elif vitamin =="C":
        if cost<minC:
            minC=cost
    elif (vitamin =="AB" or vitamin =="BA"):
        if cost<minAB:
            minAB=cost
    elif (vitamin =="BC" or vitamin =="CB"):
        if cost<minBC:
            minBC=cost
    elif (vitamin=="AC" or vitamin=="CA"):
        if cost<minAC:
            minAC=cost
    else:
        if cost<minABC:
            minABC=cost
lst=list()

minval1=minA+minB+minC
lst.append(minval1)
minval2=minAB+minC
lst.append(minval2)
minval3=minBC+minA
lst.append(minval3)
minval4=minAC+minB
lst.append(minval4)
lst.append(minABC)
lst.append(minAB+minAC)
lst.append(minAB+minBC)
lst.append(minBC+minAC)
lst.append(minBC+minAB)
lst.append(minAC+minAB)
lst.append(minAC+minBC)
lst.append(minA+minB+minAC)
lst.append(minA+minB+minBC)
lst.append(minA+minC+minBC)
lst.append(minA+minC+minAB)
lst.append(minB+minC+minAC)
lst.append(minB+minC+minAB)
    

    
if(A==-1 or B==-1 or C==-1):
    print("-1")
    terminate_flag=1
    
    
if(terminate_flag==0):
    print(min(lst))
