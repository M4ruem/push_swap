/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:38:03 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/12 15:38:34 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ar
{
	int			*a;
	int			*b;
	int			sizea;
	int			sizeb;
}				t_ar;

/* -------------------------------------------------------------------------- */
/*                                    rules                                   */
/* -------------------------------------------------------------------------- */

void			swap(int *ar, int size, int h);
void			swap_ab(t_ar *ar, int h);
void			push(int *a, int *b, int *size, int *sizeb);
void			push_ab(t_ar *ar, char c);
void			rotate(int *ar, int size, int h);
void			rotate_ab(t_ar *ar, int h);
void			rrotate(int *ar, int size, int h);
void			rrotate_ab(t_ar *ar, int h);

/* -------------------------------------------------------------------------- */
/*                                 functions                              */
/* -------------------------------------------------------------------------- */

int				issorted(int *a, int size, char c);
void			free_struct(t_ar **ar);
t_ar			*init_ar(t_ar *ar, int size);

/* -------------------------------------------------------------------------- */
/*                                    algo                                    */
/* -------------------------------------------------------------------------- */

int				readnumbers(int argc, char **argv, t_ar *ar);
void			small_sort(int *a, int size);
void			sort(t_ar *ar);
void			big_sort(t_ar *ar, int avg);

/* -------------------------------------------------------------------------- */
/*                                     get                                    */
/* -------------------------------------------------------------------------- */

int				get_avg2(int *a, int size, int avg, int flag);
int				get_avg(int *a, int size);
int				get_max(int *b, int size);
int				get_min(int *b, int size);
int				*get_maxs(int *ar, int size, int *max);
int				*get_mins(int *ar, int size, int *min);

/* -------------------------------------------------------------------------- */
/*                                    push                                    */
/* -------------------------------------------------------------------------- */

int				count_avg(int *a, int size, int avg, int flag);
void			push_a_first(t_ar *ar, int avg, int *min, int *cnt);

/* -------------------------------------------------------------------------- */
/*                                    utils                                   */
/* -------------------------------------------------------------------------- */

void			pbfirst(t_ar *ar, int *min, int *cnt);
int				numbers(int argc, char **argv, t_ar *ar, int flag);
void			pushsecond(t_ar *ar, int *min, int *cnt);
void			pufirst(t_ar *ar, int avg, int *min);

/* -------------------------------------------------------------------------- */
/*                                 functions2                                 */
/* -------------------------------------------------------------------------- */

int				isint(char *str);
int				isduplicate(int *a, int i);
void			ft_strddel(char **argv);

#endif
