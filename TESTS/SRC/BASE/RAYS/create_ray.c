#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_rays.h"
#include "base_matrices.h"

void TEST_ASSERT_EQUAL_MATRIX(t_matrix *expected, t_matrix *actual) 
{
    TEST_ASSERT_EQUAL_DOUBLE(expected->data[0][0], actual->data[0][0]);
    TEST_ASSERT_EQUAL_DOUBLE(expected->data[1][0], actual->data[1][0]);
    TEST_ASSERT_EQUAL_DOUBLE(expected->data[2][0], actual->data[2][0]);
    TEST_ASSERT_EQUAL_DOUBLE(expected->data[3][0], actual->data[3][0]);
}

void	test_ray_create(void) 
{
	t_matrix *origin;
    t_matrix *direction;
    t_ray *r;

	origin = create_point(1, 2, 3);
    direction = create_vector(4, 5, 6);
    r = ray_create(origin, direction);
    print_colored(bold, "Creating and querying a ray");
	print_colored(bold, "create_point");
	print_colored(bold, "create_vector");
    print_colored(bold, "create_ray");
	TEST_ASSERT_EQUAL_MATRIX(origin, r->origin);
    TEST_ASSERT_EQUAL_MATRIX(direction, r->direction);
    print_colored(green_back, "Ray - ray_create 	- Test 1 - Passed!");
    free_ray(r);
}

void	test_ray_position(void) 
{
    t_matrix *origin;
    t_matrix *direction;
    t_ray *r;
	t_matrix *ray_p;
    t_matrix *p1, *p2, *p3, *p4;

	origin = create_point(2, 3, 4);
    direction = create_vector(1, 0, 0);
    r = ray_create(origin, direction);
    print_colored(bold, "Computing a point from a distance");
	print_colored(bold, "create_point");
	print_colored(bold, "create_vector");
    print_colored(bold, "create_ray");
    p1 = create_point(2, 3, 4);
    ray_p = ray_position(r, 0);
    TEST_ASSERT_EQUAL_MATRIX(p1, ray_p);
    free_matrix(ray_p);
    p2 = create_point(3, 3, 4);
    ray_p = ray_position(r, 1);
    TEST_ASSERT_EQUAL_MATRIX(p2, ray_p);
    free_matrix(ray_p);
    p3 = create_point(1, 3, 4);
    ray_p = ray_position(r, -1);
    TEST_ASSERT_EQUAL_MATRIX(p3, ray_p);
    free_matrix(ray_p);
    p4 = create_point(4.5, 3, 4);
    ray_p = ray_position(r, 2.5);
    TEST_ASSERT_EQUAL_MATRIX(p4, ray_p);
    free_matrix(ray_p);
    print_colored(green_back, "Ray - ray_position 	- Test 2 - Passed!");
    free_ray(r);
    free_matrix(p1);
    free_matrix(p2);
    free_matrix(p3);
    free_matrix(p4);
}

void    test_ray_intersection(void)
{
    t_matrix *origin;
    t_matrix *direction;
    t_ray *r;

	origin = create_point(1, 2, 3);
    direction = create_vector(4, 5, 6);
    r = ray_create(origin, direction);
    
    print_colored(bold, "Creating and querying a ray");
	print_colored(bold, "create_point");
	print_colored(bold, "create_vector");
    print_colored(bold, "create_ray");
	TEST_ASSERT_EQUAL_MATRIX(origin, r->origin);
    TEST_ASSERT_EQUAL_MATRIX(direction, r->direction);
    print_colored(green_back, "Ray - ray_create 	- Test 1 - Passed!");
    free_ray(r);
}


void	ray_test()
{
	UNITY_BEGIN();

	print_colored(bold, "TEST - RAY");

	RUN_TEST(test_ray_create);
	RUN_TEST(test_ray_position);

    printf("\n");
	UNITY_END();
}
