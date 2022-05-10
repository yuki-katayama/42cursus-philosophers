/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:58:16 by kyuki             #+#    #+#             */
/*   Updated: 2022/05/10 23:00:50 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_malloc_p(void **p, size_t len);
int		ft_nbrlen(long int nb);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
bool	ft_isdigitstr(char *str);
char	*ft_spaceskip(const char *str);

#endif
