/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:28:08 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/01 16:28:09 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
	size_t dstsize)
{
	size_t i;
	size_t dstlen;
	size_t srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen)
		return (dstsize + srclen);
	while (src[i] != '\0' && (dstlen + i + 1) < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
