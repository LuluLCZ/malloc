/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:11:21 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/01 14:13:35 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>
#include <stdio.h>

int			get_type(size_t size) {
	size_t		content_size;
	size_t		page_size;

	page_size = getpagesize();
	content_size = size + FIELD_SIZE;
	printf("content_size in get_type in malloc %zu\n", content_size);
	printf("SMALL * page_size get_type in malloc %zu\n", SMALL * page_size);
	if (content_size > SMALL * page_size) {
		// TODO for a large size
		return TYPE_LARGE;
	} else if (content_size > TINY * page_size) return TYPE_SMALL;
	else return TYPE_TINY;
};

// Alloc "size" memory and return pointer to the allocated memory usgin mmap function
void    *ft_malloc(size_t size) {
	printf("--------------------------MALLOC-----------------------\n");

	t_field		*field;
	t_house		*house;
	t_house		*last_house;	
	int			type;

	// Protect your malloc if size if null
	if (size <= 0)
		return NULL;
	type = get_type(size);
	printf("TYPE AT THE BEGINING ---> %d\n", type);
	house = find_type_and_place_in_field(field, size, type);
	return (house + 1);
}
