/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:19:21 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/04 13:19:22 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(char const *str, char c)
{
	int	i;
	int	word_len;

	i = 0;
	word_len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		word_len++;
	}
	return (word_len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s || !(str = (char **)malloc(sizeof(char *)
		* (ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew((ft_word_len(&s[j], c)))))
			return (NULL);
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
