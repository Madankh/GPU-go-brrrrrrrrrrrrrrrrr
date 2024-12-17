#include<stdio.h>

struct address{
    int houseNo;
    int block;
    char city[100];
    char state[100];
};

void printAdd(struct address adds);

struct vector{
    int x;
    int y;
};


// void calcSum(struct vector v1, struct vector v2, struct vector sum);

struct complex{
    int real;
    int img;
};


int main(){ 
    
    // struct address adds[2];
    // printf("Enter yours information");
    // scanf("%d" , &adds[0].houseNo);
    // scanf("%d" , &adds[0].block);
    // scanf("%s" , adds[0].city);
    // scanf("%s" , adds[0].state);

    // // printf("Enter yours information");
    // // scanf("%d" , &adds[1].houseNo);
    // // scanf("%d" , &adds[1].block);
    // // scanf("%s" , &adds[1].city);
    // // scanf("%s" , &adds[1].state);
    // printAdd(adds[0]);

        
    
    // struct vector v1 = {5,10};
    // struct vector v2 = {3,7};
    // struct vector sum = {0};

    // calcSum(v1, v2, sum);

    struct complex number1 = {5,8};
    struct complex *ptr = &number1;

    printf("real part = %d\n", ptr->img);
    printf()
    return 0;
}

void printAdd(struct address adds){
    printf("address is : %d, %d, %s , %s\n" , adds.houseNo, adds.block, adds.city, adds.state);
}

// void calcSum(struct vector v1, struct vector v2, struct vector sum){
//     sum.x = v1.x + v2.x;
//     sum.y = v1.y + v2.y;
//     printf("Sum of x %d\n", sum.x);
//     printf("Sum of y %d\n" , sum.y);
// }