/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mama <mama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:44:18 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/02 17:15:46 by mama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

t_house				*house_according_ptr(void *ptr) {
	t_house			*house;

	house = (t_house *)(ptr - HOUSE_SIZE);
	if (house) {
		printf("House found ->%zu\n", house->size);
		return (house);
	}
	else {
		printf("house not found\n");
		return NULL;
	}
}

t_field				*field_according_house(t_house *house) {
	t_field			*field;
	t_house			*tmp;

	field = get_first_in_list();
	while (field) {
		if (field->base == house) {
			printf("Field found \n");
			return (field);
		}
		tmp = field->base;
		if (!tmp) {
			printf("Problem with field base\n");
		}
		while (tmp && tmp != house) {
			tmp = tmp->next;
		}
		if (tmp == house) {
			printf("Field found \n");
			return (field);
		}
		field = field->next;
	}
	printf("Field not found \n");
	return (NULL);
}

t_free				find_field_house_according_ptr(void *ptr) {
	t_field			*field;
	t_house			*house;
	t_free			result;

	// We need to find the house corresponding to the given ptr
	field = get_first_in_list();
	while (field) {
		house = field->base;
		printf("house->size %zu\n", house->size);
		while (house) {
			if ((void *)(house + 1) == ptr) {
				result.field = field;
				result.house = house;
				return result;
			}

			house = house->next;
		}
		printf("-walah ca marche pas\n");
		field = field->next;
	}
	return (result);
}

void				delete_the_field(t_field *field) {
	t_field			*new_linked;

	// Here we are checking if the field that we're gonna munmap is the first of the list
	new_linked = get_first_in_list();
	// If it is, we just unmap it we don't care
	if (new_linked == field) return;
	// If it's not, we need to link its previous field to the next field so we keep a linked list;
	while (new_linked && new_linked->next != field) new_linked = new_linked->next;
	if (new_linked->next == field) new_linked->next = field->next;
}

void				clean_field(t_field *field) {
	size_t			house_counter;
	size_t			free_counter;
	t_house			*house;

	printf("ok");
	// We check how much house there is in the field, and how much of them are free. If all are free, we just munmap the page;
	free_counter = 0;
	house_counter = 0;
	// field = get_first_in_list();
	if (field->base) {
		printf("OK");
		house = field->base;
	}
	else return ;
	// printf("house state : %d\n", house->free);
	if (house) {
		while (house) {
			printf("CLEANING: counter is house_counter: %zu | free_counter: %zu\n", house_counter, free_counter);
			if (house->free == true) free_counter++;
			house_counter++;
			house = house->next;
		}
		printf("We found %zu free_house and there is %zu house in the field\n", free_counter, house_counter);
		if (house_counter == free_counter != 0) {
			printf("FREEING THE FIELD\n");
			delete_the_field(field);
			munmap((void *)(field + 1), sizeof(field) + FIELD_SIZE);
		}
	}
}

void				ft_free(void *ptr) {
	printf("--------------------------FREE-----------------------\n");
	t_field			*field;
	t_house			*house;
	t_free			field_house;
	int				type;

	if (!ptr) return ;
	// field_house = find_field_house_according_ptr(ptr);
	house = house_according_ptr(ptr);
	if (house) field = field_according_house(house);
	// HERE PROBLEM THE HOUSE WE JUST GET IS NULLLLLL
	if (field && house->free == false) {
		printf("Field found, checking if we need to delete the page\n");
	}
	house->free = true;
	// clean_field(field);
}
