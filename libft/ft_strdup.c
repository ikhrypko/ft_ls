/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:15:36 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/10/25 16:39:22 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
