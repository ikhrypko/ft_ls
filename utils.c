/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:23:13 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/17 16:23:15 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_args(char **av, int ac, int i, t_ls *l)
{
	int		j;
	char	*tmp;

	if (g_k.f)
	{
		g_k.a = 1;
		g_k.t = 0;
		g_k.r = 0;
		g_k.s = 0;
	}
	(g_k.o || g_k.n || g_k.g) ? g_k.l = 1 : 0;
	polo(av, ac, i, l);
	g_ac = ac - i;
	j = -1;
	if (l->files[0])
		proc_file(l);
	if (l->folds[0] == NULL && g_ac == 0)
		proc_fold("./", l);
	else
		while (l->folds[++j])
		{
			tmp = ft_strjoin(l->folds[j], "/");
			proc_fold(tmp, l);
			free(tmp);
		}
}

void	parse_flags(char *str)
{
	int		i;

	i = 0;
	while ((ft_strchr(VALID, str[++i]) && str[i]))
	{
		(str[i] == 'l') ? g_k.l = 1 : 0;
		(str[i] == 'a') ? g_k.a = 1 : 0;
		(str[i] == 'r') ? g_k.r = 1 : 0;
		(str[i] == 't') ? g_k.t = 1 : 0;
		(str[i] == 'R') ? g_k.rt = 1 : 0;
		(str[i] == 'S') ? g_k.s = 1 : 0;
		(str[i] == 'G') ? g_k.gt = 1 : 0;
		(str[i] == 'g') ? g_k.g = 1 : 0;
		(str[i] == 'c') ? g_k.c = 1 : 0;
		(str[i] == 'u') ? g_k.u = 1 : 0;
		(str[i] == 'i') ? g_k.i = 1 : 0;
		(str[i] == 'n') ? g_k.n = 1 : 0;
		(str[i] == 'o') ? g_k.o = 1 : 0;
		(str[i] == 'f') ? g_k.f = 1 : 0;
		(str[i] == 'p') ? g_k.p = 1 : 0;
		(str[i] == '@') ? g_k.at = 1 : 0;
	}
	error_invalid(str[i]);
}

void	fold_up(t_pl *p, int koun, t_ls *l, char *s)
{
	sort_a(p, koun);
	g_k.s ? sort_s(p, koun) : 0;
	g_k.s ? g_k.t = 0 : 0;
	g_k.t ? sort_t(p, koun) : 0;
	g_k.r ? sort_r(p, koun) : 0;
	g_k.l ? col_len(koun, p, l) : 0;
	print_all(koun, p, l, s);
	g_k.rt ? recurs(p, l, s, koun) : free_struct(koun, p);
	l->total = 0;
}

void	print_col_help(t_pl *p, int i)
{
	if (p[i].atr[0] == 'l')
		ft_printf("\e[35m%s\e[0m", p[i].fold);
	else if (p[i].atr[0] == 'c')
		ft_printf("\e[34;43m%s\e[0m", p[i].fold);
	else if (p[i].atr[0] == 'b')
		ft_printf("\e[34;46m%s\e[0m", p[i].fold);
	else if (p[i].atr[0] == 'p')
		ft_printf("\e[33m%s\e[0m", p[i].fold);
	else if (ft_strchr(p[i].atr, 'x') && !(ft_strchr(p[i].atr, 's')))
		ft_printf("\e[31m%s\e[0m", p[i].fold);
	else if (p[i].atr[0] == 's')
		ft_printf("\e[32m%s\e[0m", p[i].fold);
	else if (p[i].atr[3] == 's')
		ft_printf("\e[30;41m%s\e[0m", p[i].fold);
	else if (p[i].atr[6] == 's')
		ft_printf("\e[30;46m%s\e[0m", p[i].fold);
	else
		ft_printf("%s", p[i].fold);
}

void	zero_l(t_ls *l)
{
	l->link_len = 0;
	l->size_len = 0;
	l->group_len = 0;
	l->name_len = 0;
	l->ino_len = 0;
}
