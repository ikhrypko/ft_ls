/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 14:56:42 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/01 14:56:43 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_width(t_flags *p)
{
	if (p->wi && !p->dot && !p->pr && !p->minus)
	{
		if (p->wi > p->size && !p->pr)
			p->get_wi = p->wi - p->size;
		while (p->wi && p->get_wi--)
			write_buff(' ');
	}
	else if (p->wi && p->dot && !p->minus)
	{
		if (p->wi && p->wi > p->pr && p->pr <= p->size)
			p->get_wi = p->wi - p->pr;
		if (p->wi && p->wi >= p->pr && p->pr > p->size)
			p->get_wi = p->wi - p->size;
		if (p->wi && p->wi < p->pr && p->pr > p->size)
			p->get_wi = p->wi - p->size;
		while (p->wi && p->get_wi--)
			write_buff(' ');
	}
}

void	type_s(t_flags *p, va_list args)
{
	p->out = va_arg(args, char *);
	if (p->out == NULL)
	{
		p->out = NULL_STR;
		p->size = 6;
	}
	p->size = ft_strlen(p->out);
	p->minus && p->wi && p->wi > p->size ? p->tmp_min = p->wi - p->size : false;
	p->dot && p->size > p->pr ? p->size = p->pr : p->size;
	if ((p->wi && !p->minus) || (p->dot && !p->minus))
		s_width(p);
	if (p->minus && p->wi && p->dot && p->wi > p->size)
		p->tmp_min = (p->pr > p->size) ? p->wi - p->size : p->wi - p->pr;
	while (p->size--)
		write_buff(p->out[p->index++]);
	if (p->minus && p->wi && p->wi > p->size)
		while (p->tmp_min--)
			write_buff(' ');
	ft_bzero(p, sizeof(t_flags));
}

void	type_c(char c, t_flags *p, va_list args)
{
	char	qw;

	qw = (c == '%' ? '%' : va_arg(args, int));
	if (p->wi && !p->minus)
		p->get_wi = p->wi - 1;
	while (p->wi && !p->zero && p->get_wi--)
		write_buff(' ');
	while (p->wi && p->zero && p->get_wi--)
		write_buff('0');
	p->minus && p->wi ? p->tmp_min = p->wi - 1 : false;
	write_buff(qw);
	if (p->minus && p->wi)
		while (p->tmp_min--)
			write_buff(' ');
	ft_bzero(p, sizeof(t_flags));
}

void	take_p(t_flags *p, uintmax_t val)
{
	val == 0 && p->dot ? p->size = 0 : false;
	if (p->wi && !p->minus && p->wi > (p->size + 2))
	{
		p->wi > p->pr ? p->get_wi = p->wi - (p->size + 2) : false;
		if (p->wi && p->pr && p->wi > p->pr && p->pr > p->size)
			p->get_wi = ((p->wi - p->pr - 2) > 0) ? p->wi - p->pr - 2 : false;
	}
	while (p->wi && p->get_wi--)
		write_buff(' ');
	write_buff('0');
	write_buff('x');
}

void	type_p(t_flags *p, va_list args)
{
	uintmax_t	val;

	val = va_arg(args, unsigned long int);
	p->out = ft_itoa_base(val, 16, 0);
	p->size = (ft_strlen(p->out));
	take_p(p, val);
	if (p->minus && p->wi && p->pr > p->size && p->wi > p->pr)
		p->tmp_min = ((p->wi - p->pr - 2) > 0) ? p->wi - p->pr - 2 : false;
	else if (p->minus && (p->wi || p->dot) && p->wi > p->pr)
		p->tmp_min = (p->wi - p->size - 2 > 0) ? p->wi - p->size - 2 : 0;
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
