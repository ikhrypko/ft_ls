/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:21:35 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/03 21:21:36 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			if_prec_u(t_flags *p)
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
	if (p->wi && (!p->minus) && p->wi > p->pr && p->wi > p->tmp)
		while ((p->pr || p->dot) && (p->get_prec--))
			write_buff(' ');
}

void			take_prec_u(t_flags *p)
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
		if_prec_u(p);
		if (p->wi && (!p->zero) && (!p->minus) && p->wi < p->pr)
			while (p->wi && (p->wi--) - p->tmp)
				write_buff(' ');
		if (p->pr && p->pr >= p->tmp)
			while (p->pr && (p->get_wi--) - p->tmp_prec)
				write_buff('0');
	}
}

uintmax_t		take_val_u(t_flags *p, uintmax_t val)
{
	p->out = ft_utoa(val);
	p->size = ft_strlen(p->out);
	val == 0 && p->dot && !p->pr ? p->size = 0 : false;
	val == 0 && p->wi && p->dot && !p->pr ? p->wi++ : false;
	return (val);
}

void			type_u(t_flags *p, va_list args)
{
	uintmax_t	val;

	val = (p->k == 1) ?
	va_arg(args, unsigned long) : ft_switch_types_us(p, args);
	p->tmp = ft_get_str_len(val);
	p->get_wi = p->wi - p->tmp;
	val = take_val_u(p, val);
	if ((p->wi > 0 && !p->pr && !p->dot) || (p->pr > 0 || p->dot))
		take_prec_u(p);
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
