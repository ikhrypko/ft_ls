/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fold.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:02:32 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/12 16:02:33 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	polo_sort(char **av, int ac, int i, t_ls *l)
{
	char		**mas1;
	char		**mas2;
	DIR			*dir;
	static int	k = 0;
	static int	p = 0;

	mas1 = ft_memalloc(sizeof(char *) * ac);
	mas2 = ft_memalloc(sizeof(char *) * ac);
	while (i < ac)
	{
		if (!(dir = opendir(av[i])))
		{
			if (errno == 2 || errno == 13)
				ft_printf("ft_ls: %s: %s\n", av[i++], strerror(errno));
			else
				mas1[p++] = av[i++];
		}
		else
		{
			mas2[k++] = av[i++];
			closedir(dir);
		}
	}
	l->files = sort_args_a(mas1, p);
	l->folds = sort_args_a(mas2, k);
}

void	polo(char **av, int ac, int i, t_ls *l)
{
	int		j;
	int		koun;
	t_pl	*p;

	polo_sort(av, ac, i, l);
	koun = coun(l->folds);
	p = (t_pl *)ft_memalloc(sizeof(t_pl) * (koun));
	j = -1;
	while (l->folds[++j])
	{
		writ2(l->folds[j], l, &p[j], l->folds[j]);
		l->folds[j] = NULL;
	}
	g_k.t ? sort_t(p, koun) : 0;
	g_k.s ? sort_s(p, koun) : 0;
	g_k.r ? sort_r(p, koun) : 0;
	j = -1;
	while (++j < koun)
		l->folds[j] = ft_strdup(p[j].fold);
	free_struct(koun, p);
}

void	proc_fold(char *s, t_ls *l)
{
	DIR		*dir;
	t_pl	*p;
	char	*lel;
	int		koun;
	int		i;

	i = 0;
	koun = count_file(s, l);
	p = (t_pl *)ft_memalloc(sizeof(t_pl) * (koun));
	if (!(dir = opendir(s)))
		return ;
	while ((l->s_d = readdir(dir)) != NULL)
	{
		if ((!g_k.a && l->s_d->d_name[0] == 46))
			continue ;
		lel = ft_strjoin(s, l->s_d->d_name);
		writ(lel, l, &p[i++]);
		free(lel);
	}
	closedir(dir);
	fold_up(p, koun, l, s);
}

void	print_down(t_pl *p, t_ls *l, int i)
{
	(p[i].atr[0] == 'c' || (p[i].atr[0] == 'b')) && l->size_min == 1 ?
	ft_printf("%5d,%4d ", p[i].maj, p[i].min) : 0;
	p[i].atr[0] != 'c' && (p[i].atr[0] != 'b') && l->size_min == 1 ?
	ft_printf("%7c", ' ') : 0;
	g_k.l && (l->size_min == 0 || (p[i].atr[0] != 'c' &&
		p[i].atr[0] != 'b')) ?
	ft_printf("  %*s ", l->size_len, p[i].size) : 0;
	g_k.l ? ft_printf("%s ", p[i].time) : 0;
	g_k.gt ? print_col(p, i) : ft_printf("%s", p[i].fold);
	g_k.p && p[i].atr[0] == 'd' ? ft_printf("/") : 0;
	p[i].atr[0] == 'l' && g_k.l ?
	ft_printf(" -> %s\n", p[i].lin) : ft_printf("\n");
	g_k.at && p[i].atr[10] == '@' ?
	ft_printf("        %s        %zu\n", p[i].xat, p[i].sizeat) : 0;
}

void	print_up(int koun, t_pl *p, t_ls *l)
{
	int	i;

	i = -1;
	while (++i < koun)
	{
		g_k.i ? ft_printf("%*s ", l->ino_len, p[i].ino) : 0;
		g_k.l ? ft_printf("%s %*s", p[i].atr, l->link_len, p[i].links) : 0;
		g_k.l && !g_k.g ? ft_printf(" %-*s", l->name_len, p[i].name) : 0;
		g_k.l && !g_k.o ? ft_printf("  %-*s", l->group_len, p[i].group) : 0;
		if (g_k.l && ((p[i].atr[0] == 'c') ||
			(p[i].atr[0] == 'b')) && p[i].min > 255)
			ft_printf("%*d, %#.8x ", 5, p[i].maj, p[i].min);
		print_down(p, l, i);
	}
}
