#ifndef BAG_H
#define BAG_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/random.h>
#include <stdio.h>
#include <string.h>

#define ARE_EQUAL(first, second) _Generic((first),                                      \
    char*: strcmp(first, second) == 0,                                                  \
    const char*: strcmp(first, second) == 0,                                            \
    default: (first) == (second)                                                        \
)

#define DECLARE_BAG(type)                                                               \
                                                                                        \
typedef struct Node_##type Node_##type;                                                 \
typedef struct Bag_##type Bag_##type;                                                   \
static inline Bag_##type* create_bag_##type(const size_t capacity);                     \
static inline void release_bag_##type(Bag_##type* bag);                                 \
static inline size_t get_current_size_##type(Bag_##type* bag);                          \
static inline bool is_empty_##type(Bag_##type* bag);                                    \
static inline bool add_##type(Bag_##type* bag, type new_entry);                         \
static inline bool remove_random_##type(Bag_##type* bag, type* removed_data_address);   \
static inline bool remove_entry_##type(Bag_##type* bag, type an_entry);                 \
static inline void clear_##type(Bag_##type* bag);                                       \
static inline size_t get_frequency_of_##type(Bag_##type* bag, type an_entry);           \
static inline bool contains_##type(Bag_##type* bag, type an_entry);                     \
static inline type* to_list_##type(Bag_##type* bag);                                    \
static inline bool is_list_full_##type(Bag_##type* bag);

#ifndef IMPLEMENTATION

#include <stdbool.h>
#include <stdlib.h>
#include <sys/random.h>
#include <stdio.h>
#include <string.h>

#define IMPLEMENT_BAG(type)

typedef struct{
    type data;
    Node_##type* previous;
    Node_##type* next;
} Node_##type;

typedef struct{
    Node_##type node;
    Node_##type* head;
    Node_##type* tail;
    size_t size;
} Bag_##type;

static inline Bag_##type* create_bag_##type(){                     \
    Node_##type* node = malloc(sizeof(Node_##type));                                       \
                                                                                        \
    if(node == NULL){                                                                    \
        fprintf(stderr, "Failed to create node!");                                       \
        return NULL;                                                                    \
    }                                                                                   \
                                                                                        \
    bag -> size = 0;                                                                    \
    bag -> data = malloc(sizeof(type) * capacity);                                      \                                                                                \
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
static inline size_t get_current_size_##type(Bag_##type* bag){                          \
    return bag -> size;                                                                 \
}                                                                                       \
                                                                                        \
static inline bool is_empty_##type(Bag_##type* bag){                                    \
        return bag -> size == 0;                                                        \
}                                                                                       \
                                                                                        \
static inline bool add_##type(Bag_##type* bag, type new_entry){                         \
    if(!is_array_full_##type(bag)){                                                     \
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
static inline size_t generate_random_number_##type(Bag_##type* bag){                    \
    if (bag->size == 0) {                                                               \
        return 0;                                                                       \
    }                                                                                   \
    size_t number;                                                                      \
    getrandom(&number, sizeof(size_t), GRND_NONBLOCK);                                  \
    return number % bag -> size;                                                        \
                                                                                        \
}                                                                                       \
                                                                                        \
static inline bool remove_random_##type(Bag_##type* bag, type* removed_data_address){   \
    if(is_empty_##type(bag)){                                                           \
        perror("Size of the bag must be positive!");                                    \
        return false;                                                                   \
    }                                                                                   \
                                                                                        \
    size_t random_number = generate_random_number_##type(bag);                          \
                                                                                        \
    type* last_data_address = bag -> data + bag -> size - 1;                            \
    type* new_data_address = bag -> data + random_number;                               \
                                                                                        \
    *removed_data_address = *new_data_address;                                          \
    *new_data_address = *last_data_address;                                             \
    bag -> size--;                                                                      \
    return true;                                                                        \
}                                                                                       \
                                                                                        \
static inline bool remove_entry_##type(Bag_##type* bag, type an_entry){                 \
    bool is_removed = false;                                                            \
    type* last_data_address = bag -> data + bag -> size - 1;                            \
    type* new_data_address;                                                             \
                                                                                        \
    for(type* p = bag -> data; p < bag -> data + bag -> size; p++){                     \
        if(ARE_EQUAL(*p, an_entry)){                                                    \
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
static inline size_t get_frequency_of_##type(Bag_##type* bag, type an_entry){           \
    size_t count = 0;                                                                   \
    for(type* p = bag -> data; p < bag -> data + bag -> size; p++){                     \
        if(ARE_EQUAL(*p, an_entry)){                                                    \
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
        if(ARE_EQUAL(*p, an_entry)){                                                    \
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
}                                                                                       \
                                                                                        \
static inline bool is_array_full_##type(Bag_##type* bag){                               \
    if(bag -> size == bag -> capacity){                                                 \
        return true;                                                                    \
    }                                                                                   \
    else{                                                                               \
        return false;                                                                   \
    }                                                                                   \
}

#endif
#endif