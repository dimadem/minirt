#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_helpers.h"
#include "base_matrices.h"
#include "base_rays.h"
#include "base_colours.h"
#include "core_render.h"
#include "features_ppm.h"
#include "core_init.h"
#include "objects_transform.h"
#include "objects_utils.h"
#include "objects_sphere.h"
#include "muk_lib.h"
#include <stdlib.h>
#include "window_size.h"
#include "objects_camera.h"

/**
 * @brief Debugs ray information for specific pixels in the render grid
 * 
 * Prints debug information including pixel coordinates, ray origin, ray direction,
 * and intersection status for every nth pixel (where n is window width/4 and height/4).
 * This creates a sparse debug output grid across the render window.
 * 
 * @param ray Pointer to the ray being traced
 * @param inter Pointer to intersection data (NULL if no intersection)
 * @param i Current pixel x-coordinate
 * @param j Current pixel y-coordinate
 * 
 * @note Debug output occurs only when i and j are multiples of WINDOW_WIDTH/4 
 *       and WINDOW_HEIGHT/4 respectively
 */
void debug_all_rays(t_ray *ray, t_isect *inter, int i, int j)
{
    // Выводим информацию для нескольких ключевых точек
    if (i % (WINDOW_WIDTH/4) == 0 && j % (WINDOW_HEIGHT/4) == 0)
    {
        printf("Pixel [%d,%d]\n", i, j);
        printf("Ray from: (%f, %f, %f)\n", 
            ray->origin->data[0][0],
            ray->origin->data[1][0],
            ray->origin->data[2][0]);
        printf("Direction: (%f, %f, %f)\n",
            ray->direction->data[0][0],
            ray->direction->data[1][0],
            ray->direction->data[2][0]);
        printf("%s\n\n", inter ? "Hit!" : "Miss!");
    }
}

/**
 * @brief Calculate the UV coordinates for a given pixel.
 *
 * This function normalizes the pixel coordinates (i, j) and calculates
 * the corresponding UV coordinates in the camera's viewport. The UV
 * coordinates are used for mapping the pixel to the viewport.
 *
 * @param i         The x-coordinate of the pixel.
 * @param j         The y-coordinate of the pixel.
 * @param camera    Pointer to the camera structure containing viewport dimensions.
 */
static void calculate_uv(int i, int j, t_camera *camera)
{
    // normalizing the pixel coordinates
    camera->viewport.u = (2.0 * ((i + 0.5) / WINDOW_WIDTH) - 1.0) * camera->half_width;
    camera->viewport.v = (1.0 - 2.0 * ((j + 0.5) / WINDOW_HEIGHT)) * camera->half_height;
}

/**
 * @brief Paints a sphere onto the pixel buffer.
 *
 * This function iterates over each pixel in the window and determines if a ray
 * from the camera intersects with the given sphere. If an intersection occurs,
 * the pixel is set to white (0xFFFFFFFF), otherwise it is set to black (0x00000000).
 *
 * @param pixel     pixel buffer.
 * @param sphere    sphere object to be rendered.
 * @param camera    camera object used for rendering.
 */
static void paint_sphere(int **pixel, t_object **sphere, t_camera *camera)
{
    t_ray ray;
    t_isect **inter;
    int y;
    int x;

    y = 0;
    while(y < WINDOW_HEIGHT)
    {
        x = 0;
        while(x < WINDOW_WIDTH)
        {
            // set the direction of the current ray
            calculate_uv(x, y, camera);
            matrix_normalize(camera->v_orient);
            ray = ray_create_local(camera->origin, &camera->viewport);
            inter = ray_intersect_sphere(sphere, &ray);
            pixel[y][x] = (inter != NULL) ? 0xFFFFFFFF : 0x00000000;
            if (inter != NULL) free_dptr((void **)inter);
            x++;
        }
        y++;
    }
}

int    **create_pixel_buffer(int w_h, int w_w)
{
    int **pixel;
    int i;

    i = 0;
    pixel = safe_malloc(sizeof(int *), w_h);
    while (i < w_h)
        pixel[i++] = safe_malloc(sizeof(int), w_w);

    return (pixel);
}

void	test_ray_render(void)
{
    print_colored(bold, "render intercestions of rays of the sphere");
    print_colored(bold, "minilibx library");
    print_colored(bold, "canvas_to_ppm");

    t_rayt  lux;
    int     w_w;
    int     w_h;
    int     **pixel;
    int     i;
    t_object *sphere;
    t_camera *camera;
    t_matrix *transform_temp;
    /************************************************************** */

    //! INIT
    w_w = WINDOW_WIDTH;
    w_h = WINDOW_HEIGHT;
    pixel = NULL;

    // declare camera
    camera = (t_camera *)safe_malloc(sizeof(t_camera), 1);
    camera->type = CAMERA;
    camera->origin = create_point(0, 0, 5);
    camera->v_orient = create_vector(0, 0, -1);
    camera->fov_deg = 70;
    camera_init(camera);

	// declare sphere
	sphere = (t_object *)safe_malloc(sizeof(t_object), 1);
    sphere->type = SPHERE;
	sphere->obj.sphere.radius = 2;
    sphere->obj.sphere.origin = create_point(0, 0, 0);
	sphere->obj.sphere.transform = matrix_identity(4);
    t_matrix *scaling = object_scaling(1, 2, 2);
    transform_temp = matrix_multiple(sphere->obj.sphere.transform, scaling);
    free_matrix(sphere->obj.sphere.transform);
    sphere->obj.sphere.transform = transform_temp;
    free_matrix(scaling);

    // create pixel buffer for the whole screen
    pixel = create_pixel_buffer(w_h, w_w);

    init_lux(&lux);
    lux.mlx_ptr = mlx_init();
    lux.win_ptr = mlx_new_window(lux.mlx_ptr, w_w, w_h, "Test Window");    
    lux.image.img = mlx_new_image(lux.mlx_ptr, w_w, w_h);

    /**
    * @brief Gets the data address of the current image.
    *
    * @param	void *img_ptr			the image instance;
    * @param	int  *bits_per_pixel	a pointer to where the bpp is written;
    * @param	int  *line_length	    a pointer to where the line is written;
    * @param	int  *endian		    a pointer to where the endian is written;
    * @return	char*				    the memory address of the image.
    */
    lux.image.addr = mlx_get_data_addr(lux.image.img, &lux.image.bpp, &lux.image.line_len, &lux.image.endian);
    
    /********************************************************** */

    paint_sphere(pixel, sphere, camera);
    
    /********************************************************** */

    // put red pixels on the image buffer
    pixel_to_image(&lux, pixel, w_w, w_h);

    // cleanup new pixels
    i = 0;
	while (i < w_h)
		free(pixel[i++]);

    // save image to ppm file
    canvas_to_ppm("./sphere.ppm", &lux, w_w, w_h);

    // put data to win
    mlx_put_image_to_window(lux.mlx_ptr, lux.win_ptr, lux.image.img, 0, 0);
    sleep(3);
	free(pixel);
    free_camera(camera);
    free_object(sphere);
    mlx_destroy_image(lux.mlx_ptr, lux.image.img);
    mlx_destroy_window(lux.mlx_ptr, lux.win_ptr);
    mlx_destroy_display(lux.mlx_ptr);
    free(lux.mlx_ptr);
    print_colored(green_back, "Passed!");
    printf("\n");
}

void	test_shadow_render(void)
{

}

void	test_render_intersection_sphere(void)
{
	UNITY_BEGIN();
	print_colored(cyan_back, "-> INTERSECTION FEATURE <-");

	print_colored(bold, "TEST - RAY-SPHERE INTERSECT");
	RUN_TEST(test_ray_render);
	printf("\n");

	print_colored(bold, "TEST - RAY-SPHERE INTERSECT");
	RUN_TEST(test_shadow_render);
	printf("\n");

	UNITY_END();
}