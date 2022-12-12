/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:45:34 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 19:18:16 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	push_swap(t_ar *ar)
{
	if (issorted(ar->a, ar->sizea, 'a'))
		return ;
	if (ar->sizea < 3)
		small_sort(ar->a, ar->sizea);
	else if (ar->sizea < 6)
		sort(ar);
	else
		big_sort(ar, get_avg(ar->a, ar->sizea));
}

int	main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = (t_ar *)malloc(sizeof(t_ar));
	if (readnumbers(argc - 1, argv + 1, ar))
		push_swap(ar);
	else
		write(2, "Error\n", 6);
	free_struct(&ar);
	return (0);
}
