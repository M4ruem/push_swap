/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:58 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/10 11:09:14 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_avg(int *a, int size, int avg, int flag)
{
	int	count;
	int	av;

	count = 0;
	av = get_avg2(a, size, avg, 1);
	while (--size >= 0)
		if ((flag == 0 && a[size] <= avg) || (flag == 1 && a[size] > avg)
			|| (flag == 2 && a[size] > avg && a[size] <= av))
			count++;
	return (count);
}

static void	push_a_second(t_ar *ar, int *min, int *cnt)
{
	int	ra;

	ra = 0;
	while (ar->sizeb > 0)
	{
		pushsecond(ar, min, cnt);
		push_ab(ar, 'a');
		ra++;
	}
	while (ra-- > 0 && ++(*cnt))
		rotate(ar->a, ar->sizea, 1);
}

static	void	push_a_recursive(t_ar *ar, int *min, int *cnt, int flag)
{
	int	count;

	count = count_avg(ar->b, ar->sizeb, get_avg(ar->b, ar->sizeb), 1);
	if ((flag && count > 9) || (flag && count > 17))
		push_a_first(ar, get_avg(ar->b, ar->sizeb), min, cnt);
	else
		push_a_second(ar, min, cnt);
}

static void	push_a_help(t_ar *ar, int *min, int *cnt, int ret)
{
	int	mmin;

	mmin = min[0] < ar->b[get_min(ar->b, ar->sizeb)];
	while (ret-- > 0)
	{
		if (min[0] == ar->a[0] && mmin)
		{
			rotate(ar->a, ar->sizea, 1);
			++(*cnt);
			min = get_mins(ar->a, ar->sizea - *cnt, min);
		}
		else
			push_ab(ar, 'b');
	}
}

void	push_a_first(t_ar *ar, int avg, int *min, int *cnt)
{
	int	count;
	int	ret;
	int	flag;

	ret = 0;
	flag = (ar->sizea + ar->sizeb) > 200;
	count = count_avg(ar->b, ar->sizeb, avg, 1);
	while ((count > 9 && !flag) || (count > 17 && flag))
	{
		while (count > 0)
		{
			if (avg == 0)
				avg = get_avg(ar->b, ar->sizeb);
			if (ar->b[0] > avg && count-- && ++ret)
				push_ab(ar, 'a');
			else if (ar->b[0] == min[0] && ++(*cnt))
				pufirst(ar, avg, min);
			else
				rotate(ar->b, ar->sizeb, 2);
		}
	}
	push_a_second(ar, get_mins(ar->b, ar->sizeb, min), cnt);
	push_a_help(ar, get_mins(ar->a, ar->sizea - *cnt, min), cnt, ret);
	push_a_recursive(ar, get_mins(ar->b, ar->sizeb, min), cnt, flag);
}
