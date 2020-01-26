/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:35:18 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/08 15:35:21 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char		*str;
	size_t		str_len;
	uintmax_t	num;

	str_len = ft_get_str_len(n);
	num = n;
	if (n < 0)
		num = n * -1;
	if (!(str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	str[str_len] = '\0';
	while (str_len--)
	{
		str[str_len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
