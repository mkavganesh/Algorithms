'''
@author : utkarshpatel
'''

def readInt():
    return int(input())

def readIntArray(t=False, delim=' '):
    s = input().strip().split(delim)
    if t: return tuple([int(x) for x in s])
    else: return [int(x) for x in s]

def readStrArray(t=False, delim=' '):
    s= input().strip().split(delim)
    if t: return tuple(s)
    else: return s

def GCD(a, b):
    if (b == 0): return a
    return GCD(b, a % b)

def binary_search(words, low, high, key):
    if high < low:
        return -1

    mid = (low + high) // 2

    if words[mid] < key:
        return binary_search(words, mid + 1, high, key)
    elif words[mid] > key:
        return binary_search(words, low, mid - 1, key)
    else:
        return mid

if __name__ == '__main__':
    tt = readInt()
    for case in range(1, tt+1):
        n, l = readIntArray(t=True)
        a = readIntArray()
        primes = []
        temp = GCD(a[0], a[1])
        primes.append(int(a[0] / temp))
        for i in range(l-1):
            primes.append(GCD(a[i], a[i+1]))
        temp = GCD(a[-1], a[-2])
        primes.append(int(a[-1] / temp))
        s = set()
        for i in primes:
            s.add(i)
        s = sorted(s)
        ans = ''
        for e in primes:
            temp = binary_search(s, 0, 25, e) + 65
            ans += chr(temp)
        print('Case #{0}:'.format(case), ans)

