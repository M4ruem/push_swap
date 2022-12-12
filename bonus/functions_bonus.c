/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:41:02 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:30:40 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

#include <stddef.h> // NULL

int	issorted(int *a, int size, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
	{
		while (i < size - 1)
		{
			if (a[i] > a[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < size - 1)
		{
			if (a[i] < a[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

void	free_struct(t_ar **ar)
{
	free((*ar)->a);
	free((*ar)->b);
	free(*ar);
	*ar = NULL;
}

t_ar	*init_ar(t_ar *ar, int size)
{
	ar->sizea = size;
	ar->a = (int *)malloc(sizeof(int) * size);
	ar->sizeb = 0;
	ar->b = (int *)malloc(sizeof(int) * size);
	return (ar);
}
