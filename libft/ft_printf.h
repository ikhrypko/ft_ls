/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:36:35 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/08 15:36:36 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# define MIN_INT -9223372036854775807
# define MIN_STR "9223372036854775808."
# define NULL_STR "(null)"
# define BUFF_SIZE 4096

typedef struct		s_flags
{
	char			*out;
	char			sharp;
	char			zero;
	char			minus;
	char			plus;
	char			space;
	int				l;
	int				lll;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				dot;
	int				reg;
	int				size;
	int				index;
	int				tmp;
	int				wi;
	int				get_wi;
	int				tmp_wi;
	int				tmp_min;
	int				pr;
	int				get_prec;
	int				tmp_prec;
	int				k;
	int				sh;

}					t_flags;

typedef struct		s_buf
{
	char			buf[BUFF_SIZE];
	int				wr_size;
	int				i;
}					t_buf;

t_buf g_buf;

void				write_buff(char c);
int					ft_printf(const char *format, ...);
int					check_flags(char *format, t_flags *p, int i);
int					parsing(char *format, t_flags *p, va_list args, int i);
int					check_width(char *format, t_flags *p, int i, va_list args);
void				check_mod(char c, t_flags *p, va_list args);
int					width_star(t_flags *p, va_list args, int i);
int					precision_star(t_flags *p, va_list args, int i);
intmax_t			ft_switch_types_s(t_flags *p, va_list args);
uintmax_t			ft_switch_types_us(t_flags *p, va_list args);
char				*ft_ftoa(t_flags *p, long double n);
void				type_d(char c, t_flags *p, va_list args);
void				type_c(char c, t_flags *p, va_list args);
void				type_o(char c, t_flags *p, va_list args);
void				type_f(t_flags *p, va_list args);
void				type_s(t_flags *p, va_list args);
void				type_p(t_flags *p, va_list args);
void				type_x(t_flags *p, va_list args);
void				type_u(t_flags *p, va_list args);

#endif
