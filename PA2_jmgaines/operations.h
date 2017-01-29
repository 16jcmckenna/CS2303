#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

int print, pause, gens, x, y;
int **grid, **variable_grid, **prev1, **prev2; 
int cur_gen;

int compare_matrices(int **arr1, int **arr2);

int stuck_pat(int **cur_arr, int **prev1_arr);

int repeating_pat(int **cur_arr, int **prev2_arr);

int all_dead(int **arr);

int is_complete(int **arr);

void print_gen(int **arr);

void apply_ops(void);

#endif
