/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:55:10 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/12/09 17:55:13 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(uintmax_t n, uintmax_t base, int size)
{
	char			*out;
	char			*str1;
	char			*str2;
	uintmax_t		len;

	str1 = "0123456789ABCDEF";
	str2 = "0123456789abcdef";
	len = base_len(n, base);
	out = (char *)malloc(sizeof(char) * len + 1);
	out[len] = '\0';
	while (len--)
	{
		if (size == 1)
			out[len] = str1[n % base];
		else
			out[len] = str2[n % base];
		n /= base;
	}
	return (out);
}
