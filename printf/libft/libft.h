/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:35:55 by mmorue            #+#    #+#             */
/*   Updated: 2023/03/13 14:49:01 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

long long		ft_atoi(const char *str);
char			*ft_strdup(char *src);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
char			**ft_split(char const *str, char c);
#endif