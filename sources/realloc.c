/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:25:16 by mama              #+#    #+#             */
/*   Updated: 2019/10/10 17:49:49 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <unistd.h>

// The realloc() function changes the size of the memory block pointed to by ptr to size bytes.
// The contents will be unchanged in the range from the start of the region up to the minimum of the old and new sizes.



void				*realloc(void *ptr, size_t size) {
	ft_putstr("-----------REALLOC-------------\n");
	t_free			field_house;
	void			*new_ptr;
	// If ptr == null just return malloc(size)
	if (!ptr) return (malloc(size));

	// If size = 0 -> free the pointer
	if (size == 0) free(ptr);

	// We need to find the house provided to free it and allocate it again
	field_house = find_field_house_according_ptr(ptr, false);
	if (!field_house.field || !field_house.house) return NULL;
	else {
		if (field_house.house->free) return NULL;
		else {
			if (field_house.house->size == size) return (ptr);
			field_house.house->free = true;
			if ((new_ptr = malloc(size)) == NULL) return NULL;
			ft_memcpy(new_ptr, ptr, field_house.house->size > size ? size : field_house.house->size);
			free(ptr);
			ft_putstr("-----------END1REALLOC-------------\n");
			return (new_ptr);
		}
	}
	ft_putstr("-----------END2REALLOC-------------\n");
	return (NULL);
}

void				*reallocf(void *ptr, size_t size) {
	ft_putstr("-----------REALLOCF-------------\n");
	t_free			field_house;
	void			*new_ptr;
	// If ptr == null just return malloc(size)
	if (!ptr) return (malloc(size));

	// If size = 0 -> free the pointer
	if (size == 0) free(ptr);

	// We need to find the house provided to free it and allocate it again
	field_house = find_field_house_according_ptr(ptr, false);
	if (!field_house.field || !field_house.house) {
		free(ptr);
		ft_putstr("-----------END1REALwLOeCF-------------\n");
		return (void *)0xdeadffbf;
	}
	else {
		if (field_house.house->free) {
			free(ptr);
			ft_putstr("-----------END1REALLOeCF-------------\n");
			return (void *)0xdeadccbf;
		}
		else {
			if (field_house.house->size == size) return (ptr);
			field_house.house->free = true;
			if ((new_ptr = malloc(size)) == NULL) return NULL;
			ft_memcpy(new_ptr, ptr, field_house.house->size > size ? size : field_house.house->size);
			free(ptr);
			ft_putstr("-----------END1REALLOCF-------------\n");
			return (new_ptr);
		}
	}
	free(ptr);
	ft_putstr("-----------END2REALLOCF-------------\n");
	return (void *)0xdeadbf;
}

