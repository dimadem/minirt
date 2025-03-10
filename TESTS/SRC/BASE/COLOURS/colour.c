#include "../../../LIB/Unity/src/unity.h"
#include "test.h"
#include "base_colours.h"

void    test_create_colour(void)
{
    t_trgb c;

    print_colored(bold, "Colors are (red, green, blue) tuples");
	print_colored(bold, "colour");
	c = colour(100, 1, 0);
    TEST_ASSERT_EQUAL_DOUBLE(c.t, 255);
    TEST_ASSERT_EQUAL_DOUBLE(c.r, 100);
    TEST_ASSERT_EQUAL_DOUBLE(c.g, 1);
    TEST_ASSERT_EQUAL_DOUBLE(c.b, 0);
    print_colored(green_back, "Passed!");
}

void    test_colour_operations(void)
{
    t_trgb c1, c2, c;

    print_colored(bold, "Adding colors");
	print_colored(bold, "colour");
	print_colored(bold, "colour_sum");
    c1 = colour(150, 100, 150);
    c2 = colour(100, 150, 100);
    c = colour_sum(c1, c2);
    TEST_ASSERT_EQUAL_DOUBLE(c.t, 255);
    TEST_ASSERT_EQUAL_DOUBLE(c.r, 250);
    TEST_ASSERT_EQUAL_DOUBLE(c.g, 250);
    TEST_ASSERT_EQUAL_DOUBLE(c.b, 250);
    print_colored(green_back, "Passed!");
    printf("\n");
    printf("\n");

    print_colored(bold, "Subtracting colors");
	print_colored(bold, "colour");
    print_colored(bold, "colour_subs");
    c1 = colour(150, 100, 150);
    c2 = colour(100, 50, 100);
    c = colour_subs(c1, c2);
    TEST_ASSERT_EQUAL_DOUBLE(c.t, 255);
    TEST_ASSERT_EQUAL_DOUBLE(c.r, 50);
    TEST_ASSERT_EQUAL_DOUBLE(c.g, 50);
    TEST_ASSERT_EQUAL_DOUBLE(c.b, 50);
    print_colored(green_back, "Passed!");
    printf("\n");
    printf("\n");

    print_colored(bold, "Multiplying a color by a scalar");
	print_colored(bold, "colour");
    print_colored(bold, "colour_scalar_mult");
	c1 = colour(100, 50, 2);
    c = colour_scalar_mult(c1, 2);
    TEST_ASSERT_EQUAL_DOUBLE(c.t, 255);
    TEST_ASSERT_EQUAL_DOUBLE(c.r, 200);
    TEST_ASSERT_EQUAL_DOUBLE(c.g, 100);
    TEST_ASSERT_EQUAL_DOUBLE(c.b, 4);
    print_colored(green_back, "Passed!");
    printf("\n");
    printf("\n");

    print_colored(bold, "Multiplying a colors");
	print_colored(bold, "colour");
    print_colored(bold, "colour_scalar_mult");
	c1 = colour(5, 2, 4);
    c2 = colour(5, 2, 4);
    c = colour_hadamard_product(c1, c2);
    TEST_ASSERT_EQUAL_DOUBLE(c.t, 255);
    TEST_ASSERT_EQUAL_DOUBLE(c.r, 25);
    TEST_ASSERT_EQUAL_DOUBLE(c.g, 4);
    TEST_ASSERT_EQUAL_DOUBLE(c.b, 16);
    print_colored(green_back, "Passed!");
    printf("\n");
    printf("\n");
}

void    test_colour_utils(void)
{
    t_trgb c;
    char addr[4];

    print_colored(bold, "t_trgb -> (char *)");
	print_colored(bold, "colour");
	print_colored(bold, "t_trgb_to_addr");
    c = colour(100, 50, 255);
    t_trgb_to_addr(addr, c);
    TEST_ASSERT_EQUAL_HEX8(0xFF, addr[0]); // Blue = 255 = 0xFF
    TEST_ASSERT_EQUAL_HEX8(0x32, addr[1]); // Green = 50 = 0x32
    TEST_ASSERT_EQUAL_HEX8(0x64, addr[2]); // Red = 100 = 0x64
    TEST_ASSERT_EQUAL_HEX8(0xFF, addr[3]); // Alpha = 255 = 0xFF
    print_colored(green_back, "Passed!");
    printf("\n");
    printf("\n");

}


void	colour_test_main()
{
	print_colored(cyan_back, "-> COLOUR <-");

	UNITY_BEGIN();

    RUN_TEST(test_create_colour);
	printf("\n");
    RUN_TEST(test_colour_operations);
    printf("\n");
    RUN_TEST(test_colour_utils);
    printf("\n");

	UNITY_END();
}
