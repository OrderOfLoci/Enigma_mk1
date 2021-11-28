#include <stdlib.h>
#include <stdio.h>

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char    rotor1(int i, char c)
{
    return (c + i);
}

int len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *enigma_mk1(char config1, char *str)
{
    int     i;
    char    *coded;

    i = 0;
    coded = (char *)malloc(sizeof(char) * len(str) + 1);
    while (str[i] != '\0')
    {
        printf("rotor position: %d\n", config1);
        if (str[i] >= 'a' && str[i] <= 'z')
            coded[i] = rotor1(config1, str[i]);
        else
        {
            coded[i] = str[i];
            i++;
        }
        i++;
        config1++;
    }
    coded[i] = '\0';
    return (coded);
}

int main()
{
    printf("coded message: %s\n", enigma_mk1('a', "hello"));
}