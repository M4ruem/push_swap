/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:41:27 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/10 11:09:27 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_avg(int *a, int size)
{
	double	count;
	int		i;

	i = 0;
	count = 0;
	while (i < size)
		count += a[i++];
	return ((int)(count / size - 0.5));
}

int	get_max(int *b, int size)
{
	int	index;

	index = 0;
	while (--size > 0)
	{
		if (b[size] > b [index])
			index = size;
	}
	return (index);
}

int	get_min(int *b, int size)
{
	int	index;

	index = 0;
	while (--size > 0)
	{
		if (b[size] < b[index])
			index = size;
	}
	return (index);
}

int	*get_mins(int *ar, int size, int *min)
{
	min[0] = ar[0];
	min[1] = ar[get_max(ar, size)];
	min[2] = min[1];
	while (--size > 0)
	{
		if (min[0] > ar[size])
		{
			min[2] = min[1];
			min[1] = min[0];
			min[0] = ar[size];
		}
		else if (min[1] > ar[size])
		{
			min[2] = min[1];
			min[1] = ar[size];
		}
		else if (min[2] > ar[size])
			min[2] = ar[size];
	}
	return (min);
}

int	*get_maxs(int *ar, int size, int *max)
{
	max[0] = ar[0];
	max[1] = ar[get_min(ar, size)];
	max[2] = max[1];
	while (--size > 0)
	{
		if (max[0] < ar[size])
		{
			max[2] = max[1];
			max[1] = max[0];
			max[0] = ar[size];
		}
		else if (max[1] < ar[size])
		{
			max[2] = max[1];
			max[1] = ar[size];
		}
		else if (max[2] < ar[size])
			max[2] = ar[size];
	}
	return (max);
}
