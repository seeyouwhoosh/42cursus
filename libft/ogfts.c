// ft_striteri, ft_substr, ft_strjoin, ft_strtrim, ft_itoa, ft_strmapi, ft_split

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int index;

    index = 0;
    if (!s || !f)
    {
        return ;
    }
    while (s[index])
    {
        f(index, &s[index]);
        index++;
    }
}