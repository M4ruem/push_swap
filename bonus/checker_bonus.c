/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:05:42 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:30:36 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	check_word(char const *line, t_ar *ar)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ab(ar, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		push(ar->a, ar->b, &(ar->sizea), &(ar->sizeb));
	else if (ft_strcmp(line, "pb\n") == 0)
		push(ar->b, ar->a, &(ar->sizeb), &(ar->sizea));
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_ab(ar, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rrotate(ar->a, ar->sizea, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrotate(ar->b, ar->sizeb, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrotate_ab(ar, 0);
	else
		return (1);
	return (0);
}

int	check_result(t_ar *ar)
{
	int	i;

	if (ar->sizeb != 0)
	{
		write(2, "KO\n", 3);
		return (1);
	}
	i = 0;
	while (i < ar->sizea - 1)
	{
		if (ar->a[i] > ar->a[i + 1])
		{
			write(2, "KO\n", 3);
			return (1);
		}
		i++;
	}
	write(2, "OK\n", 3);
	return (0);
}

void	checker(t_ar *ar)
{
	char	*rest;
	int		flag;

	flag = 0;
	while (1)
	{
		rest = get_next_line(0);
		if (!rest)
			break ;
		if (check_word(rest, ar) == 1)
			flag = 1;
		free(rest);
	}
	if (flag == 1)
		write(2, "Error\n", 6);
	else
		check_result(ar);
	return ;
}

int	main(int argc, char **argv)
{
	t_ar	*ar;

	if (argc == 1)
		return (0);
	ar = (t_ar *)malloc(sizeof(t_ar));
	if (readnumbers(argc - 1, argv + 1, ar))
		checker(ar);
	free_struct(&ar);
	return (0);
}
