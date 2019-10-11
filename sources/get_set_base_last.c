/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_base_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:41:57 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 12:48:59 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*base = NULL;

t_field				**first_in_list() {
	static t_field	*field = NULL;

	return (&field);
}

t_field		*get_first_in_list() {
	return (*first_in_list());
}

void		set_field_base(void *new_base) {
	base = new_base;
}

t_field		*get_last_field() {
	t_field	*last;

	// Get the first base
	last = get_first_in_list();

	// While there is a field and a next one go to the next and check
	while (last && last->next && last->next) last = last->next;
	return (last);
}

t_house		*get_last_house(t_field *field) {
	t_house		*last_house;

	last_house = field->base;
	while (last_house && last_house->next != NULL) last_house = last_house->next;
	return (last_house);
}

void		link_fields(t_field *field) {
	t_field	*last;

	if (get_first_in_list() == NULL) *first_in_list() = field;
	else {
		last = get_first_in_list();
		while (last && last->next) last = last->next;
		last->next = field;
	}
	// if (last) last->next = field;
	// else set_field_base(field);
}
