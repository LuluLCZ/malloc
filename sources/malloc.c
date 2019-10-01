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

void    *ft_malloc(size_t size) {
	t_field		*field;
	t_house		*house;
	t_house		*last_house;	
	int			type;

	// Protect your malloc if size if null
	if (size <= 0)
		return NULL;
	type = size < TINY ? TYPE_TINY : TYPE_SMALL;
	house = find_type_and_place_in_field(field, size, type);
	return (house + 1);
	// Alloc "size" memory and return pointer to the allocated memory usgin mmap function
}
