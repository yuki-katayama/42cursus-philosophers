/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:58:16 by kyuki             #+#    #+#             */
/*   Updated: 2021/08/07 19:58:17 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_malloc_p(void **p, size_t len);
int		ft_nbrlen(long int nb);
size_t	ft_strlen(const char *s);

#endif
