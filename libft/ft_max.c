/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:23 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/11/07 15:15:24 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *tab, size_t len)
{
	int		i;
	int		max_value;

	if (!tab && !len)
		return (0);
	max_value = tab[0];
	i = 0;
	while (len--)
	{
		if (tab[i] > max_value)
			max_value = tab[i];
		i++;
	}
	return (max_value);
}
