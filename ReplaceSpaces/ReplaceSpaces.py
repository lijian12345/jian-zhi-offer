def replaceSpace(s):
    if not isinstance(s, str) or len(s) <= 0 or s is None:
        return ''

    numOfSpace = 0
    for i in s:
        if i == ' ':
            numOfSpace += 1

    newLen = len(s) + numOfSpace * 2
    newStr = newLen * [None]
    indexOfOriginal, indexOfNew = len(s) - 1, newLen - 1
    while indexOfOriginal >= 0 and indexOfOriginal <= indexOfNew:
        if s[indexOfOriginal] == ' ':
            newStr[indexOfNew - 2:indexOfNew + 1] = ['%', '2', '0']
            indexOfNew -= 3
        else:
            newStr[indexOfNew] = s[indexOfOriginal]
            indexOfNew -= 1
        indexOfOriginal -= 1
    return ''.join(newStr)


print(replaceSpace("hello  world"))
