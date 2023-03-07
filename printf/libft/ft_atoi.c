/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:36:59 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/07 15:49:36 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

static long long	calcul(const char *str, int i, int k)
{	
	long long	res;

	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (k == 1)
		res = -res;
	return (res);
}

long long	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k++;
		if (str[i] == '+')
			j++;
		i++;
	}
	if (j > 1 || k > 1 || (k + j) > 1)
		return (0);
	return (calcul(str, i, k));
}

//int main(void)
//{
//	char tab[] = "     2147483657";
//
//	printf("%d\n", ft_atoi(tab));
//	printf("%d", atoi(tab));
//}
