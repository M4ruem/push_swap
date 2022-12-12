/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:46:13 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:31:47 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	rotate(int *ar, int size, int h)
{
	int	tmp;
	int	b;
	int	i;

	if (h == 1)
		write(1, "ra\n", 3);
	else if (h == 2)
		write(1, "rb\n", 3);
	if (size > 1)
	{
		b = ar[size - 1];
		ar[size - 1] = ar[0];
		i = size - 2;
		while (i >= 0)
		{
			tmp = ar[i];
			ar[i] = b;
			b = tmp;
			i--;
		}
	}
}

void	rotate_ab(t_ar *ar, int h)
{
	if (h == 1)
		write(1, "rr\n", 3);
	rotate(ar->a, ar->sizea, 0);
	rotate(ar->b, ar->sizeb, 0);
}

void	rrotate(int *ar, int size, int h)
{
	int	tmp;
	int	b;
	int	i;

	if (h == 1)
		write(1, "rra\n", 4);
	else if (h == 2)
		write(1, "rrb\n", 4);
	if (size > 1)
	{
		b = ar[0];
		ar[0] = ar[size - 1];
		i = 1;
		while (i < size)
		{
			tmp = ar[i];
			ar[i] = b;
			b = tmp;
			i++;
		}
	}
}

void	rrotate_ab(t_ar *ar, int h)
{
	if (h == 1)
		write(1, "rrr\n", 4);
	rrotate(ar->a, ar->sizea, 0);
	rrotate(ar->b, ar->sizeb, 0);
}
