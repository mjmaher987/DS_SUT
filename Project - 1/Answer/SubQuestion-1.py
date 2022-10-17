if __name__ == '__main__':
    mainNumbers = list(map(int, input().split()))
    n = mainNumbers[0]
    k = mainNumbers[1]
    answer = 0
    numbers = list(map(int, input().split()))

    for i in range(0, n):
        for j in range(i, n):
            sum = 0
            for t in range(i, j + 1):
                sum += numbers[t]
            if sum <= k:
                answer += 1

    print(answer)
