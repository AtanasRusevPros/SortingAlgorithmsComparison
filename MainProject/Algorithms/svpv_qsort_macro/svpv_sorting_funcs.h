
#ifndef SVPV_SORTING_FUNCS_H
#define SVPV_SORTING_FUNCS_H

void svpv_stdlib_isort(int* A, unsigned int n);
void svpv_stl_isort(int* A, unsigned int n);
void svpv_isort_qsort(int* A, unsigned int n);

void svpv_stl_isort_RusevMerge(int arr[], unsigned int size);
void svpv_isort_qsort_RusevMerge(int arr[], unsigned int size);

#endif // SVPV_SORTING_FUNCS_H
