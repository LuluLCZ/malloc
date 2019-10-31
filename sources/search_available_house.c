/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_available_house.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:12:40 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 15:54:51 by llacaze          ###   ########.fr       */
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


	// If there is no more place available for the asked size, then let's create a new field giving them the size asked
	if (field && field->remain_size <= size + HOUSE_SIZE && field->type != TYPE_LARGE) {
		printf("NOT GOOD -> create_new_house but no space should never happen\n");
	}

	// new_house = mmap(NULL, size + HOUSE_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	// if (new_house == (void *)-1) {
	// 	// printf("wesh2");
	// 	return NULL;
	// }
	if (last_house != NULL) {
		new_house = (t_house *)(((void *)last_house + HOUSE_SIZE) + last_house->size);
		// new_house += 16 - ((uintptr_t)new_house % 16);
		// new_house += sizeof(t_house) % 16;
	} else {
		new_house = (t_house *)(((void *)field + FIELD_SIZE));
		new_house += 16 - ((uintptr_t)new_house % 16);
	}

	// We initialize the new house
	new_house->next = NULL;
	new_house->free = false;
	new_house->size = size;

	// We keep the track of the last house by updating it
	if (last_house) {
		last_house->next = new_house;
		// new_house->address = last_house->address + HOUSE_SIZE;
	} else {
		field->base = new_house;
		// new_house->address = (void *)field + FIELD_SIZE;
	}

	// Do not forget to update the size remaining in the field if field type != large
	if (field->type != TYPE_LARGE) {
		field->remain_size = field->remain_size - (size + HOUSE_SIZE);
		// printf("field remain %zu", field->remain_size);
	}
	return (new_house);
};

t_field			*find_field_according_to_size_type(t_field *field, size_t size, int type) {
	field = get_first_in_list();
	while (field) {
		// printf("%zu -> size\n%zu -> field remain size\n%zu -> size + HOUSE_SIZE\n%p field addr\n%d -> field type == %d type", size, field->remain_size, size + HOUSE_SIZE, field, field->type, type);
		if (field->type == type && field->remain_size > size + HOUSE_SIZE) break;
		field = field->next;
	}
	if (!field) return NULL;
	return field;
}

t_house			*find_type_and_place_in_field(t_field *field, size_t size, int type) {
	t_house		*last_house;
	t_house		*new_house;
	// t_field		*new_field;

	field = get_first_in_list();

	// We first check if there is a field with a free house available for this new malloc;
	// printf("remain size on already existant field before returning ptr of the house to malloc\n");
	if (field && field->type != TYPE_LARGE && (new_house = search_room_for_house(size, type))) {
		return (new_house);
	}

	 
	field = find_field_according_to_size_type(field, size, type);
	// If we find a field with the same type and enough available place -> create block at the end of the list
	// If there is no room for the house, do as if you had no field
	// printf("%p: FIELD\n", field);
	if ((field && field->remain_size >= (size + HOUSE_SIZE) && field->type == type) || (field && field->type != TYPE_LARGE)) {
		last_house = get_last_house(field);
		new_house = create_new_house(field, last_house, size);
		// ft_putstr("not creating new field\n");
		// printf("into field-> %p\n", field);
		// printf("old field %zu\n", field->remain_size);
		// printf("remain size on already existant field before returning ptr of the house to malloc %lu\n", field->remain_size);
	} else { // Else we create a field corresponding to the size given
		// ft_putstr("creating new field\n");
		field = create_new_field(size);
		if (field == NULL) return NULL;
		new_house = create_new_house(field, NULL, size);
		// printf("into field-> %p\n", new_field);
		// if (field) printf("new field %zu\n", field->remain_size);
		// printf("FIELD TYPE : %d | HOUSE SIZE %zu", new_field->type, new_house->size);
		// printf("remain size of new field before returning ptr of the house to malloc %lu\n", new_field->remain_size);
		// printf("size of first house of the field we just created before returning ptr of the house to malloc %lu\n", new_house->size);
	}
	return (new_house);
};
