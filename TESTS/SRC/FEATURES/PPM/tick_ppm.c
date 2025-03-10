#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "core_init.h"
#include "core_render.h"
#include "base_colours.h"
#include "base_matrices.h"
#include "features_ppm.h"
#include "muk_lib.h"


void setUp(void)
{
}

void tearDown(void)
{
}

static void tuple_tick(t_matrix *projective_position, t_matrix *projective_velocity, 
                t_matrix *environment_gravity, t_matrix *environment_wind)
{
    t_matrix *new_position;
    t_matrix *new_velocity;
    t_matrix *env_forces;

    // env_forces = gravity + wind
    env_forces = matrix_sum(environment_gravity, environment_wind);
    // new_position = poition + velocity
    new_position = matrix_sum(projective_position, projective_velocity);
    // velocity = velocity + gravity + wind
    new_velocity = matrix_sum(projective_velocity, env_forces);

    // normalise velocity vector
    matrix_normalize(new_velocity);

    // add new position
    *projective_velocity = *new_velocity;
    *projective_position = *new_position;

    free(new_position);
    free(new_velocity);
    free(env_forces);
}

static void test_canvas_to_ppm(void)
{
    print_colored(bold, "transform rendered canvas to PPM format");
	print_colored(bold, "minilibx library");
    print_colored(bold, "canvas_to_ppm");

    t_rayt  lux;
    t_trgb c;
    int     w_w;
    int     w_h;
    int     **pixel;
    int     i;
    int     j;
    
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
    c = colour(0, 255, 0);
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

    t_matrix *projective_position; // point
    t_matrix *projective_velocity; // vector
    t_matrix *environment_gravity; // vector
    t_matrix *environment_wind;    // vector

    projective_position = create_point(0, 1, 0);
    projective_velocity = create_vector(1, 1, 0);
    matrix_normalize(projective_velocity);
    environment_gravity = create_vector(0, -0.1, 0);
    environment_wind = create_vector(-0.01, 0, 0);

    while(projective_position->data[1][0] >= 0)
    {
        tuple_tick(projective_position, projective_velocity,
                    environment_gravity, environment_wind);
        printf("Position: x=%f, y=%f, z=%f\n", 
               projective_position->data[0][0], projective_position->data[1][0], projective_position->data[2][0]);
    }
    // put red pixels on the image buffer
    pixel_to_image(&lux, pixel, w_w, w_h);
    // cleanup new pixels
    i = 0;
	while (i < w_h)
		free(pixel[i++]);
	free(pixel);
    free_matrix(projective_position);
    free_matrix(projective_velocity);
    free_matrix(environment_gravity);
    free_matrix(environment_wind);
    canvas_to_ppm("./test.ppm", &lux, w_w, w_h);
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

void tick_ppm_test_main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_canvas_to_ppm);
    printf("\n");

    UNITY_END();
}
