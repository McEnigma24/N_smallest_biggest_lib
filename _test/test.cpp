// clang-format off
#include <gtest/gtest.h> // must be first
// clang-format on
#include "N_smallest_or_biggest_values.hpp"

struct OBJ
{
    int a;
    int b;
    int c;

    OBJ(int _a = 0, int _b = 0, int _c = 0) : a(_a), b(_b), c(_c) {}
};

TEST(SampleTest, smallest_3)
{
    N_smallest_or_biggest_values::N_smallest_values<3, int, OBJ> smallest_values;
    int value;

    value = 3;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 5;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 2;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 1;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 4;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 10;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 20;
    smallest_values.push(value, new OBJ(value, value, value));

    int size{};
    N_smallest_or_biggest_values::entry_t<int, OBJ>* tab = smallest_values.get_data(size);

    EXPECT_EQ(size, 3);

    EXPECT_EQ(tab[base_0(1)].value, 1);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, 1);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, 1);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, 1);

    EXPECT_EQ(tab[base_0(2)].value, 2);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, 2);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, 2);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, 2);

    EXPECT_EQ(tab[base_0(3)].value, 3);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, 3);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, 3);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, 3);
}

TEST(SampleTest, smallest_5)
{
    N_smallest_or_biggest_values::N_smallest_values<5, int, OBJ> smallest_values;
    int value;

    value = 16468;
    smallest_values.push(value, new OBJ(value, value, value));
    value = -56559;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 4541;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 5;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 0;
    smallest_values.push(value, new OBJ(value, value, value));
    value = 100;
    smallest_values.push(value, new OBJ(value, value, value));
    value = -2000;
    smallest_values.push(value, new OBJ(value, value, value));

    int size{};
    N_smallest_or_biggest_values::entry_t<int, OBJ>* tab = smallest_values.get_data(size);

    EXPECT_EQ(size, 5);

    EXPECT_EQ(tab[base_0(1)].value, -56559);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, -56559);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, -56559);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, -56559);

    EXPECT_EQ(tab[base_0(2)].value, -2000);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, -2000);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, -2000);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, -2000);

    EXPECT_EQ(tab[base_0(3)].value, 0);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, 0);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, 0);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, 0);

    EXPECT_EQ(tab[base_0(4)].value, 5);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->a, 5);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->b, 5);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->c, 5);

    EXPECT_EQ(tab[base_0(5)].value, 100);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->a, 100);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->b, 100);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->c, 100);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
