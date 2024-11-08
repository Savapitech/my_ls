/*
** EPITECH PROJECT, 2024
** __
** File description:
** _
*/

#include "lib.h"

static
void mini_swap(char *a, char *b, size_t size)
{
    char swap;

    for (size_t i = 0; i < size; i++) {
        swap = a[i];
        a[i] = b[i];
        b[i] = swap;
    }
}

void mini_qsort(char *arr, size_t size, size_t mem_s,
    int compare(void const *, void const *))
{
    void *pivot = IDX_OF(arr, size - 1, mem_s);
    size_t cp_index = 0;

    if (size < 2)
        return;
    for (size_t i = 0; i < size; i++) {
        if (compare(IDX_OF(arr, i, mem_s), pivot) < 0) {
            mini_swap(IDX_OF(arr, i, mem_s),
                IDX_OF(arr, cp_index, mem_s), mem_s);
            cp_index++;
        }
    }
    mini_swap(IDX_OF(arr, cp_index, mem_s), pivot, mem_s);
    if (size == 2)
        return;
    mini_qsort(arr, cp_index, mem_s, compare);
    mini_qsort(IDX_OF(arr, cp_index + 1, mem_s),
        size - (cp_index + 1), mem_s, compare);
}
