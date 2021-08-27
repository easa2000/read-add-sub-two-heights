// program to read, display, add, and subtract two heights using pointer structure
#include<stdio.h>
typedef struct 
{
    int ft;
    int inch;
}HEIGHT;

HEIGHT h1, h2, h3;
HEIGHT add_height(HEIGHT *,HEIGHT *);
HEIGHT subtract_height(HEIGHT *, HEIGHT *);
int main()
{
    int option;
    system("cls");
    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Read height");
        printf("\n 2. Display height");
        printf("\n 3. Add");
        printf("\n 4. Subtract");
        printf("\n 5.Exit");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the first height in feet and inches: ");
            scanf("%d %d",&h1.ft ,&h1.inch);
            printf("\n Enter the second height in feet and inches: ");
            scanf("%d %d",&h2.ft,&h2.inch);
            break;

        case 2:
            printf("\n The first height is : %d ft %d inch",h1.ft ,h1.inch);
            printf("\n The second height is : %d ft %d inch",h2.ft ,h2.inch);
            break;
        
        case 3:
            h3 = add_height(&h1 , &h2);
            printf("\n The sum of two height is: %d ft %d inch",h3.ft, h3.inch);
            break;
        case 4:
            h3 = subtract_height(&h1, &h2);
            printf("\n The difference of two height is: %d ft %d inch",h3.ft, h3.inch);
            break;
        }
    }while(option != 5);
    return 0;
}

HEIGHT add_height(HEIGHT *h1, HEIGHT *h2)
{
    HEIGHT sum;
    sum.inch = h1->inch + h2->inch;
    while(sum.inch > 12)
    {
        sum.inch -= 12;
        sum.ft++;
    }
    sum.ft = h1->ft + h2->ft;
    return sum;
}

HEIGHT subtract_height(HEIGHT *h1, HEIGHT *h2)
{
    HEIGHT sub;
    if(h1->ft > h2->ft)
    {
        if(h1->inch < h2->inch)
        {
            h1->inch += 12;
            h1->ft--;
        }
        sub.inch = h1->inch - h2->inch;
        sub.ft = h1->ft - h2->ft;
    }
    else
    {
        if(h2->inch < h1->inch)
        {
            h2->inch += 12;
            h2->ft--;
        }
        sub.inch = h2->inch - h1->inch;
        sub.ft = h2->ft - h1->ft;
    }
    return sub;
}
