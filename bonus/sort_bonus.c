/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:46:18 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:31:50 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	push_a(t_ar *ar, int *max)
{
	int	flag;

	max = get_maxs(ar->b, ar->sizeb, max);
	flag = 0;
	while (ar->sizeb > 0)
	{
		if (ar->b[0] == max[0])
		{
			push_ab(ar, 'a');
			if (flag)
				swap(ar->a, ar->sizea, 1);
			flag = 0;
			max = get_maxs(ar->b, ar->sizeb, max);
		}
		else if (ar->b[0] == max[1])
		{
			push_ab(ar, 'a');
			flag = 1;
		}
	}
}

static void	push_b(t_ar *ar, int *max)
{
	while (ar->sizea > 3)
	{
		if (ar->a[0] < max[2])
			push_ab(ar, 'b');
		else
			rotate(ar->a, ar->sizea, 1);
	}
}

void	sort(t_ar *ar)
{
	int	*max;

	max = (int *)malloc(sizeof(int) * 3);
	max = get_maxs(ar->a, ar->sizea, max);
	push_b(ar, max);
	small_sort(ar->a, ar->sizea);
	push_a(ar, max);
	free(max);
}
