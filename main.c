/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:30:29 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/01/11 21:30:56 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int		i;
	t_ls	l;

	ft_bzero(&l, sizeof(t_ls));
	ft_bzero(&g_k, sizeof(t_keys));
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (av[i][0] == '-' && av[i][1])
				parse_flags(av[i++]);
			else
				break ;
		}
	}
	parse_args(av, ac, i, &l);
	return (0);
}
