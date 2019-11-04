/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:44:18 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 17:00:18 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <unistd.h>

t_free				find_field_house_according_ptr(void *ptr, bool need_to_free) {
	t_field			*field;
	t_house			*house;
	t_free			result;


	// We need to find the house corresponding to the given ptr
	field = get_first_in_list();
	result.house = NULL;
	result.field = NULL;
	// printf("first field-> %p\n", field);
	while (field) {
		house = field->base;
		while (house != NULL) {
			// If the address of the pointer equals the house, return field and house
			if (ptr - HOUSE_SIZE == house) {
				// printf("FOUND: ptr->address %p \n", ptr - HOUSE_SIZE);
				if (need_to_free) {
					// printf("FOUND: house->address %p \n", house);
					house->free = 1;
				}
				result.field = field;
				result.house = house;
				return result;
			}
			// printf("house->address %p \n", (void *)house);
			// printf("ptr->address %p \n", ptr - HOUSE_SIZE);
			// printf("out");
			if (house && house->next) house = house->next;
			else break;
		}
		field = field->next;
	}
	return (result);
}

void				delete_the_field(t_field *field) {
	t_field			*new_linked;

	// Here we are checking if the field that we're gonna munmap is the first of the list
	new_linked = get_first_in_list();
	// If it is, we just unmap it we don't care
	if (new_linked == field) {
		if (!field->next) {
			new_linked = NULL;
			field->base = NULL;
			field = NULL;
		} else {
			new_linked = field->next;
			field->base = NULL;
		}
		return;
	}
	// If it's not, we need to link its previous field to the next field so we keep a linked list;
	while (new_linked && new_linked->next != field) new_linked = new_linked->next;
	if (new_linked->next == field) new_linked->next = field->next;
}

void				clean_field(t_field *field) {
	// ft_putstr("--------------------------CLEANING-------------------\n");
	size_t			house_counter;
	size_t			free_counter;
	t_house			*house;

	// We check how much house there is in the field, and how much of them are free. If all are free, we just munmap the page;
	free_counter = 0;
	house_counter = 0;
	if (!field || !field->base) {
		// printf("IOJWEOIJFOWEJFWJEFOIQWPFJWEOIFJQPWIEJFOIQFIOVQNOPFHQVIUNVIUQWVOINQUWNOVIUWNok");
		return;
	}
	else {
		house = field->base;
	}
	while (house) {
		if (house->free) free_counter++;
		house_counter++;
		house = house->next;
	}
	// printf("We found %zu free_house and there is %zu house in the field\n", free_counter, house_counter);
	if (house_counter == free_counter != 0) {
		// ft_putstr("+-----------------+\n|FREEING THE FIELD|\n+-----------------+\n");
		delete_the_field(field);
		// printf("freeing this field -> %p\n", field);
		// printf("|%zu|", sizeof(FIELD_SIZE));
		munmap(field + FIELD_SIZE, field->final_size + sizeof(FIELD_SIZE));
	}
}


void				free(void *ptr) {
	// fprintf(stderr, "trying to free %p\n", ptr);
	// ft_putstr("--------------------------FREE-----------------------\n");
	// t_field			*field;
	// t_house			*house;
	t_free			field_house;
	// int				type;

	// printf("ad")
	if (ptr == NULL) {
		// write(1, "ptr NULL\n", 10);
		return ;
	}
	else {
		field_house = find_field_house_according_ptr(ptr, true);
		if (field_house.field != NULL && field_house.house != NULL) {
			// write(1, "field and house found\n", 23);
			clean_field(field_house.field);
			// write(1, "--------------------------END1FREE-------------------\n", 55);
		} else {
			// write(1, "--------------------------END2FREE-------------------\n", 55);
			// fprintf(stderr, "trying to free %p\n", ptr);
			return ;
		}
	}
}
