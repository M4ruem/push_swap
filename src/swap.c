/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:46:22 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:53:09 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *ar, int size, int h)
{
	int	temp;

	if (h == 1)
		write(1, "sa\n", 3);
	else if (h == 2)
		write(1, "sb\n", 3);
	if (size > 1)
	{
		temp = ar[0];
		ar[0] = ar[1];
		ar[1] = temp;
	}
}

void	swap_ab(t_ar *ar, int h)
{
	if (h == 1)
		write(1, "ss\n", 3);
	swap(ar->a, ar->sizea, 0);
	swap(ar->b, ar->sizeb, 0);
}
