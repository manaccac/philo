#include "philo_three.h"

void		ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_atoi(char *nptr)
{
	int				i;
	int				a;
	long int		res;

	res = 0;
	a = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		a = -a;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * a);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	{
		if (n >= 0 && n <= 9)
			ft_putchar(n + 48);
		else if (n < 0)
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

int			put_error(char *err)
{
	ft_putstr(err);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int		ft_lent(char *s1, char *s2)
{
	int len;

	len = (ft_strlen(s1)) + (ft_strlen(s2));
	return (len);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	int			len;

	if (s1 && s2)
	{
		len = ft_lent(((char *)s1), ((char *)s2));
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
		i = 0;
		while (s2[i])
		{
			str[j++] = s2[i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int			ft_intlen(long int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char			*ft_intzero(int n)
{
	long int	nl;
	char		*res;

	nl = n;
	if (!(res = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	if (nl == 0)
	{
		res[0] = 0 + 48;
		res[1] = '\0';
		return (res);
	}
	return (res);
}

char				*ft_itoa(int n)
{
	long int	nl;
	long int	len;
	char		*res;

	len = ft_intlen(n);
	nl = n;
	if (nl == 0)
	{
		res = ft_intzero(n);
		return (res);
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nl < 0)
	{
		res[0] = '-';
		nl = nl * -1;
	}
	while (nl > 0)
	{
		res[len--] = (nl % 10) + 48;
		nl = nl / 10;
	}
	return (res);
}