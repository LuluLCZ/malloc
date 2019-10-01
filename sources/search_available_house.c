/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_available_house.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:12:40 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/01 15:35:58 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

t_house			*create_new_house(t_field *field, t_house *last_house, size_t size) {
	t_house		*new_house;

	new_house = mmap(NULL, size + HOUSE_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new_house == (void *)-1) {
		printf("wesh2");
		return NULL;
	}

	// We keep the track of the last house by updating it
	if (last_house) {
		last_house->next = new_house;
		// last_house = last_house->next;
		// last_house->next = NULL;
		// last_house->free = false;
		// last_house->size = size + 1;
	} else field->base = new_house;

	// We initialize the new house
	new_house->next = NULL;
	new_house->free = false;
	new_house->size = size;

	printf("hello %lu\n", size);

	// Ne pas oublier d'update la size remaining in the field if field type != large
	if (field->type != TYPE_LARGE) field->remain_size = field->remain_size - (size + HOUSE_SIZE);
	return (new_house);
};

t_house			*find_type_and_place_in_field(t_field *field, size_t size, int type) {
	t_house		*last_house;
	t_house		*new_house;
	t_field		*new_field;

	field = get_first_in_list();

	while (field && field->type != type && field->remain_size <= size + HOUSE_SIZE) field = field->next;

	// If we find a field with the same type and enough available place -> create block at the end of the list
	if (field) {
		last_house = get_last_house(field);
		new_house = create_new_house(field, last_house, size);
		printf("remain size on already existant field %lu\n", field->remain_size);
	} else { // Else we create a field corresponding to the size given
		new_field = create_new_field(size);
		new_house = create_new_house(new_field, NULL, size);
		printf("hello remain size if no field after first house creation %lu\n", new_field->remain_size);
		printf("hello size of first house %lu\n", new_house->size);
	}
	return (new_house);
};
