def countRange(numbers, length, start, end):
    if not numbers:
        return 0
    count = 0
    for i in numbers:
        if i >= start and i <= end:
            count += 1
    return count


def getDuplication(numbers):
    length = len(numbers)
    if not numbers or length <= 0:
        return -1
    start = 1
    end = length - 1
    while end >= start:
        middle = int((end - start) / 2) + start
        count = countRange(numbers, length, start, middle)
        if end == start:
            if count > 1:
                return end
            else:
                break
        if count > middle - start + 1:
            end = middle
        else:
            start = middle + 1
    return -1


print(getDuplication([4, 2, 3, 1, 2, 5]))
