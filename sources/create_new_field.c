/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:24:47 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/01 15:21:00 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>
#include <stdio.h>


size_t			get_proper_size(size_t size, int *type, size_t *space_left) {
	size_t		content_size;
	size_t		page_size;
	size_t		final_size;

	page_size = getpagesize();
	printf("page_size equals -> %lu\n", page_size);
	content_size = size + FIELD_SIZE;
	printf("content_size -> %lu\n", content_size);
	// if (content_size > SMALL * page_size) {
	// 	// TODO for a large size
	// } else 
	if (content_size > TINY * page_size) {
		// For a SMALL allocation we got the infos ->
		final_size = SMALL * page_size;
		*type = TYPE_SMALL;
		*space_left = final_size - FIELD_SIZE;
		printf("field is SMALL\n");
	} else {
		// For a TINY allocation we got the infos -->
		final_size = TINY * page_size;
		*type = TYPE_TINY;
		*space_left = final_size - FIELD_SIZE;
		printf("field is tiny\n");
	}
	
	return (final_size);
};

t_field			*create_new_field(size_t size) {
	t_field		*field;
	int			type;
	size_t		space_left;
	size_t		final_size;

	final_size = get_proper_size(size, &type, &space_left);
	printf("new field final size%lu\n", final_size);
	printf("new field space left%lu\n", space_left);
	field = mmap(0, final_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (field == (void *)-1) {
		printf("wesh1");
		return NULL;
	}
	field->base = NULL;
	field->remain_size = space_left;
	field->type = type;
	field->next = NULL;
	link_fields(field);
	return (field);
};