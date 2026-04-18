#ifndef BAG_H
#define BAG_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/random.h>
#include <stdio.h>
#include <string.h>

#define DECLARE_BAG(type)                                                               \
                                                                                        \
typedef struct{                                                                         \
    int capacity;                                                                       \
    int size;                                                                           \
    type* data;                                                                         \
} Bag_##type;                                                                           \
                                                                                        \
static inline Bag_##type* create_bag_##type(int capacity);                              \
static inline void release_bag_##type(Bag_##type* bag);                                 \
static inline int get_current_size_##type(Bag_##type* bag);                             \
static inline bool is_empty_##type(Bag_##type* bag);                                    \
static inline bool add_##type(Bag_##type* bag, type new_entry);                         \
static inline bool remove_random_##type(Bag_##type* bag, type* removed_data_address);   \
static inline bool remove_entry_##type(Bag_##type* bag, type an_entry);                 \
static inline void clear_##type(Bag_##type* bag);                                       \
static inline int get_frequency_of_##type(Bag_##type* bag, type an_entry);              \
static inline bool contains_##type(Bag_##type* bag, type an_entry);                     \
static inline type* to_array_##type(Bag_##type* bag);

#define IMPLEMENT_BAG(type)                                                             \
                                                                                        \
static inline Bag_##type* create_bag_##type(int capacity){                              \
    Bag_##type* bag = malloc(sizeof(Bag_##type));                                       \
                                                                                        \
    if(bag == NULL){                                                                    \
        perror("Failed to create bag!");                                                \
        return NULL;                                                                    \
    }                                                                                   \
                                                                                        \
    bag -> capacity = capacity;                                                         \
    bag -> size = 0;                                                                    \
    bag -> data = malloc(sizeof(type) * capacity);                                      \
                                                                                        \
    if(bag -> data == NULL){                                                            \
        free(bag);                                                                      \
        perror("Failed to allocate memory for data! Bag memory has been freed.");       \
        return NULL;                                                                    \
    }                                                                                   \
                                                                                        \
    return bag;                                                                         \
}                                                                                       \
                                                                                        \
static inline void release_bag_##type(Bag_##type* bag){                                 \
    if(bag != NULL){                                                                    \
        if(bag -> data != NULL){                                                        \
            free(bag -> data);                                                          \
        }                                                                               \
        free(bag);                                                                      \
    }                                                                                   \
}                                                                                       \
                                                                                        \
static inline int get_current_size_##type(Bag_##type* bag){                             \
    return bag -> size;                                                                 \
}                                                                                       \
                                                                                        \
static inline bool is_empty_##type(Bag_##type* bag){                                    \
        return bag -> size == 0;                                                        \
}                                                                                       \
                                                                                        \
static inline bool add_##type(Bag_##type* bag, type new_entry){                         \
    if(bag -> size < bag -> capacity){                                                  \
        type* new_entry_address = bag -> data + bag -> size;                            \
        *new_entry_address = new_entry;                                                 \
        bag -> size++;                                                                  \
        return true;                                                                    \
    }                                                                                   \
    else{                                                                               \
        return false;                                                                   \
    }                                                                                   \
}                                                                                       \
                                                                                        \
static inline int generate_random_number_##type(Bag_##type* bag){                       \
    if(bag -> size == 0){                                                               \
        return -1;                                                                      \
    }                                                                                   \
                                                                                        \
    int number;                                                                         \
    int byte_number = getrandom(&number, sizeof(int), GRND_NONBLOCK);                   \
                                                                                        \
    if(byte_number != sizeof(int)){                                                     \
        perror("Random number generation failed");                                      \
        return -1;                                                                      \
    }                                                                                   \
                                                                                        \
    unsigned int u_number = (unsigned int) number;                                      \
    u_number %= bag -> size;                                                            \
    return u_number;                                                                    \
                                                                                        \
}                                                                                       \
                                                                                        \
static inline bool remove_random_##type(Bag_##type* bag, type* removed_data_address){   \
    int random_number = generate_random_number_##type(bag);                             \
                                                                                        \
    if(random_number == -1){                                                            \
        fprintf(stderr, "Error: Could not remove data from bag.\n");                    \
        return false;                                                                   \
    }                                                                                   \
    else{                                                                               \
        type* last_data_address = bag -> data + bag -> size - 1;                        \
        type* new_data_address = bag -> data + random_number;                           \
                                                                                        \
        *removed_data_address = *new_data_address;                                      \
        *new_data_address = *last_data_address;                                         \
        bag -> size--;                                                                  \
        return true;                                                                    \
    }                                                                                   \
                                                                                        \
}                                                                                       \
                                                                                        \
static inline bool remove_entry_##type(Bag_##type* bag, type an_entry){                 \
    bool is_removed = false;                                                            \
    type* last_data_address = bag -> data + bag -> size - 1;                            \
    type* new_data_address;                                                             \
                                                                                        \
    for(type* p = bag -> data; p < bag -> data + bag -> size; p++){                     \
        if(*p == an_entry){                                                             \
            new_data_address = p;                                                       \
            is_removed = true;                                                          \
            break;                                                                      \
        }                                                                               \
    }                                                                                   \
                                                                                        \
    if(is_removed){                                                                     \
        *new_data_address = *last_data_address;                                         \
        bag -> size--;                                                                  \
    }                                                                                   \
                                                                                        \
    return is_removed;                                                                  \
}                                                                                       \
                                                                                        \
static inline void clear_##type(Bag_##type* bag){                                       \
    bag -> size = 0;                                                                    \
}                                                                                       \
                                                                                        \
static inline int get_frequency_of_##type(Bag_##type* bag, type an_entry){              \
    int count = 0;                                                                      \
    for(type* p = bag -> data; p < bag -> data + bag -> size; p++){                     \
        if(*p == an_entry){                                                             \
            count++;                                                                    \
        }                                                                               \
    }                                                                                   \
                                                                                        \
    return count;                                                                       \
}                                                                                       \
                                                                                        \
static inline bool contains_##type(Bag_##type* bag, type an_entry){                     \
    bool is_contains = false;                                                           \
                                                                                        \
    for(type* p = bag -> data; p < bag -> data + bag -> size; p++){                     \
        if(*p == an_entry){                                                             \
            is_contains = true;                                                         \
            break;                                                                      \
        }                                                                               \
    }                                                                                   \
                                                                                        \
    return is_contains;                                                                 \
                                                                                        \
}                                                                                       \
                                                                                        \
/*The user must free the memory that is used, if it is not necessary*/                  \
static inline type* to_array_##type(Bag_##type* bag){                                   \
    type* bag_array = malloc(sizeof(type) * bag -> size);                               \
                                                                                        \
    if(bag_array == NULL){                                                              \
        perror("Memory allocation failed for array!");                                  \
        return NULL;                                                                    \
    }                                                                                   \
                                                                                        \
    memcpy(bag_array, bag -> data, bag -> size * sizeof(type));                         \
                                                                                        \
    return bag_array;                                                                   \
}

#endif