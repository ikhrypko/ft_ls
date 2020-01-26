/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:41:31 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/10 18:41:56 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	base_len(uintmax_t n, uintmax_t base)
{
	uintmax_t		count;

	count = 0;
	while (n /= base)
		++count;
	return (++count);
}
