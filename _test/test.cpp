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

    value = 1;
    EXPECT_EQ(tab[base_0(1)].value, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, value);

    value = 2;
    EXPECT_EQ(tab[base_0(2)].value, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, value);

    value = 3;
    EXPECT_EQ(tab[base_0(3)].value, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, value);
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

    value = -56559;
    EXPECT_EQ(tab[base_0(1)].value, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, value);

    value = -2000;
    EXPECT_EQ(tab[base_0(2)].value, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, value);

    value = 0;
    EXPECT_EQ(tab[base_0(3)].value, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, value);

    value = 5;
    EXPECT_EQ(tab[base_0(4)].value, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->c, value);

    value = 100;
    EXPECT_EQ(tab[base_0(5)].value, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->c, value);
}

TEST(SampleTest, biggest_3)
{
    N_smallest_or_biggest_values::N_biggest_values<3, int, OBJ> biggest_values;
    int value;

    value = 3;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 5;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 2;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 1;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 4;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 10;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 20;
    biggest_values.push(value, new OBJ(value, value, value));

    int size{};
    N_smallest_or_biggest_values::entry_t<int, OBJ>* tab = biggest_values.get_data(size);

    EXPECT_EQ(size, 3);

    value = 20;
    EXPECT_EQ(tab[base_0(1)].value, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, value);

    value = 10;
    EXPECT_EQ(tab[base_0(2)].value, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, value);

    value = 5;
    EXPECT_EQ(tab[base_0(3)].value, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, value);
}

TEST(SampleTest, biggest_5)
{
    N_smallest_or_biggest_values::N_biggest_values<5, int, OBJ> biggest_values;
    int value;

    value = 16468;
    biggest_values.push(value, new OBJ(value, value, value));
    value = -56559;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 4541;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 5;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 0;
    biggest_values.push(value, new OBJ(value, value, value));
    value = 100;
    biggest_values.push(value, new OBJ(value, value, value));
    value = -2000;
    biggest_values.push(value, new OBJ(value, value, value));

    int size{};
    N_smallest_or_biggest_values::entry_t<int, OBJ>* tab = biggest_values.get_data(size);

    EXPECT_EQ(size, 5);

    value = 16468;
    EXPECT_EQ(tab[base_0(1)].value, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(1)].obj_ptr->c, value);

    value = 4541;
    EXPECT_EQ(tab[base_0(2)].value, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(2)].obj_ptr->c, value);

    value = 100;
    EXPECT_EQ(tab[base_0(3)].value, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(3)].obj_ptr->c, value);

    value = 5;
    EXPECT_EQ(tab[base_0(4)].value, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(4)].obj_ptr->c, value);

    value = 0;
    EXPECT_EQ(tab[base_0(5)].value, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->a, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->b, value);
    EXPECT_EQ(tab[base_0(5)].obj_ptr->c, value);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
