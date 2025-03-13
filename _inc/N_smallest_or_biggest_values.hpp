#pragma once
#include "__preprocessor__.h"

namespace N_smallest_or_biggest_values
{
    template <typename value_t, class obj_t>
    struct entry_t
    {
        value_t value;
        obj_t* obj_ptr;

        entry_t() { memset(this, 0, sizeof(*this)); }
    };

    template <int tab_size, typename value_t, class obj_t>
    class N_smallest_values
    {
        entry_t<value_t, obj_t> tab[tab_size];
        int index_of_biggest_value = -1;

    private:
        void puch_back(const value_t& value, obj_t* obj)
        {
            index_of_biggest_value++;

            tab[index_of_biggest_value].value = value;
            tab[index_of_biggest_value].obj_ptr = obj;
        }

        void insert(const int index, const value_t& value, obj_t* obj)
        {
            if (index_of_biggest_value != (tab_size - 1)) { index_of_biggest_value++; }

            // moving obj to make space //
            for (int i = index_of_biggest_value; i >= (index + 1); i--)
            {
                tab[i] = tab[i - 1];
            }

            tab[index].value = value;
            tab[index].obj_ptr = obj;
        }

    public:
        void push(const value_t& value, const obj_t* obj)
        {
            // first obj //
            if (index_of_biggest_value == -1)
            {
                puch_back(value, (obj_t*)obj);
                return;
            }

            // pierwsza wartość jest najmniejsza
            const value_t smallest_value =
                tab[0].value; // optymalizacja żeby wyszukiwać binarnie, bo jak będę wkładał we właściwe miejsca to będzie posortowane
            const value_t biggest_value = tab[index_of_biggest_value].value;

            // jak jest większa od aktualnie największej to dajemy ją na koniec i nic nie przenosimy
            if (biggest_value < value)
            {
                if (index_of_biggest_value == (tab_size - 1))
                {
                    // wszystkie pozycje są już zajęte i można odrzucać
                    return;
                }

                puch_back(value, (obj_t*)obj);
                return;
            }

            // jest gdzieś pomiędzy - trzeba przejść i ustawić na właściwe miejsce
            for (int i = 0; i < tab_size; i++)
            {
                if (value < tab[i].value)
                {
                    insert(i, value, (obj_t*)obj);
                    return;
                }
            }
        }

        entry_t<value_t, obj_t>* get_data(int& size)
        {
            size = index_of_biggest_value + 1;
            return tab;
        }
    };

    template <int tab_size, typename value_t, class obj_t>
    class N_biggest_values
    {
        entry_t<value_t, obj_t> tab[tab_size];
        int index_of_smallest_value = -1;

    private:
        void puch_back(const value_t& value, obj_t* obj)
        {
            index_of_smallest_value++;

            tab[index_of_smallest_value].value = value;
            tab[index_of_smallest_value].obj_ptr = obj;
        }

        void insert(const int index, const value_t& value, obj_t* obj)
        {
            if (index_of_smallest_value != (tab_size - 1)) { index_of_smallest_value++; }

            // moving obj to make space //
            for (int i = index_of_smallest_value; i >= (index + 1); i--)
            {
                tab[i] = tab[i - 1];
            }

            tab[index].value = value;
            tab[index].obj_ptr = obj;
        }

    public:
        void push(const value_t& value, const obj_t* obj)
        {
            // first obj //
            if (index_of_smallest_value == -1)
            {
                puch_back(value, (obj_t*)obj);
                return;
            }

            // pierwsza wartość jest najmniejsza
            const value_t smallest_value = tab[index_of_smallest_value].value;
            const value_t biggest_value = tab[0].value;

            // jak jest większa od aktualnie największej to dajemy ją na koniec i nic nie przenosimy
            if (smallest_value < value)
            {
                if (index_of_smallest_value == (tab_size - 1))
                {
                    // wszystkie pozycje są już zajęte i można odrzucać
                    return;
                }

                puch_back(value, (obj_t*)obj);
                return;
            }

            // jest gdzieś pomiędzy - trzeba przejść i ustawić na właściwe miejsce
            for (int i = 0; i < tab_size; i++)
            {
                if (value < tab[i].value)
                {
                    insert(i, value, (obj_t*)obj);
                    return;
                }
            }
        }

        entry_t<value_t, obj_t>* get_data(int& size)
        {
            size = index_of_smallest_value + 1;
            return tab;
        }
    };
} // namespace N_smallest_or_biggest_values