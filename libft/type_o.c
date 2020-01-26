/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:14:53 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/04 16:14:54 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_sharp_o(t_flags *p, intmax_t val)
{
	if (p->sharp)
	{
		if (val == 0 && p->dot)
		{
			write_buff('0');
			p->wi && !p->pr ? p->wi-- : p->wi;
		}
		else if (val != 0)
			write_buff('0');
	}
	if (p->zero == 1 && !p->dot && !p->minus && p->wi > p->size)
	{
		p->minus = 0;
		p->tmp_wi = ((p->wi - p->size - p->sh) > 0) ?
		p->wi - p->size - p->sh : 0;
		while (p->wi && p->tmp_wi--)
			write_buff('0');
	}
}

void	take_o_with_sharp(t_flags *p, uintmax_t val)
{
	val == 0 && p->dot ? p->size = 0 : false;
	if (!p->sharp && p->wi && !p->minus && p->wi > p->size)
	{
		p->wi > p->pr ? p->get_wi = p->wi - p->size : false;
		if (p->wi && p->pr && p->wi > p->pr && p->pr > p->size)
			p->get_wi = p->wi - p->pr;
	}
	else
	{
		if (p->wi && !p->minus && p->wi > (p->size + p->sh))
		{
			p->wi > p->pr ? p->get_wi = p->wi - (p->size + p->sh) : false;
			val == 0 && (p->wi || p->dot) ?
			p->get_wi = p->wi - p->size - p->sh : false;
			p->get_wi == p->wi && val == 0 && p->pr ?
			p->get_wi = 0 : false;
			if (p->wi && p->pr && p->wi > p->pr && p->pr > p->size && !p->minus)
			{
				p->get_wi = ((p->wi - p->pr) > 0) ?
				p->wi - p->pr : false;
				val == 0 && p->sharp && p->pr ?
				p->get_wi = p->wi - p->pr : false;
			}
		}
	}
}

void	take_o(t_flags *p, uintmax_t val)
{
	val == 0 && p->zero && !p->dot ? p->get_wi = 0 : false;
	take_o_with_sharp(p, val);
	while (p->wi && (!p->zero || p->dot) && p->get_wi--)
		write_buff(' ');
	take_sharp_o(p, val);
	if (p->minus && (p->wi || p->dot) && p->wi > p->pr)
	{
		if (val == 0)
		{
			if (!p->pr)
				p->tmp_min = (p->wi - p->size > 0) ? p->wi - p->size : false;
			else
				p->tmp_min = (p->wi - p->pr > 0) ? p->wi - p->pr : false;
		}
		else
		{
			p->tmp_min = (p->wi - p->size - p->sh > 0) ?
			p->wi - p->size - p->sh : false;
			p->pr > p->size ? p->tmp_min = p->wi - p->pr : false;
		}
	}
}

void	type_o(char c, t_flags *p, va_list args)
{
	uintmax_t	val;

	val = (c == 'O') ? va_arg(args, unsigned long) :
	ft_switch_types_us(p, args);
	p->out = ft_itoa_base(val, 8, p->reg);
	p->size = ft_strlen(p->out);
	p->sh = (p->sharp == 1) ? 1 : 0;
	take_o(p, val);
	if (p->pr && p->pr > p->size)
		while ((p->pr--) - (p->size + p->sh))
			write_buff('0');
	while (p->size--)
		write_buff(p->out[p->index++]);
	if (p->minus && p->wi)
		while (p->tmp_min--)
			write_buff(' ');
	free(p->out);
	ft_bzero(p, sizeof(t_flags));
}
