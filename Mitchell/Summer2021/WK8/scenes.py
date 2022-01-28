
def repeats(cols, w):
    r = []
    i = 0
    while(i < w):
        count = 1
        cur = cols[i]
        i += 1
        while(i < w and cols[i] == cur):
            count += 1
            i += 1
        r += [count]
    return r 

def main():
    facts = [1]
    for i in range(1, 101):
        facts += [facts[i-1] * i]
    #print(facts)
    vals = input().split()
    l = int(vals[0])
    w = int(vals[1])
    h = int(vals[2])
    #l = int(input())
    #w = int(input())
    #h = int(input())
    cols = [0 for i in range(w)]
    cols[0] = 1
    s = 0
    while(cols[0] <= h):
        if sum(cols) <= l:
            r = repeats(cols, w)
            #print("cols:", cols)
            #print("repeats:", r)
            if len(r) > 1:
                cur = facts[w]
                for rep in r:
                    cur //= facts[rep]
                s += cur
                s %= 1000000007
        i = w-1
        while (i > 0) and (cols[i] == cols[i-1]):
            i-=1;
        cols[i] += 1
        temp = i+1
        while temp < w and cols[temp] != 0:
            cols[temp] = 0
            temp+=1

    print(s)

main();
