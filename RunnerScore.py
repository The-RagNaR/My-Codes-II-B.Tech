if __name__ == '__main__':
    n = int(input())
    arr = input().split()
    result =[]
    for i in arr:
        result.append(int(i))
    result.sort()
    max_r = max(result)
    result.pop()
    while max_r==max(result):
        result.pop()
    print(max(result))
    