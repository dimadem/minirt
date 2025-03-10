#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "core_render.h"
#include "core_init.h"
#include "base_colours.h"
#include <mlx.h>
#include "muk_lib.h"

void test_canvas_initialization(void)
{
    print_colored(bold, "initialization & put red pixel to Canvas");
	print_colored(bold, "minilibx library");
    print_colored(bold, "pixel_to_image");

    t_rayt  lux;
    int     w_w;
    int     w_h;
    int     **pixel;
    int     i;
    int     j;
    t_trgb c;
    
    w_w = 100;
    w_h = 200;

    i = 0;
	pixel = safe_malloc(sizeof(int *), w_h);
	while (i < w_h)
		pixel[i++] = safe_malloc(sizeof(int), w_w);

    init_lux(&lux);

    lux.mlx_ptr = mlx_init();
    TEST_ASSERT_NOT_NULL(lux.mlx_ptr);
    
    lux.win_ptr = mlx_new_window(lux.mlx_ptr, w_w, w_h, "Test Window");
    TEST_ASSERT_NOT_NULL(lux.win_ptr);
    
    lux.image.img = mlx_new_image(lux.mlx_ptr, w_w, w_h);
    TEST_ASSERT_NOT_NULL(lux.image.img);

    /*
    ** Gets the data address of the current image.
    **
    ** @param	void *img_ptr			the image instance;
    ** @param	int  *bits_per_pixel	a pointer to where the bpp is written;
    ** @param	int  *line_length	    a pointer to where the line is written;
    ** @param	int  *endian		    a pointer to where the endian is written;
    ** @return	char*				    the memory address of the image.
    */
    lux.image.addr = mlx_get_data_addr(lux.image.img, &lux.image.bpp, &lux.image.line_len, &lux.image.endian);
    TEST_ASSERT_NOT_NULL(lux.image.addr);
    TEST_ASSERT_EQUAL_INT(32, lux.image.bpp);
    
    // put red color on each pixel of he screen
    c = colour(255, 0, 0);
    i = 0;
    while(i < w_h)
    {
        j = 0;
        while(j < w_w)
        {
            pixel[i][j] = t_trgb_to_hex(c); 
            j++;
        }   
        i++;     
    }
    // put red pixels on the image buffer
    pixel_to_image(&lux, pixel, w_w, w_h);
    // cleanup new pixels
    i = 0;
	while (i < w_h)
		free(pixel[i++]);
	free(pixel);
    // put data to win
    mlx_put_image_to_window(lux.mlx_ptr, lux.win_ptr, lux.image.img, 0, 0);
    sleep(3);
    mlx_destroy_image(lux.mlx_ptr, lux.image.img);
    mlx_destroy_window(lux.mlx_ptr, lux.win_ptr);
    mlx_destroy_display(lux.mlx_ptr);
    free(lux.mlx_ptr);
    print_colored(green_back, "Passed!");
    printf("\n");
}

void canvas_test_main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_canvas_initialization);
    printf("\n");

    UNITY_END();
}
