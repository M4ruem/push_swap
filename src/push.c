/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:50 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 19:22:40 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(int *a, int *b, int *size, int *sizeb)
{
	int	tmp;
	int	i;

	if (*sizeb > 0)
	{
		tmp = a[0];
		a[0] = b[0];
		i = 1;
		while (i < *size)
		{
			b[0] = a[i];
			a[i] = tmp;
			tmp = b[0];
			i++;
		}
		a[i] = tmp;
		(*size)++;
		(*sizeb)--;
		i = 0;
		while (i < *sizeb)
		{
			b[i] = b[i + 1];
			i++;
		}
	}
}

void	push_ab(t_ar *ar, char c)
{
	if (c == 'a')
	{
		push(ar->a, ar->b, &(ar->sizea), &(ar->sizeb));
		write(1, "pa\n", 3);
	}
	else
	{
		push(ar->b, ar->a, &(ar->sizeb), &(ar->sizea));
		write(1, "pb\n", 3);
	}
}
