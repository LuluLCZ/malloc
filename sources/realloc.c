/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:25:16 by mama              #+#    #+#             */
/*   Updated: 2019/10/09 17:51:50 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <unistd.h>

// The realloc() function changes the size of the memory block pointed to by ptr to size bytes.
// The contents will be unchanged in the range from the start of the region up to the minimum of the old and new sizes.



void				*ft_realloc(void *ptr, size_t size) {
	t_free			field_house;
	void			*new_ptr;
	// If ptr == null just return malloc(size)
	if (!ptr) return (ft_malloc(size));

	// If size = 0 -> free the pointer
	if (size == 0) ft_free(ptr);

	// We need to find the house provided to free it and allocate it again
	field_house = find_field_house_according_ptr(ptr, false);
	if (!field_house.field || !field_house.house) return NULL;
	else {
		if (field_house.house->free) return NULL;
		else {
			if (field_house.house->size == size) return (ptr);
			field_house.house->free = true;
			new_ptr = ft_malloc(size);
			ft_memcpy(new_ptr, ptr, field_house.house->size > size ? size : field_house.house->size);
			ft_free(ptr);
			return (new_ptr);
		}
	}
	return (NULL);
}
