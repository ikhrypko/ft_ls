/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:24:29 by ikhrypko          #+#    #+#             */
/*   Updated: 2018/10/26 13:24:30 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					j;
	unsigned long int	i;
	unsigned long int	res;

	i = 0;
	res = 0;
	j = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (res >= 9223372036854775807 && j == 1)
			return (-1);
		else if (res > 9223372036854775807 && j == -1)
			return (0);
	}
	return (res * j);
}
