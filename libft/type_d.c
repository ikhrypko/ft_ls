/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 16:36:47 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/12/31 19:56:01 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			if_prec(t_flags *p, intmax_t val)
{
	if (p->wi > p->pr)
	{
		p->get_prec = (p->pr > p->size) ? p->wi - p->pr : p->wi - p->tmp;
		p->tmp_prec = p->get_prec;
		if (!p->wi && p->pr > 0)
		{
			p->get_wi = p->pr;
			p->wi = p->pr;
		}
	}
	else if (p->wi < p->pr)
	{
		p->get_wi = p->pr - p->size;
		p->tmp_prec = 0;
		p->wi = 0;
	}
	if (p->plus == 1 && val >= 0 && p->wi >= p->pr)
		p->get_wi--;
	p->space && p->pr ? p->get_prec-- : p->get_prec;
	if (p->wi && (!p->minus) && p->wi > p->pr && p->wi > p->tmp)
		while ((p->pr || p->dot) && (p->get_prec--))
			write_buff(' ');
}

void			take_prec(t_flags *p, intmax_t val)
{
	if (p->wi > 0 && !p->pr && !p->dot)
	{
		p->minus == 1 ? p->zero = 0 : false;
		p->get_wi = (p->wi > p->tmp) ? p->wi - p->tmp : 0;
		if (p->zero == 1 && !p->dot && p->wi > p->tmp)
			while (p->wi && ((p->wi--) - p->tmp))
				write_buff('0');
		if ((p->wi && (!p->zero) && (!p->minus)) || (p->dot && !p->pr))
			while (p->wi && p->get_wi--)
				write_buff(' ');
	}
	else if (p->pr > 0 || p->dot)
	{
		if_prec(p, val);
		if (p->wi && (!p->zero) && (!p->minus) && p->wi < p->pr)
			while (p->wi && (p->wi--) - p->tmp)
				write_buff(' ');
		(p->dot || p->tmp <= p->pr) && p->plus == 1 ? write_buff('+') : false;
		(p->dot || p->tmp <= p->pr) && p->k == 1 ? write_buff('-') : false;
		if (p->pr && p->pr >= p->tmp)
			while (p->pr && (p->get_wi--) - p->tmp_prec)
				write_buff('0');
	}
}

intmax_t		z_p_m(t_flags *p, intmax_t val)
{
	val < 0 ? p->k = 1 : false;
	if (val < 0)
	{
		if (p->zero == 1 && !p->dot)
		{
			write_buff('-');
			p->k = 0;
		}
		val == MIN_INT - 1 ? p->k = 0 : false;
		val < 0 ? val = -val : false;
		p->plus = 0;
		p->space = 0;
		p->wi && p->pr >= p->tmp ? p->wi-- : p->wi;
	}
	p->out = ft_itoa(val);
	p->size = ft_strlen(p->out);
	val == 0 && p->dot && !p->pr ? p->size = 0 : false;
	val == 0 && p->wi && p->dot && !p->pr ? p->wi++ : false;
	return (val);
}

intmax_t		take_val(t_flags *p, intmax_t val)
{
	val = z_p_m(p, val);
	if (p->plus == 1 && val >= 0)
	{
		p->wi && p->zero && !p->pr && !p->dot ? write_buff('+') : false;
		p->space = 0;
		p->wi ? p->wi-- : p->wi;
	}
	if (p->space == 1 && val >= 0)
	{
		p->wi && !p->pr && !p->minus ? p->wi-- : p->wi;
		write_buff(' ');
	}
	return (val);
}

void			type_d(char c, t_flags *p, va_list args)
{
	intmax_t	val;

	val = (c == 'D') ? va_arg(args, long long) : ft_switch_types_s(p, args);
	p->tmp = ft_get_str_len(val);
	p->get_wi = p->wi - p->tmp;
	val = take_val(p, val);
	if ((p->wi > 0 && !p->pr && !p->dot) || (p->pr > 0 || p->dot))
		take_prec(p, val);
	!p->dot && !p->zero && p->tmp >= p->pr && p->k == 1 ?
	write_buff('-') : false;
	!p->dot && !p->zero && p->tmp >= p->pr && p->plus == 1 ?
	write_buff('+') : false;
	while (p->size--)
		write_buff(p->out[p->index++]);
	if (p->minus && p->wi >= p->pr && p->wi > p->tmp)
		p->space ? p->wi-- : false;
	p->tmp_min = (p->pr > p->tmp) ? p->wi - p->pr : p->wi - p->tmp;
	if (p->minus && p->wi > p->tmp)
		while (p->wi && p->tmp_min--)
			write_buff(' ');
	free(p->out);
	ft_bzero(p, sizeof(t_flags));
}
