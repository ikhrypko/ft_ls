/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:31:04 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/08 15:31:35 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_len(char *format, t_flags *p, int i)
{
	if (format[i] == 'l' && format[i + 1] != 'l')
	{
		p->l = 1;
		return (++i);
	}
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		p->ll = 1;
		return (i += 2);
	}
	else if (format[i] == 'h' && format[i + 1] != 'h')
	{
		p->h = 1;
		return (++i);
	}
	else if (format[i] == 'h' && format[i + 1] == 'h')
	{
		p->hh = 1;
		return (i += 2);
	}
	return (i);
}

int		check_flags(char *format, t_flags *p, int i)
{
	while (format[++i] == ' ' || format[i] == '#' || format[i] == '+'
		|| format[i] == '-' || format[i] == '0')
	{
		format[i] == ' ' ? p->space = 1 : 0;
		format[i] == '#' ? p->sharp = 1 : 0;
		format[i] == '+' ? p->plus = 1 : 0;
		format[i] == '-' ? p->minus = 1 : 0;
		format[i] == '0' ? p->zero = 1 : 0;
	}
	return (i);
}

int		check_width(char *format, t_flags *p, int i, va_list args)
{
	if (ft_isdigit(format[i]))
	{
		p->wi = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			++i;
	}
	else if (format[i] == '*')
		i = width_star(p, args, i);
	if (format[i] == '.')
	{
		p->dot = 1;
		if (ft_isdigit(format[++i]))
		{
			p->pr = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				++i;
		}
		else if (format[i] == '*')
			i = precision_star(p, args, i);
	}
	return (i);
}

int		parsing(char *format, t_flags *p, va_list args, int i)
{
	i = check_flags(format, p, i);
	i = check_width(format, p, i, args);
	i = check_len(format, p, i);
	if (format[i] == 'z')
	{
		p->z = 1;
		i++;
	}
	else if (format[i] == 'j')
	{
		p->j = 1;
		i++;
	}
	else if (format[i] == 'L')
	{
		p->lll = 1;
		i++;
	}
	check_mod(format[i], p, args);
	if (format[i] == '\0')
		return (i);
	return (++i);
}

void	check_mod(char c, t_flags *p, va_list args)
{
	if (c == 'd' || c == 'i' || c == 'D')
		type_d(c, p, args);
	else if (c == 's' || c == 'S')
		type_s(p, args);
	else if (c == 'p')
		type_p(p, args);
	else if (c == 'c' || c == 'C' || c == '%')
		type_c(c, p, args);
	else if (c == 'x' || c == 'X')
	{
		p->reg = (c == 'x') ? 0 : 1;
		type_x(p, args);
	}
	else if (c == 'u' || c == 'U')
	{
		p->k = (c == 'U') ? 1 : 0;
		type_u(p, args);
	}
	else if (c == 'o' || c == 'O')
	{
		p->reg = (c == 'o') ? 0 : 1;
		type_o(c, p, args);
	}
	else if (c == 'f' || c == 'F')
		type_f(p, args);
}
