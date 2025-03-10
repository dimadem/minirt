/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoskune <mcoskune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:14:25 by mcoskune          #+#    #+#             */
/*   Updated: 2025/01/18 19:17:33 by mcoskune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIB/Unity/src/unity.h" 
#include "types.h"
#include "test.h"

/**
* @brief https://github.com/ThrowTheSwitch/Unity
* Code to run before each test, if needed (leave empty otherwise)
*/

void	print_colored(const char* color, const char* message)
{
	printf("%s%s\033[0m", color, message);
	printf("\n");
}

int	main(void)
{
	print_colored(yellow_back, "******TESTS******");
	printf("\n");
	// print_colored(cyan_back, "-> TUPLE <-");
	// tuple_create_test();
	// tuple_manipulation_test();
	// tick_manipulation_test();
	// colour_test_main();
	// matrix_test_main();
	// canvas_test_main();
	// ppm_test_main();
	// matrix_test_transform_main();
	// intersection_test_ray_sphere();
	// light_shading_test();
	// ray_test();
	test_render_intersection_sphere();
	light_shading_test();
	intersection_test_ray_world();
}
