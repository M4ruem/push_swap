/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:34 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:31:39 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	small_sort(int *a, int size)
{
	if (size == 2 && a[0] > a[1])
		swap(a, size, 1);
	while (!(issorted(a, size, 'a')))
	{
		if (a[0] > a[1] && a[0] > a[2])
			rotate(a, size, 1);
		else if (a[0] > a[1] && a[0] < a[2])
			swap(a, size, 1);
		else
			rrotate(a, size, 1);
	}
}
