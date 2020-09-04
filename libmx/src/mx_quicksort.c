#include "../inc/libmx.h"

static void mx_swaparr_elements(char **s1, char **s2, int *counter);
static int partition(char **arr, int left, int right, int *counter);

int mx_quicksort(char **arr, int left, int right) {

    static int swap_counter = 0;

    if (!(*arr))
        return -1;

    if (left < right) {
        int loc = partition(arr, left, right, &swap_counter);

        mx_quicksort(arr, left, loc - 1);
        mx_quicksort(arr, loc + 1, right);
    }

    return swap_counter;
}

static int partition(char **arr, int left, int right, int *counter) {
    int pivot = mx_strlen(arr[left]);
    int start = left;
    int end = right;

    while (start < end) {
        while (start <= end && mx_strlen(arr[start]) <= pivot)
            start++;

        while (mx_strlen(arr[end]) > pivot)
            end--;

        if (start < end)
            if (&arr[start] != &arr[end])
                mx_swaparr_elements(&arr[start], &arr[end], counter);
    }
    if (&arr[left] != &arr[end])
        mx_swaparr_elements(&arr[left], &arr[end], counter);

    return end;
}

static void mx_swaparr_elements(char **s1, char **s2, int *counter) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    (*counter)++;
}
