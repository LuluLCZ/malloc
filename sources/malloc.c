/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:11:21 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 17:02:59 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int			get_type(size_t size) {
	size_t		content_size;

	content_size = size + FIELD_SIZE;
	// printf("content_size in get_type in malloc %zu\n", content_size);
	// printf("SMALL * page_size get_type in malloc %zu\n", SMALL * page_size);
	if (content_size > round(SMALL/100)) {
		return TYPE_LARGE;
	} else if (content_size > round(TINY/100)) return TYPE_SMALL;
	else return TYPE_TINY;
};

// Alloc "size" memory and return pointer to the allocated memory usgin mmap function
void    *malloc(size_t size) {
	ft_putstr("---------------------MALLOC---------------------\n");
	t_field		*field;
	t_house		*house;
	t_house		*last_house;	
	int			type;

	// Protect your malloc if size if null
	if (size <= 0) {
		write(1, "o", 1);
		return NULL;
	}
	// size = multiple_4(size);
	ft_putnbr(size);
	ft_putchar('|');
	// fprintf(stdout, "\n%zu\n", size);
	type = get_type(size);
	ft_putnbr(type);
	// printf("TYPE AT THE BEGINING ---> %d\n", type);
	house = find_type_and_place_in_field(field, size, type);
	// printf("returning %p\n", house);

	fprintf(stderr, "address returned by malloc %p\n", house);
	ft_putstr("-----------------END MALLOC---------------------\n");
	return (house + 1);
}
