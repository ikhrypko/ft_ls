/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:11:49 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/03 19:30:18 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_sharp_b(t_flags *p, intmax_t val)
{
	if (p->sharp && val > 0)
	{
		write_buff('0');
		p->reg == 0 ? write_buff('x') : write_buff('X');
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

void	take_x_with_sharp(t_flags *p, uintmax_t val)
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
		if (p->wi && !p->minus && p->wi > (p->size + 2))
		{
			p->wi > p->pr ? p->get_wi = p->wi - (p->size + 2) : false;
			val == 0 && (p->wi || p->dot) ?
			p->get_wi = p->wi - p->size : false;
			p->get_wi == p->wi && val == 0 && p->pr ?
			p->get_wi = 0 : false;
			if (p->wi && p->pr && p->wi > p->pr && p->pr > p->size && !p->minus)
			{
				p->get_wi = ((p->wi - p->pr - 2) > 0) ?
				p->wi - p->pr - 2 : false;
				val == 0 && p->sharp && p->pr ?
				p->get_wi = p->wi - p->pr : false;
			}
		}
	}
}

void	take_x(t_flags *p, uintmax_t val)
{
	val == 0 && p->zero && !p->dot ? p->get_wi = 0 : false;
	take_x_with_sharp(p, val);
	while (p->wi && (!p->zero || p->dot) && p->get_wi--)
		write_buff(' ');
	take_sharp_b(p, val);
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
			if (p->pr > p->size)
				p->tmp_min = (p->wi - p->pr - p->sh > 0) ?
			p->wi - p->pr - p->sh : false;
		}
	}
}

void	type_x(t_flags *p, va_list args)
{
	uintmax_t	val;

	val = ft_switch_types_us(p, args);
	p->out = ft_itoa_base(val, 16, p->reg);
	p->size = ft_strlen(p->out);
	p->sh = (p->sharp == 1) ? 2 : 0;
	take_x(p, val);
	if (p->pr && p->pr > p->size)
		while ((p->pr--) - p->size)
			write_buff('0');
	while (p->size--)
		write_buff(p->out[p->index++]);
	if (p->minus && p->wi)
		while (p->tmp_min--)
			write_buff(' ');
	free(p->out);
	ft_bzero(p, sizeof(t_flags));
}
