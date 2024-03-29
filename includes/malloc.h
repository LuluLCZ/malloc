/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:19:44 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 16:39:18 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <sys/mman.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include <pthread.h>
# include <stddef.h>
# include <errno.h>
# include <unistd.h>

# define TYPE_TINY 0
# define TYPE_SMALL 1
# define TYPE_LARGE 2

# define TINY (512 * getpagesize())
# define SMALL (1024 * getpagesize())

# define HOUSE_SIZE sizeof(struct s_house)
# define FIELD_SIZE sizeof(struct s_field)

# define HOUSE_ADDRESS(house) ((void *)(char *)house + sizeof(t_house) + 1)
# define FIELD_ADDRESS(field) ((void *)(char *)field + sizeof(t_field) + 1)

# define multiple_4(x) ()

typedef struct		s_house
{
	struct s_house	*next;
	bool			free;
	size_t			size;
	char			pad[8];
}					t_house;

typedef struct		s_field
{
	int				type;
	size_t			remain_size;
	t_house			*base;
	size_t			final_size;
	struct s_field	*next;
	struct s_field	*prev;
}					t_field;


/*
The free structure is usefull when i'm looking for the house and the field,
it contains the field and the house where the ptr to free is located
*/
typedef struct		s_free
{
	t_field			*field;
	t_house			*house;
}					t_free;


/*
Functions to implement
*/

void				*malloc(size_t size);
void				free(void *ptr);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t count, size_t size);


/*
create_new_field.c
*/

size_t				get_proper_size(size_t size, int *type, size_t *space_left);
t_field				*create_new_field(size_t size);


/*
get_set_base_last.c
*/

t_field				**first_in_list();
t_field				*get_first_in_list();
void				set_field_base(void *new_base);
t_field				*get_last_field();
void				link_fields();
t_house				*get_last_house(t_field *field);

/*
search_available_house.c
*/

t_house				*create_new_house(t_field *field, t_house *last_house, size_t size);
t_house				*find_type_and_place_in_field(t_field *field, size_t size, int type);

/*
free.c
*/
t_free				find_field_house_according_ptr(void *ptr, bool need_to_free);

/*
realloc.c
*/
void				*reallocf(void *ptr, size_t size);



/*
show_alloc_mem.c
*/
void				show_alloc_mem();


#endif