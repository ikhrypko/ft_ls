/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:54:44 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/06 20:54:45 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
