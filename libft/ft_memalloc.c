/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:17:12 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/10/29 13:17:13 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
