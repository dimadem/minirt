/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:37:12 by dmdemirk          #+#    #+#             */
/*   Updated: 2025/01/18 16:13:31 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "libft.h"
#include "base_colours.h"
#include <stdio.h>

static void	write_ppm_header(int fd, int width, int height)
{
	char	*buffer;

	ft_putstr_fd("P3\n", fd);
	buffer = ft_itoa(width);
	ft_putstr_fd(buffer, fd);
	free(buffer);
	ft_putstr_fd(" ", fd);
	buffer = ft_itoa(height);
	ft_putstr_fd(buffer, fd);
	free(buffer);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("255\n", fd);
}

static void	write_pixel_data(int fd, t_rayt *lux, int x, int y)
{
	char			*buffer;
	unsigned char	*addr;
	int				offset;

	addr = (unsigned char *)lux->image.addr;
	offset = (y * lux->image.line_len) + (x * (lux->image.bpp / 8));
	buffer = join_rgb_values(addr[offset + 2], addr[offset + 1], addr[offset]);
	ft_putstr_fd(buffer, fd);
	free(buffer);
}

static void	write_image_data(int fd, t_rayt *lux, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			write_pixel_data(fd, lux, x, y);
			x++;
		}
		ft_putstr_fd("\n", fd);
		y++;
	}
}

/**
 * @brief This function create PPM file based on ASCII characters
 * @param file_path where put the file with data
 * @param lux OG data from processed pipeline
 * @param widht width of the image
 * @param height height of the image
 * Every PPM file begins with a header:
 * P3       ASCII type of PPM
 * 80 40    width & height of the image
 * 255      maximum color value
 * @return 0 succesfull
 * @return 1 unsuccesfull
 */
int	canvas_to_ppm(const char *file_path, t_rayt *lux, int width, int height)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Cannot open output file");
		exit(1);
	}
	write_ppm_header(fd, width, height);
	write_image_data(fd, lux, width, height);
	close(fd);
	return (0);
}
