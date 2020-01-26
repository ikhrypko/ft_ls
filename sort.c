/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:22:51 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/04 17:22:53 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_a(t_pl *p, int count)
{
	int		i;
	int		j;
	t_pl	tmp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (p[i].fold && p[j].fold && ft_strcmp(p[i].fold, p[j].fold) > 0)
			{
				tmp = p[j];
				p[j] = p[i];
				p[i] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_t(t_pl *p, int count)
{
	int		i;
	int		j;
	t_pl	tmp;

	i = 0;
	j = 0;
	while (i < count - 1)
	{
		j = count - 1;
		while (i < j)
		{
			if (p[j].timesec > p[j - 1].timesec)
			{
				tmp = p[j - 1];
				p[j - 1] = p[j];
				p[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	sort_r(t_pl *p, int count)
{
	int		i;
	t_pl	tmp;

	i = -1;
	while (++i < count--)
	{
		tmp = p[i];
		p[i] = p[count];
		p[count] = tmp;
	}
}

void	sort_s(t_pl *p, int count)
{
	int		i;
	int		j;
	int		min;
	t_pl	tmp;

	i = -1;
	while (++i < count - 1)
	{
		min = i;
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(p[j].size) > ft_atoi(p[min].size))
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = p[i];
			p[i] = p[min];
			p[min] = tmp;
		}
	}
}

char	**sort_args_a(char **mas, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(mas[i], mas[j]) > 0)
			{
				tmp = mas[j];
				mas[j] = mas[i];
				mas[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (mas);
}
