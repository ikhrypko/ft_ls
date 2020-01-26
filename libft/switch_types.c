/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:32:50 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/08 15:32:51 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_switch_types_s(t_flags *p, va_list args)
{
	if (p->l)
		return (va_arg(args, long));
	else if (p->ll)
		return (va_arg(args, long long));
	else if (p->z)
		return (va_arg(args, ssize_t));
	else if (p->j)
		return (va_arg(args, intmax_t));
	else if (p->h)
		return ((short)va_arg(args, int));
	else if (p->hh)
		return ((char)va_arg(args, int));
	return (va_arg(args, int));
}

uintmax_t	ft_switch_types_us(t_flags *p, va_list args)
{
	if (p->l)
		return (va_arg(args, unsigned long));
	else if (p->ll)
		return (va_arg(args, unsigned long long));
	else if (p->z)
		return (va_arg(args, size_t));
	else if (p->j)
		return (va_arg(args, uintmax_t));
	else if (p->h)
		return ((unsigned short)va_arg(args, unsigned int));
	else if (p->hh)
		return ((unsigned char)va_arg(args, unsigned int));
	return (va_arg(args, unsigned int));
}

void		write_buff(char c)
{
	if (g_buf.i + 1 == BUFF_SIZE)
	{
		write(1, g_buf.buf, g_buf.i);
		g_buf.wr_size += g_buf.i;
		g_buf.i = 0;
	}
	g_buf.buf[g_buf.i++] = c;
}

int			width_star(t_flags *p, va_list args, int i)
{
	p->wi = va_arg(args, intmax_t);
	return (++i);
}

int			precision_star(t_flags *p, va_list args, int i)
{
	p->pr = va_arg(args, intmax_t);
	return (++i);
}
