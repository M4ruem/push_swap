/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:55:37 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/10 11:07:55 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pbfirst(t_ar *ar, int *min, int *cnt)
{
	int	count;
	int	av;

	av = get_avg(ar->b, ar->sizeb);
	count = count_avg(ar->b, ar->sizeb, av, 1);
	while (count > 0)
	{
		if (ar->b[0] > av && count--)
			push_ab(ar, 'a');
		else if (ar->b[0] == min[0] && ++(*cnt))
		{
			push_ab(ar, 'a');
			if (ar->b[0] <= av)
				rotate_ab(ar, 1);
			else
				rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->b, ar->sizeb, min);
		}
		else
			rotate(ar->b, ar->sizeb, 2);
	}
}

int	numbers(int argc, char **argv, t_ar *ar, int flag)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < argc)
	{
		ar->a[i] = ft_atoi(argv[i]);
		tmp = ft_strtrim(argv[i]);
		if (!tmp || !isint(tmp) || !isduplicate(ar->a, i))
		{
			if (tmp)
				free(tmp);
			if (flag)
				ft_strddel(argv);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

void	pushsecond(t_ar *ar, int *min, int *cnt)
{
	int	index;
	int	max;

	index = get_max(ar->b, ar->sizeb);
	max = ar->b[index];
	while (ar->b[0] != max)
	{
		if (ar->b[0] == min[0] && ++(*cnt))
		{
			push_ab(ar, 'a');
			rotate(ar->a, ar->sizea, 1);
			min = get_mins(ar->b, ar->sizeb, min);
		}
		else if (index != 0 && index > ar->sizeb / 2)
			rrotate(ar->b, ar->sizeb, 2);
		else
			rotate(ar->b, ar->sizeb, 2);
	}
}

void	pufirst(t_ar *ar, int avg, int *min)
{
	push_ab(ar, 'a');
	if (ar->b[0] <= avg)
		rotate_ab(ar, 1);
	else
		rotate(ar->a, ar->sizea, 1);
	min = get_mins(ar->b, ar->sizeb, min);
}
