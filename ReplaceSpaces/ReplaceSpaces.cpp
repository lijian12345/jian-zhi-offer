/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char string[], int length)
{
    if (string == nullptr || length <= 0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        originalLength++;
        if (string[i] == ' ')
            numberOfBlank++;
        i++;
    }
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        indexOfOriginal--;
    }
}

void replaceSpace(char *str, int length)
{
    if (str == nullptr || length <= 0)
        return;
    int numberOfBlock = 0;
    char *originalPointer = str;
    while (*originalPointer != '\0')
    {
        if (*originalPointer == ' ')
            numberOfBlock++;
        originalPointer++;
    }
    char *newPointer = originalPointer + numberOfBlock * 2;
    while (originalPointer >= str && newPointer > originalPointer)
    {
        if (*originalPointer == ' ')
        {
            *(newPointer--) = '0';
            *(newPointer--) = '2';
            *(newPointer--) = '%';
        }
        else
        {
            *(newPointer--) = *originalPointer;
        }
        originalPointer--;
    }
}