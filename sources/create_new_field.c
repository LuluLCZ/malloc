/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:24:47 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 17:03:16 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>


size_t			get_proper_size(size_t size, int *type, size_t *space_left) {
	size_t		content_size;
	size_t		page_size;
	size_t		final_size;

	// Type : (page_size given by getpagesize() generally equals to 4kB - 4096)
	// Tiny = 500 * page_size | Small = 1000 * page_size 

	// printf("page_size equals -> %lu\n", page_size);
	content_size = size + FIELD_SIZE;
	// printf("content_size -> %lu\n", content_size);
	// printf("content_size %zu | round tiny /100 %f | round small / 100 %f\n", content_size, round(TINY/100), round(SMALL/100));
	if (content_size > round(TINY / 100) && content_size <= round(SMALL / 100)) {
		// For a SMALL allocation we got the infos ->
		final_size = SMALL;
		*type = TYPE_SMALL;
		*space_left = final_size - FIELD_SIZE;
		// printf("field is SMALL\n");
	} else if (content_size <= round(TINY / 100)) {
		// For a TINY allocation we got the infos -->
		final_size = TINY;
		*type = TYPE_TINY;
		*space_left = final_size - FIELD_SIZE;
		// printf("field is tiny\n");
	} else {
		final_size = size + FIELD_SIZE + HOUSE_SIZE;
		*type = TYPE_LARGE;
		*space_left = 0;
		// printf("field is large\n");
	}
	
	return (final_size);
};

t_field			*create_new_field(size_t size) {
	t_field		*field;
	int			type;
	size_t		space_left;
	size_t		final_size;

	final_size = get_proper_size(size, &type, &space_left);
	field = mmap(0, final_size + FIELD_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (field == (void *)-1) {
		printf("wesh1");
		return NULL;
	}
	field->base = NULL;
	field->remain_size = space_left;
	field->type = type;
	field->final_size = final_size;
	link_fields(field);
	field->next = NULL;
	return (field);
};