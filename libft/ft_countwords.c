/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:40 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/05 18:34:41 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(char const *str, char c)
{
	int word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			word_count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (word_count);
}
