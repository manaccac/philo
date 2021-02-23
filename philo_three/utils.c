/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:27:58 by jdel-ros          #+#    #+#             */
/*   Updated: 2021/02/23 10:31:00 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				ft_atoi(char *nptr)
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

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
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

int				put_error(char *err)
{
	int i;

	i = 0;
	while (err[i])
	{
		ft_putchar(err[i]);
		i++;
	}
	return (0);
}
