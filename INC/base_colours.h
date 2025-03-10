/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_colours.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:06:19 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/14 14:32:31 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_COLOURS_H
# define BASE_COLOURS_H

/* basic */
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

/* custom */
# define CHARCOAL 0x36454F
# define GLAUCOUS 0x6082B6
# define PLATINUM 0xE5E4E2
# define NEONORANGE 0xFF5F1F
# define IRIS 0x5D3FD3

# include "types.h"

t_trgb	colour_sum(t_trgb colour1, t_trgb colour2);
t_trgb	colour_scalar_mult(t_trgb colour, int num);
t_trgb	colour_hadamard_product(t_trgb colour1, t_trgb colour2);
t_trgb	colour_subs(t_trgb colour1, t_trgb colour2);
t_trgb	colour(double red, double green, double blue);
void	t_trgb_to_addr(char *addr, t_trgb colour);
int		t_trgb_to_hex(t_trgb c);
char	*join_rgb_values(unsigned char r, unsigned char g, unsigned char b);
int		colour_to_int(t_trgb data);

#endif
