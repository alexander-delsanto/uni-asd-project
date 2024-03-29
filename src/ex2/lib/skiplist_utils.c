/**
 * @file skiplist_utils.c
 * @brief Utility functions for managing and manipulating skiplists.
 */

#include "skiplist_utils.h"
#include <stdio.h>

/**
 * @brief Check if a skiplist is empty.
 *
 * @param[in] list a pointer to the skiplist.
 * @return returns 1 if the skiplist is empty, 0 otherwise.
 */
int skiplist_is_empty(struct SkipList *list)
{
    if(list == NULL){
        fprintf(stderr, "skiplist_is_empty: list parameter cannot be NULL.\n");
        exit(EXIT_FAILURE);
    }
    if(list->heads[0] == NULL)
        return 1;
    return 0;
}

/**
 * @brief Calculates the length (number of nodes) of a skiplist.
 *
 * @param[in] list a pointer to the skiplist.
 * @return the length of the skiplist.
 */
size_t skiplist_length(struct SkipList *list)
{
    if(list == NULL){
        fprintf(stderr, "skiplist_length: list parameter cannot be NULL.\n");
        exit(EXIT_FAILURE);
    }
    size_t length = 0;
    for(struct Node *n = list->heads[0]; n != NULL; n = n->next[0]){
        length++;
    }
    return length;
}

/**
 * @brief Prints a skiplist of integer type items.
 *
 * @note This function assumes that the skiplist's item type is int.
 *
 * @param[in] list a pointer to the skiplist.
 */
void skiplist_print_int(struct SkipList *list)
{
    if(list == NULL){
        fprintf(stderr, "skiplist_print: list parameter cannot be NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < list->max_level; i++){
        printf("level: %ld\n", i+1);
        for(struct Node *n = list->heads[i]; n != NULL; n = n->next[i]){
            printf("[%d]", *(int*)n->item);
            if(n->next[i] != NULL)
                printf("->");
        }
        printf("\n");
    }
}
