/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:16:08 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/10/31 22:16:10 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ft_strncpy(ret, &s[start], len);
	ret[len] = '\0';
	return (ret);
}
