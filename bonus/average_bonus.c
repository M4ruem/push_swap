/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:26 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:30:24 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	get_avg2bis(int *a, int size, int avg)
{
	double	sum;
	int		count;
	int		i;

	i = -1;
	sum = 0;
	count = 0;
	while (++i < size)
	{
		if (a[i] > avg && ++count)
			sum += a[i];
		else
			sum += 0;
	}
}

int	get_avg2(int *a, int size, int avg, int flag)
{
	double	sum;
	int		count;
	int		i;

	i = -1;
	count = 0;
	sum = 0;
	while (++i < size)
	{
		if (((!flag && a[i] < avg) || (flag && a[i] > avg)) && ++count)
			sum += a[i];
		else
			sum += 0;
	}
	if (flag == 0 || flag == 1)
		return ((int)(sum / count - 0.5));
	avg = (int)(sum / count - 0.5);
	get_avg2bis(a, size, avg);
	return ((int)(sum / count - 0.5));
}
