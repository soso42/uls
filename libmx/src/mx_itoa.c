#include "../inc/libmx.h"

static size_t nbrlen(int nbr) {
    int len;

    len = 0;
    if (nbr == 0)
        return (1);
    if (nbr < len)
        len += 1;
    while (nbr != 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char *mx_itoa(int number) {
    size_t	i;
    size_t	n_size;
    char	*str;

    i = 0;
    if (number == -2147483648)
        return (mx_strdup("-2147483648"));
    n_size = nbrlen(number);
    if (!(str = (char *)malloc(sizeof(char) * (n_size + 1))))
        return (NULL);
    str[n_size] = 0;
    if (number < 0) {
        str[0] = '-';
        number *= -1;
        i += 1;
    }
    while (i < n_size--) {
        str[n_size] = (number % 10) + '0';
        number /= 10;
    }
    return (str);
}