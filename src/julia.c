#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<unistd.h>
typedef struct{
    double real_part;
    double imag_part;
}complex_number;
typedef struct set{
    int nrows;
    int ncols;
    double min_real;
    double max_real;
    double min_imag;
    double max_imag;
    complex_number c;
    complex_number **complex_matrix;
    char ***julia_set;
}SET;
complex_number new_complex(double real_part, double imag_part){
    complex_number temp;
    temp.real_part = real_part;
    temp.imag_part = imag_part;
    return temp;
}
SET *new_set(int nrows, int ncols, double min_real, double max_real, double min_imag, double max_imag){
    SET *temp = (struct set *)malloc(sizeof(struct set));
    temp -> nrows = nrows;
    temp -> ncols = ncols;
    temp -> min_real = min_real;
    temp -> max_real = max_real;
    temp -> min_imag = min_imag;
    temp -> max_imag = max_imag;
    temp ->c = new_complex(-0.8,0.156);
    temp -> julia_set = (char ***)malloc(temp->nrows*sizeof(char**));
    temp -> complex_matrix = (complex_number **)malloc(temp->nrows * sizeof(complex_number*));
    for (int i = 0; i < temp->ncols; i++){
        temp->complex_matrix[i] = (complex_number *)malloc(temp->ncols*sizeof(complex_number));
        temp->julia_set[i] = (char**)malloc(temp->ncols*sizeof(char*));
    }
    return temp;
}
void set_matrix(SET* set){
    double real_step = (fabs(set->min_real)+fabs(set->max_real))/(set->ncols-1);
    double imag_step = (fabs(set->min_imag)+fabs(set->max_imag))/(set->nrows-1);
    double real_itr = set->min_real;
    double imag_itr = set->min_imag;
    for (int i = 0; i < set->ncols; i++){
        for (int j = 0; j < set->nrows; j++){
            set->complex_matrix[i][j] = new_complex(real_itr,imag_itr);
            real_itr+=real_step;
        }
        real_itr = set->min_real;
        imag_itr+= imag_step;
    }
}
complex_number add(complex_number a, complex_number b){
    complex_number temp;
    temp.real_part = a.real_part+b.real_part;
    temp.imag_part = a.imag_part+b.imag_part;
    return temp;
}
complex_number square(complex_number c){
    complex_number temp;
    temp.real_part = (pow(c.real_part,2)-pow(c.imag_part,2));
    temp.imag_part = (2*c.real_part*c.imag_part);
    return temp;
}
double absolute_complex(complex_number c){
    return sqrt(pow(c.real_part,2)+pow(c.imag_part,2));
}
void delete_set(SET* set){
    for (int i = 0; i < set->ncols;i++){
        free(set->julia_set[i]);
        free(set->complex_matrix[i]);
    }
    free(set->julia_set);
    free(set->complex_matrix);
    set->julia_set=NULL;
    set->complex_matrix=NULL;
}
int iterate_z(complex_number z, SET *set, int itr){
    z = square(z);
    z = add(set->c,z);
    int count = 0;
    while (absolute_complex(z) < 4.0){
        complex_number z_temp = square(z);
        complex_number z_temp_two = add(set->c,z_temp);
        z = z_temp_two;
        count++;
        if (count > itr){
            return -1;
        }
    }
    return count;
}
void set_julia(SET* set, int itr){
    for (int i = 0; i < set->ncols; i++){
        for (int j = 0; j < set->nrows; j++){
            if (iterate_z(set->complex_matrix[i][j],set,itr) != -1){
                set->julia_set[i][j] = "  ";
            } else {
                set->julia_set[i][j] = "x ";
            }
        }
    }
    system("clear");
}
void print_julia(SET* set){
    for (int i = 0; i < set->ncols; i++){
        for (int j = 0; j < set->nrows; j++){
            printf("%s",set->julia_set[i][j]);
        }
        printf("\n");
    }
}
int main(){
    SET* set = new_set(100,100,-1,1,-1,1);
    set_matrix(set);
    set_julia(set,60);
    print_julia(set);
    delete_set(set);
    free(set);
    set = NULL;
}
