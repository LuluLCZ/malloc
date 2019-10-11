/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <llacaze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:20:38 by llacaze           #+#    #+#             */
/*   Updated: 2019/10/11 13:40:03 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

extern void write_char(char);

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void print_address_hex(void* p0) {
    int i;
    uintptr_t p = (uintptr_t)p0;

    ft_putchar('0'); ft_putchar('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
        ft_putchar(hex_digit((p >> i) & 0xf));
    }
}

void			show_alloc_mem() {
	t_field		*field;
	t_house		*house;
	int		tmp_prev;
	int		type;
	int		tmp;
	int		i;

	i = 0;
	type = -1;
	tmp = 0;
	// tmp2= 0;
	field = get_first_in_list();
	// printf("%--zu--", field->base->size);
	while (field) {
		if (!field->base) return ;
		tmp_prev = type;
		type = field->type;
		house = field->base;
		// if (tmp_prev == -1 || tmp_prev != type) {
			if (field->type == TYPE_TINY) ft_putstr("TINY :");
			else field->type == TYPE_SMALL ? ft_putstr("SMALL :") : ft_putstr("LARGE :");
			print_address_hex(field);
			ft_putstr("\n");
		// }
		// getchar();
		// printf(" -> show alloc mem  field| printf : %p\n", field->base);
			i++;
		while (house) {
			print_address_hex(house);
			ft_putstr(" - ");
			print_address_hex(house + house->size);
			ft_putstr(" : ");
			ft_putnbr(house->size);
			ft_putstr(" octets\n");
			tmp = tmp + house->size;
			// if (house->free) ft_putstr("non-occupated\n");
			// else ft_putstr("occupated");
			// printf("%p\n", house);
			house = house->next;
		}
		// tmp2 = tmp;
		field = field->next;
	}
	ft_putstr("TOTAL: ");
	ft_putnbr(tmp);
	ft_putstr(" octets\n");
	ft_putnbr(i);
}