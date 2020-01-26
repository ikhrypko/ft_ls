/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:55:18 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/07 14:57:23 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*whole_part(int a, long double f)
{
	char		*tmp;
	char		*str;

	f = (f < 0) ? -f : f;
	tmp = ft_utoa(f);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (a + 1000))))
		return (NULL);
	str = ft_strcat(str, tmp);
	free(tmp);
	str = ft_strcat(str, ".");
	return (str);
}

char	*round_f(char *str)
{
	int		l;
	char	*tmp;

	l = ft_strlen(str) - 1;
	if (str[l] > '4')
		l -= (str[l - 1] == '.') ? 2 : 1;
	str[l]++;
	while (l > -1 && str[l] > '9')
	{
		str[l] = '0';
		if (str[l - 1] == '.')
			l--;
		str[l - 1]++;
		l--;
	}
	if (l == -1)
	{
		tmp = str;
		str = ft_strjoin("1", str);
		free(tmp);
	}
	return (str);
}

int		l_case(char *str)
{
	if (ft_strcmp(str, MIN_STR) == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*ft_ftoa(t_flags *p, long double f)
{
	char		*str;
	char		*tmp;
	uintmax_t	n;
	int			a;

	f < 0 ? f = f * -1 : false;
	a = p->pr;
	p->dot ? a++ : (a = 7);
	str = whole_part(a, f);
	if (l_case(str) == 1)
		return (ft_strdup("0.0000000"));
	f = f - (uintmax_t)f;
	n = 0;
	while (a--)
	{
		f -= n;
		n = f *= 10;
		tmp = ft_utoa(n);
		str = ft_strcat(str, tmp);
		free(tmp);
	}
	str = round_f(str);
	return (str);
}
