#include "bag.h"

DECLARE_BAG(int)
IMPLEMENT_BAG(int)

int main()
{
    Bag_int *bag = create_bag_int(20);
    if (bag != NULL)
    {
        bool is_empty = is_empty_int(bag);
        int data[] = {101, 102, 434, 102, 301, 105, 434, 102};
        int size_all_data = sizeof(data) / sizeof(data[0]);

        if (is_empty)
        {
            for (int i = 0; i < size_all_data; i++)
            {
                bool is_added = add_int(bag, data[i]);
                if (is_added)
                {
                    printf("%d is added.\n", data[i]);
                }
                else
                {
                    printf("%d is not added.\n", data[i]);
                }
            }
        }

        int current_size_bag = get_current_size_int(bag);
        printf("Current size of bag is %d.\n", current_size_bag);

        bool is_contain = contains_int(bag, 434);
        if (is_contain)
        {
            printf("%d is found!\n", 434);
        }
        else
        {
            printf("%d is not found!\n", 434);
        }

        int frequency_102 = get_frequency_of_int(bag, 102);
        printf("Frequency of %d is %d.\n", 102, frequency_102);

        int *array_data = to_array_int(bag);
        if(array_data != NULL){
            for (int i = 0; i < current_size_bag; i++){
                printf("%d \n", array_data[i]);
            }

            free(array_data);
        }

        int frequency_101 = get_frequency_of_int(bag, 101);
        for (int i = 0; i < frequency_101; i++)
        {
            bool is_removed = remove_entry_int(bag, 101);
            if (is_removed)
            {
                printf("%d is removed.\n", 101);
            }
        }

        int *removed_data_address;
        int value;
        removed_data_address = &value;
        bool is_removed_random_data = remove_random_int(bag, removed_data_address);
        if (is_removed_random_data)
        {
            printf("%d is selected randomly.\n", *removed_data_address);
        }

        clear_int(bag);
        release_bag_int(bag);
    }

    return 0;
}