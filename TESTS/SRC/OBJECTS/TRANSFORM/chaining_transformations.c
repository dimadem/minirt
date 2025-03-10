#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "objects_transform.h"
#include "muk_lib.h"
#include <mlx.h>

static void test_chaining_transformation(void)
{
    print_colored(bold, "transform rendered canvas to PPM format");
	print_colored(bold, "minilibx library");
    print_colored(bold, "canvas_to_ppm");
/**
 * 
 */
    print_colored(green_back, "Passed!");
    printf("\n");
}

void chainig_transformations_test_main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_chaining_transformation);
    printf("\n");

    UNITY_END();
}
