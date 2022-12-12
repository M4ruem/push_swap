/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:40:56 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/10 11:09:12 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_b_third(t_ar *ar, int av, int avg)
{
	int	count;
	int	rra;
	int	max;

	rra = 0;
	count = count_avg(ar->a, ar->sizea, avg, 2);
	while (count > 0)
	{
		if (ar->a[0] > avg && ar->a[0] <= av && count--)
			push_ab(ar, 'b');
		else if (++rra)
			rotate(ar->a, ar->sizea, 1);
	}
	max = ar->b[get_max(ar->b, ar->sizeb)];
	while (rra-- > 0)
	{
		if (ar->b[0] != max)
			rrotate_ab(ar, 1);
		else
			rrotate(ar->a, ar->sizea, 1);
	}
}

static void	push_b_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int	count;

	count = count_avg(ar->a, ar->sizea, avg, 0);
	while (count > 0)
	{
		if (ar->a[0] <= avg && count--)
			push_ab(ar, 'b');
		else
			rotate(ar->a, ar->sizea, 1);
	}
	pbfirst(ar, min, cnt);
}

static void	push_b_fourth(t_ar *ar, int avg, int flag)
{
	while ((flag && ar->a[0] <= avg) || (!flag && ar->a[0] > avg))
		push_ab(ar, 'b');
}

static void	push_b_second(t_ar *ar, int av, int avg, int flag)
{
	int	count;
	int	max;

	count = 0;
	while ((flag && ar->a[0] <= avg) || (!flag && ar->a[0] > avg))
	{
		if (ar->a[0] > av && ++count)
			rotate(ar->a, ar->sizea, 1);
		else
			push_ab(ar, 'b');
	}
	max = ar->b[get_max(ar->b, ar->sizeb)];
	while (count-- > 0)
	{
		if (ar->b[0] == max)
			rrotate(ar->a, ar->sizea, 1);
		else
			rrotate_ab(ar, 1);
	}
}

void	big_sort(t_ar *ar, int avg)
{
	int	*min;
	int	cnt;

	cnt = 0;
	min = (int *)malloc(sizeof(int) * 3);
	push_b_first(ar, avg, get_mins(ar->a, ar->sizea, min), &cnt);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_second(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 0), avg, 1);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 1);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_third(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 1), avg);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_second(ar, get_avg2(ar->a, ar->sizea - cnt, avg, 2), avg, 0);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	push_b_fourth(ar, avg, 0);
	push_a_first(ar, get_avg(ar->b, ar->sizeb),
		get_mins(ar->b, ar->sizeb, min), &cnt);
	free(min);
}
