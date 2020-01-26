/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:15:30 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/01 17:15:35 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	char	*res;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (!(tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	res = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (res);
}
