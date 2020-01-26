/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 21:01:11 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/03 21:01:13 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		ft_get_str_len_u(uintmax_t n)
{
	intmax_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_utoa(uintmax_t n)
{
	char			*str;
	intmax_t		str_len;

	str_len = ft_get_str_len_u(n);
	if (!(str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	str[str_len] = '\0';
	while (str_len--)
	{
		str[str_len] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
