/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tch.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:55:25 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/02/12 15:55:26 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurs(t_pl *p, t_ls *l, char *s, int koun)
{
	char	*path;
	char	*tmp;
	int		q;

	q = -1;
	if (g_k.rt && koun == -1)
		free(p);
	while (++q < koun)
	{
		if (p[q].atr[0] == 'd' &&
			((ft_strcmp(p[q].fold, ".") != 0) &&
				(ft_strcmp(p[q].fold, "..") != 0)))
		{
			tmp = ft_strjoin(s, p[q].fold);
			path = ft_strjoin(tmp, "/");
			free(tmp);
			l->total = 0;
			zero_l(l);
			proc_fold(path, l);
			free(path);
		}
	}
	free_struct(koun, p);
}

int		count_file(char *s, t_ls *l)
{
	char	*path;
	DIR		*dir;
	int		ko;

	path = NULL;
	ko = 0;
	if (!(dir = opendir(s)))
	{
		help_exit(s, path);
		return (-1);
	}
	while ((l->s_d = readdir(dir)) != NULL)
	{
		if (!g_k.a && l->s_d->d_name[0] == 46)
			continue ;
		path = ft_strjoin(s, l->s_d->d_name);
		lstat(path, &l->s_st);
		ko++;
		l->total += l->s_st.st_blocks;
		free(path);
	}
	closedir(dir);
	return (ko);
}

void	times(t_ls *l, t_pl *p)
{
	intmax_t	i;

	if (g_k.u)
	{
		p->time = ft_strsub(ctime(&l->s_st.st_atime), 4, 20);
		p->timesec = l->s_st.st_atimespec.tv_sec;
	}
	else if (g_k.c)
	{
		p->time = ft_strsub(ctime(&l->s_st.st_ctime), 4, 20);
		p->timesec = l->s_st.st_ctimespec.tv_sec;
	}
	else
	{
		p->time = ft_strsub(ctime(&l->s_st.st_mtime), 4, 20);
		p->timesec = l->s_st.st_mtimespec.tv_sec;
	}
	p->time[12] = '\0';
	i = time(0) - p->timesec;
	if (i > 15768000 || i < 0)
		ft_memmove(p->time + 7, p->time + 15, 5);
}

void	writ(char *lel, t_ls *l, t_pl *p)
{
	char	buf[1024];

	ft_bzero(buf, 1024);
	lstat(lel, &l->s_st);
	times(l, p);
	p->name = (g_k.n) ? ft_itoa(l->s_st.st_uid) :
	ft_strdup(((struct passwd *)getpwuid(l->s_st.st_uid))->pw_name);
	p->group = (g_k.n) ? ft_itoa(l->s_st.st_gid) :
	ft_strdup(((struct group *)getgrgid(l->s_st.st_gid))->gr_name);
	p->fold = ft_strdup(l->s_d->d_name);
	p->links = ft_itoa(l->s_st.st_nlink);
	p->size = ft_itoa(l->s_st.st_size);
	p->ino = ft_itoa(l->s_st.st_ino);
	p->atr = mode(lel, l->s_st.st_mode, p);
	if (p->atr[0] == 'l' && readlink(lel, buf, 1024) != -1)
		p->lin = ft_strdup(buf);
	p->min = minor(l->s_st.st_rdev);
	p->maj = major(l->s_st.st_rdev);
}

void	writ2(char *lel, t_ls *l, t_pl *p, char *name)
{
	char	buf[1024];

	ft_bzero(buf, 1024);
	lstat(lel, &l->s_st);
	p->name = (g_k.n) ? ft_itoa(l->s_st.st_uid) :
	ft_strdup(((struct passwd *)getpwuid(l->s_st.st_uid))->pw_name);
	p->group = (g_k.n) ? ft_itoa(l->s_st.st_gid) :
	ft_strdup(((struct group *)getgrgid(l->s_st.st_gid))->gr_name);
	times(l, p);
	p->fold = ft_strdup(name);
	p->links = ft_itoa(l->s_st.st_nlink);
	p->size = ft_itoa(l->s_st.st_size);
	p->ino = ft_itoa(l->s_st.st_ino);
	p->atr = mode(lel, l->s_st.st_mode, p);
	if (p->atr[0] == 'l' && readlink(lel, buf, 1024) != -1)
		p->lin = ft_strdup(buf);
	p->min = minor(l->s_st.st_rdev);
	p->maj = major(l->s_st.st_rdev);
}
