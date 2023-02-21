/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:59:15 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/22 00:07:09 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_calloc(unsigned long count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
