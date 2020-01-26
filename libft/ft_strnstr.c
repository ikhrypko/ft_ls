/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:54:31 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/01 16:54:33 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)(haystack + i - j));
	return (NULL);
}
