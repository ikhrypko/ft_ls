/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:07:15 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/12 16:07:16 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	proc_file(t_ls *l)
{
	int		koun;
	char	*lel;
	t_pl	*p;
	int		i;
	char	*s;

	s = NULL;
	koun = coun(l->files);
	p = (t_pl *)ft_memalloc(sizeof(t_pl) * (koun));
	i = -1;
	while (++i < koun)
	{
		lel = ft_strjoin(s, l->files[i]);
		writ2(lel, l, &p[i], l->files[i]);
		free(lel);
	}
	sort_a(p, koun);
	g_k.t ? sort_t(p, koun) : 0;
	g_k.s ? sort_s(p, koun) : 0;
	g_k.r ? sort_r(p, koun) : 0;
	g_k.l ? col_len(koun, p, l) : 0;
	print_all(koun, p, l, s);
	free_struct(koun, p);
}

void	print_all(int koun, t_pl *p, t_ls *l, char *s)
{
	char		*tmp;
	static int	i = 0;

	if (s)
	{
		i >= 1 && !g_k.rt ? ft_printf("\n") : 0;
		if (g_ac > 1 && (!g_k.rt || !i))
		{
			tmp = ft_strsub(s, 0, ft_strlen(s) - 1);
			ft_printf("%s:\n", tmp);
			free(tmp);
		}
		if (i >= 1 && g_k.rt && (ft_strcmp(s, "./") != 0))
		{
			tmp = ft_strsub(s, 0, ft_strlen(s) - 1);
			ft_printf("\n%s:\n", tmp);
			free(tmp);
		}
		g_k.l && koun ? ft_printf("total %d\n", l->total) : 0;
	}
	print_up(koun, p, l);
	i++;
}

void	print_col(t_pl *p, int i)
{
	if (p[i].atr[0] == 'd')
	{
		p[i].atr[8] == 'w' && (p[i].atr[9] != 't' && p[i].atr[9] != 'T') ?
		ft_printf("\e[30;43m%s\e[0m", p[i].fold) : 0;
		p[i].atr[8] == 'w' && (p[i].atr[9] == 't' || p[i].atr[9] == 'T') ?
		ft_printf("\e[30;42m%s\e[0m", p[i].fold) : 0;
		p[i].atr[8] != 'w' ? ft_printf("\e[34m%s\e[0m", p[i].fold) : 0;
	}
	else
		print_col_help(p, i);
}

char	*mode_ug(char *str, int mode, char *fullname, t_pl *p)
{
	acl_t		acl;
	char		xattr[1024];

	acl = acl_get_link_np(fullname, 256);
	if (listxattr(fullname, xattr, 1024, 1) > 0)
	{
		p->xat = ft_strdup(xattr);
		str[10] = '@';
	}
	else
		str[10] = (acl != NULL) ? '+' : ' ';
	acl_free(acl);
	if (mode & S_ISUID)
		str[3] = (str[3] == 'x') ? 's' : 'S';
	if (mode & S_ISGID)
		str[6] = (str[6] == 'x') ? 's' : 'S';
	if (mode & S_ISVTX)
		str[9] = (str[9] == 'x') ? 't' : 'T';
	if (str[10] == '@' && g_k.at)
		p->sizeat = getxattr(fullname, p->xat, 0, 1024, 0, 1);
	return (str);
}

char	*mode(char *fullname, int mode, t_pl *p)
{
	char	*str;

	str = ft_strnew(1);
	// str = NULL;
	ft_memset(str, '-', 10);
	(S_ISDIR(mode)) ? str[0] = 'd' : 0;
	(S_ISCHR(mode)) ? str[0] = 'c' : 0;
	(S_ISBLK(mode)) ? str[0] = 'b' : 0;
	(S_ISFIFO(mode)) ? str[0] = 'p' : 0;
	(S_ISLNK(mode)) ? str[0] = 'l' : 0;
	(S_ISSOCK(mode)) ? str[0] = 's' : 0;
	str[1] = (mode & S_IRUSR) ? 'r' : '-';
	str[2] = (mode & S_IWUSR) ? 'w' : '-';
	str[3] = (mode & S_IXUSR) ? 'x' : '-';
	str[4] = (mode & S_IRGRP) ? 'r' : '-';
	str[5] = (mode & S_IWGRP) ? 'w' : '-';
	str[6] = (mode & S_IXGRP) ? 'x' : '-';
	str[7] = (mode & S_IROTH) ? 'r' : '-';
	str[8] = (mode & S_IWOTH) ? 'w' : '-';
	str[9] = (mode & S_IXOTH) ? 'x' : '-';
	return (mode_ug(str, mode, fullname, p));
}
