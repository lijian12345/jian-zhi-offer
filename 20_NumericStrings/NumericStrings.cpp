class Solution
{
  public:
    bool isNumeric(char *string)
    {
        if (!string)
            return false;
        bool numeric = scanInteger(&string);
        if (*string == '.')
        {
            ++string;
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        if (*string == 'e' || *string == 'E')
        {
            string++;
            numeric = numeric && scanInteger(&string);
        }
        return numeric && *string == '\0';
    }

    bool scanUnsignedInteger(char **str)
    {
        const char *before = *str;
        while (**str != '\0' && **str >= '0' && **str <= '9')
            (*str)++;
        return *str > before;
    }

    bool scanInteger(char **str)
    {
        if (**str == '+' || **str == '-')
            (*str)++;
        return scanUnsignedInteger(str);
    }
};