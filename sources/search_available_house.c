/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_available_house.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mama <mama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:12:40 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/07 16:49:21 by mama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

t_house			*search_room_for_house(size_t size, int type) {
	t_field		*field;
	t_house		*house;

	field = get_first_in_list();
	while (field) {
		if (field->type == type) {
			house = field->base;
			if (!house) return NULL;
			while (house) {
				if (house->free == true && house->size >= size) {
					house->free = false;
					return house;
				}
				house = house->next;
			}
		}
		field = field->next;
	}
	return (NULL);
}

t_house			*create_new_house(t_field *field, t_house *last_house, size_t size) {
	t_house		*new_house;
	t_field		*new_field;

	// If there is no more place available for the asked size, then let's create a new field giving them the size asked
	if (field->remain_size <= size + HOUSE_SIZE) {
		printf("NOT GOOD -> create_new_house but no space should never happen\n");
	}

	new_house = mmap(NULL, size + HOUSE_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new_house == (void *)-1) {
		printf("wesh2");
		return NULL;
	}

	// We keep the track of the last house by updating it
	if (last_house) {
		last_house->next = new_house;
	} else {
		field->base = new_house;
		printf("In this case, the last house doesn't exisits\n");
	}

	// We initialize the new house
	new_house->next = NULL;
	new_house->free = false;
	new_house->size = size;
	new_house->address = new_house + sizeof(HOUSE_SIZE);

	// Do not forget to update the size remaining in the field if field type != large
	if (field->type != TYPE_LARGE) field->remain_size = field->remain_size - (size + HOUSE_SIZE);
	return (new_house);
};

t_house			*find_type_and_place_in_field(t_field *field, size_t size, int type) {
	t_house		*last_house;
	t_house		*new_house;
	t_field		*new_field;

	field = get_first_in_list();

	// We first check if there is a field with a free house available for this new malloc;
	new_house = search_room_for_house(size, type);
	if (new_house) {
		printf("We found some place for the house to be allocated\n");
		return (new_house);
	}

	while (field && field->type != type && field->remain_size <= size + HOUSE_SIZE) field = field->next;

	// If we find a field with the same type and enough available place -> create block at the end of the list
	// If there is no room for the house, do as if you had no field
	printf("the size + HOUSE_SIZE we need to be available in the field we're gonna place the house of that size %zu\n", size + HOUSE_SIZE);
	if (field) {
		printf("if we found a field ready to accept the house of that size field->remain_size%zu\n", field->remain_size);
		printf("type 1 is tiny 2 is small -> %d\n", field->type);
	}
	
	if (field && field->remain_size > (size + HOUSE_SIZE)) {
		last_house = get_last_house(field);
		new_house = create_new_house(field, last_house, size);
		printf("remain size on already existant field before returning ptr of the house to malloc %lu\n", field->remain_size);
	} else { // Else we create a field corresponding to the size given
		new_field = create_new_field(size);
		new_house = create_new_house(new_field, NULL, size);
		printf("remain size of new field before returning ptr of the house to malloc %lu\n", new_field->remain_size);
		printf("size of first house of the field we just created before returning ptr of the house to malloc %lu\n", new_house->size);
	}
	return (new_house);
};
