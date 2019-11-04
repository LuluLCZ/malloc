/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:25:11 by mama              #+#    #+#             */
/*   Updated: 2019/10/10 17:50:00 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

extern pthread_mutex_t	g_mut;
/*
 * The calloc() function allocates memory for an array of count elements of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If count or size is 0, then calloc() returns either NULL,
 * or a unique pointer value that can later be successfully passed to free().
*/

void				*calloc(size_t count, size_t size) {
	// ft_putstr("-----------CALLOCATION-------------\n");
	void			*house;
	house = NULL;
	// First we need to malloc the right size which is the product of the two operands
	// ft_putnbr(size * count);
	house = malloc(size * count);
	if (house != NULL) {
		// Then we need to put 0 on any byte of the bloc 
		pthread_mutex_lock(&g_mut);
		ft_memset(house, 0, size * count);
		pthread_mutex_unlock(&g_mut);
		// printf("%p -> house\n", house);
		// ft_putstr("-----------END1CALLOCATION-------------\n");
		return (house);
	}
	// ft_putstr("-----------END2CALLOCATION-------------\n");
	return ((void *)0xdeadbeef);
}