def duplicate(numbers, duplication):
    if not numbers or len(numbers) <= 0:
        return False

    for i in numbers:
        if i < 0 or i >= len(numbers):
            return False

    for i in range(len(numbers)):
        while numbers[i] != i:
            if numbers[i] == numbers[numbers[i]]:
                duplication[0] = numbers[i]
                return True
            else:
                # numbers[i], numbers[numbers[i]] = numbers[numbers[i]], numbers[i]
                temp = numbers[i]
                numbers[i], numbers[temp] = numbers[temp], numbers[i]
        return False


# L = [2, 3, 5, 4, 3, 2, 6, 7]
# LL = [0]
# duplicate(L, LL)
# print(LL)
