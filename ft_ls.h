/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:11:01 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/13 14:11:03 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include "./libft/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <errno.h>
# define VALID "lartRSGgcuinofp@1"

typedef struct s_ls		t_ls;
typedef struct s_keys	t_keys;
typedef struct s_pl		t_pl;

struct				s_ls
{
	char			**folds;
	char			**files;
	size_t			total;
	size_t			link_len;
	size_t			size_len;
	size_t			size_min;
	size_t			group_len;
	size_t			name_len;
	size_t			ino_len;
	struct dirent	*s_d;
	struct stat		s_st;
};

struct				s_keys
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rt;
	int				s;
	int				gt;
	int				g;
	int				c;
	int				u;
	int				i;
	int				n;
	int				f;
	int				p;
	int				o;
	int				at;
};

struct				s_pl
{
	char			*ino;
	char			*atr;
	char			*name;
	char			*group;
	char			*time;
	char			*fold;
	char			*links;
	char			*size;
	char			*lin;
	char			*xat;
	size_t			min;
	size_t			maj;
	size_t			link_l;
	size_t			size_l;
	size_t			group_l;
	size_t			name_l;
	size_t			ino_l;
	ssize_t			sizeat;
	intmax_t		timesec;
};

int					count_file(char *s, t_ls *l);
int					coun(char **str);
char				*mode(char *fullname, int mode, t_pl *p);
char				*mode_ug(char *str, int mode, char *fullname, t_pl *p);
char				**sort_args_a(char **mas, int count);
void				parse_flags(char *str);
void				parse_args(char **av, int ac, int i, t_ls *l);
void				sort_a(t_pl *p, int count);
void				sort_t(t_pl *p, int count);
void				sort_r(t_pl *p, int count);
void				sort_s(t_pl *p, int count);
void				error_invalid(char str);
void				help_exit(char *s, char *path);
void				proc_fold(char *s, t_ls *l);
void				col_len(int koun, t_pl *p, t_ls *l);
void				recurs(t_pl *p, t_ls *l, char *s, int koun);
void				free_struct(int koun, t_pl *p);
void				times(t_ls *l, t_pl *p);
void				writ(char *lel, t_ls *l, t_pl *p);
void				writ2(char *lel, t_ls *l, t_pl *p, char *name);
void				polo(char **av, int ac, int i, t_ls *l);
void				polo_sort(char **av, int ac, int i, t_ls *l);
void				fold_up(t_pl *p, int koun, t_ls *l, char *s);
void				print_up(int koun, t_pl *p, t_ls *l);
void				print_down(t_pl *p, t_ls *l, int i);
void				proc_file(t_ls *l);
void				print_all(int koun, t_pl *p, t_ls *l, char *s);
void				print_col(t_pl *p, int i);
void				print_col_help(t_pl *p, int i);
void				zero_l(t_ls *l);

t_keys	g_k;
int		g_ac;

#endif
