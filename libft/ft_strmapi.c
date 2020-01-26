/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:51:54 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/10/29 18:51:55 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	else
	{
		i = 0;
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		else
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	str[i] = '\0';
	return (str);
}
