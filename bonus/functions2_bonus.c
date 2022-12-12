/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:19 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:40:07 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ft_strddel(char **argv)
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	ft_wordcounter(char const *s, char c, t_ar *ar)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i] != c && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
			count++;
		i++;
	}
	if (count == 0)
	{
		write(2, "Error\n", 6);
		free(ar);
		exit(1);
	}
	return (count);
}

int	isint(char *str)
{
	long int	num;
	int			sign;

	num = 0;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		str++;
		if (!((num * sign) <= 2147483647 && (num * sign) >= -2147483648))
			return (0);
	}
	return ((num * sign) <= 2147483647 && (num * sign) >= -2147483648);
}

int	isduplicate(int *a, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (a[i] == a[j])
			return (0);
		j++;
	}
	return (1);
}

int	readnumbers(int argc, char **argv, t_ar *ar)
{
	int		flag;

	flag = 0;
	if (argc == 1)
	{
		argc = ft_wordcounter(argv[0], ' ', ar);
		argv = ft_strsplit(argv[0], ' ');
		flag = 1;
	}
	ar = init_ar(ar, argc);
	if (numbers(argc, argv, ar, flag) == 0)
		return (0);
	if (flag)
		ft_strddel(argv);
	return (1);
}
