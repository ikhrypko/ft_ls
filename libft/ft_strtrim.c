/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:02:50 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/01 18:02:51 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	str_len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	str_len = ft_strlen(s);
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	while (s[str_len - 1] && ft_iswhitespace(s[str_len - 1]))
		str_len--;
	if (s[i] == '\0')
	{
		str = ft_strsub(s, 0, 0);
		return (str);
	}
	str = ft_strsub(s, i, str_len - i);
	return (str);
}
