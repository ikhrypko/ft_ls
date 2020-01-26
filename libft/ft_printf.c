/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:29:51 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/08 15:29:53 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			args;
	t_flags			p;
	int				i;

	i = 0;
	ft_bzero(&g_buf, sizeof(g_buf));
	ft_bzero(&p, sizeof(t_flags));
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = parsing((char *)format, &p, args, i);
		else
			write_buff(format[i++]);
	}
	va_end(args);
	g_buf.i ? write(1, g_buf.buf, g_buf.i) : false;
	g_buf.wr_size += g_buf.i;
	return (g_buf.wr_size);
}
