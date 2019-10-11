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

/*
 * The calloc() function allocates memory for an array of count elements of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If count or size is 0, then calloc() returns either NULL,
 * or a unique pointer value that can later be successfully passed to free().
*/

void				*calloc(size_t count, size_t size) {
	void			*house;

	if (count == 0 || size == 0) return NULL;
	// First we need to malloc the right size which is the product of the two operands
	house = malloc(size * count);
	// Then we need to put 0 on any byte of the bloc 
	if (house) {
		ft_bzero(house, size * count);
		return (house);
	}
	return (NULL);
}