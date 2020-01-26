/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:50:24 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/12 15:50:25 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_invalid(char str)
{
	if (!ft_strchr(VALID, str))
	{
		ft_printf("ft_ls: illegal option -- %c\n", str);
		ft_printf("usage : ft_ls [%s] [file ...]\n", VALID);
		exit(EXIT_FAILURE);
	}
}

void	free_struct(int koun, t_pl *p)
{
	int i;

	i = -1;
	while (++i < koun)
	{
		free(p[i].atr);
		free(p[i].name);
		free(p[i].group);
		free(p[i].time);
		free(p[i].fold);
		free(p[i].links);
		free(p[i].size);
		free(p[i].ino);
		free(p[i].lin);
		free(p[i].xat);
	}
	free(p);
}

void	help_exit(char *s, char *path)
{
	g_k.rt ? path = ft_strsub(s, 0, ft_strlen(s) - 1) : 0;
	g_k.rt ? ft_printf("\n%s:\n", path) : 0;
	g_k.rt ? free(path) : 0;
	ft_printf("ft_ls: %s: %s", s, strerror(errno));
	g_k.rt ? ft_printf("\n") : 0;
}

int		coun(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	col_len(int koun, t_pl *p, t_ls *l)
{
	int		q;

	q = -1;
	while (++q < koun)
	{
		p[q].atr[0] == 'c' || p[q].atr[0] == 'b' ? l->size_min = 1 : 0;
		l->link_len < ft_strlen(p[q].links) ?
		l->link_len = ft_strlen(p[q].links) : 0;
		l->group_len < ft_strlen(p[q].group) ?
		l->group_len = ft_strlen(p[q].group) : 0;
		l->name_len < ft_strlen(p[q].name) ?
		l->name_len = ft_strlen(p[q].name) : 0;
		l->size_len < ft_strlen(p[q].size) ?
		l->size_len = ft_strlen(p[q].size) : 0;
		l->ino_len < ft_strlen(p[q].ino) ?
		l->ino_len = ft_strlen(p[q].ino) : 0;
	}
}
