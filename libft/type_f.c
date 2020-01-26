/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:58:08 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/07 20:58:09 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			if_prec_f(t_flags *p, long double val)
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
	if (p->wi && !p->zero && (!p->minus) && p->wi > p->pr && p->wi > p->tmp)
		while ((p->pr || p->dot) && (p->get_prec--))
			write_buff(' ');
	if (p->wi && (!p->zero) && (!p->minus) && p->wi < p->pr)
		while (p->wi && (p->wi--) - p->tmp)
			write_buff(' ');
}

void			take_prec_f(t_flags *p, long double val)
{
	if (p->wi > 0 && !p->pr)
	{
		p->minus == 1 ? p->zero = 0 : false;
		p->get_wi = (p->wi > p->tmp) ? p->wi - p->tmp : 0;
		if (p->zero == 1 && p->wi > p->tmp)
		{
			while (p->wi && ((p->wi--) - p->tmp))
				write_buff('0');
		}
		if ((p->wi && (!p->zero) && (!p->minus)))
			while (p->wi && p->get_wi--)
				write_buff(' ');
		(p->dot || p->tmp <= p->pr) && p->k == 1 ? write_buff('-') : false;
		(p->dot && !p->zero) && p->plus == 1 ? write_buff('+') : false;
	}
	else if (p->pr > 0 || p->dot)
	{
		if_prec_f(p, val);
		(p->dot || p->tmp <= p->pr) && p->plus == 1 ? write_buff('+') : false;
		(p->dot || p->tmp <= p->pr) && p->k == 1 ? write_buff('-') : false;
		if (p->pr && p->zero && p->pr <= p->tmp)
			while (p->tmp_prec && p->tmp_prec--)
				write_buff('0');
	}
}

long double		z_p_m_f(t_flags *p, long double val)
{
	val < 0 ? p->k = 1 : false;
	if (val < 0)
	{
		if (p->zero == 1)
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
	p->out = ft_ftoa(p, val);
	p->size = ft_strlen(p->out) - 1;
	p->tmp = p->size;
	p->dot && p->pr == 0 ? p->wi++ : p->wi;
	val == 0 && p->dot && !p->pr ? p->size = 0 : false;
	val == 0 && p->wi && p->dot && !p->pr ? p->wi++ : false;
	return (val);
}

long double		take_val_f(t_flags *p, long double val)
{
	val = z_p_m_f(p, val);
	if (p->plus == 1 && val >= 0)
	{
		p->wi && p->zero && !p->pr ? write_buff('+') : false;
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

void			type_f(t_flags *p, va_list args)
{
	long double	val;

	val = (p->lll) ? va_arg(args, long double) : va_arg(args, double);
	val = take_val_f(p, val);
	if ((p->wi > 0 && !p->pr && !p->dot) || (p->pr > 0 || p->dot))
		take_prec_f(p, val);
	!p->dot && !p->zero && p->tmp >= p->pr && p->k == 1 ?
	write_buff('-') : false;
	!p->dot && !p->zero && p->tmp >= p->pr && p->plus == 1 ?
	write_buff('+') : false;
	p->dot && !p->pr ? p->size-- : p->size;
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
