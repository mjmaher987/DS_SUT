if __name__ == '__main__':
    mainNumbers = list(map(int, input().split()))
    n = mainNumbers[0]
    k = mainNumbers[1]
    answer = 0
    numbers = list(map(int, input().split()))

    R = 0
    L = 0
    sum = 0
    for i in range(0, n):
        sum += numbers[i]
        if sum <= k:
            answer += i - L + 1
        else:
            while sum > k and L <= i:
                sum -= numbers[L]
                L += 1
            if sum <= k:
                answer += i - L + 1
    print(answer)
