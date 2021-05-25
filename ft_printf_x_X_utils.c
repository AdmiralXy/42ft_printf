#include "ft_printf.h"

static void ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static int	ft_hexlen(unsigned value)
{
	int	i;

	i = 0;
	while (value)
	{
		value /= 16;
		i++;
	}
	return (i);
}

static char *ft_dec_to_hexstr(unsigned value, int upper_case)
{
	int		i;
	int		len;
	char	*hexstr;
	int 	remainder;

	if (upper_case)
		upper_case = 'A';
	else
		upper_case = 'a';
	len = ft_hexlen(value);
	hexstr = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (value)
	{
		remainder = value % 16;
		if (remainder > 9)
			hexstr[i] = (char)(remainder - 10 + upper_case);
		else
			hexstr[i] = (char)('0' + remainder);
		value /= 16;
		i++;
	}
	hexstr[i] = '\0';
	ft_strrev(hexstr);
	return (hexstr);
}

char	*ft_itoa_hex(unsigned value, int upper_case)
{
	char	*hexstr;

	if (value == 0)
	{
		hexstr = malloc(sizeof(char) * 2);
		hexstr[0] = '0';
		hexstr[1] = '\0';
		return (hexstr);
	}
	hexstr = ft_dec_to_hexstr(value, upper_case);
	return (hexstr);
}