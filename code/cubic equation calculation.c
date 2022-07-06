#include<stdio.h>

int getSize(int number1)
{
    int size = 0;
    for(int divisor = 1; divisor < number1+1 ; divisor++ )
    {
        if( (number1 % divisor) == 0)                  //get the size
            size = size + 1;
    }

    return (size);
}


float* getDiv(int number1,int sizex)
{
//--------------------------------------------------------------------

    static int arrx[10];  //we identify the size of the array and create it
    int x = 0;

//--------------------------------------------------------------------
    for (int c = 1; c < number1 + 1 ; c++)
    {
        if ( (number1 % c) == 0 )
        {
            arrx[x] = c;
            x = x + 1;     //fill the array with divisor of the number
        }
    }
//--------------------------------------------------------------------
    return (arrx);
}

void printArr(int arr1[],int size1)
{
        for (int i  = 0; i < size1 ; i++)
    {        printf("%d ", arr1[i]);
    }
    printf("\n");

}


int main()
{
    float a ,b ,c ,d;

    printf("enter (A, B, C,D) of equation : \n");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    printf("\na :%f, b :%f, c:%f, d:%f\n", a ,b ,c, d);

    int size1 = getSize(a); // size of array 1
    int size2 = getSize(d); // size of array 2

    float* arr1= getDiv(a, size1);  //get divisor for  array 1
    //printArr(arr1, size1);              // print array 1

    float* arr2 = getDiv(d, size2); //get divisor of array 2
    //printArr (arr2, size2);             // print array 2

//--------------------------------------------------------------------
    int size3 = size1 * size2;
    float arr3[size3];
    int y = 0;
//-------------------------------------------------------------------
    for (int i = 0 ; i < size1 ; i++)
    {
        for(int j = 0; j < size2 ; j++)
        {
            arr3[y] = ((arr2[j] / arr1[i]) );   //divide the divisor
            y = y + 1;
        }
    }

//-------------------------------------------------------------------

        for (int i = 0; i < size3; i ++)
    {
        for (int j = i + 1; j < size3; j++)
        {
            if ( arr3[i] == arr3[j])
            {
                for (int k = j; k < size3 - 1; k++)  // removing duplicates
                {
                    arr3[k] = arr3 [k + 1];
                }
                size3--;
                j--;
            }
        }
    }
    printf("\na :%f, b :%f, c:%f, d:%f\n", a ,b ,c, d);
//-------------------------------------------------------------------
                /*//adding the negative element
int o = 1;
printf("%d\n", size3);
for (int i = 0 ; i < size3 ; i++)
{
    arr3[size3 + o] = -arr3[i];
    printf("%0.4f, ",arr3[size3 + o]);
    o = o + 1;
}
*/
//-------------------------------------------------------------------
    printf("\na :%f, b :%f, c:%f, d:%f\n", a ,b ,c, d);

//-------------------------------------------------------------------
    printf("\n");
    printf("array3 = [ ");
    for (int i = 0; i < (size3 + 1); i++)
    {
        printf (" %0.2f, ", arr3[i]);          // print the array 3
    }printf("]");

//-------------------------------------------------------------------
float E, G, H, I, J, K;
float value_x;

for (int i =0 ; i < (size3 * 2) ; i++)
{
    printf("\na :%0.4f, b :%0.4f, c :%0.4f, d :%0.4f,",a, b, c ,d);
    value_x = arr3[i];
    printf("\n Value : %0.4f", arr3[i]);

    E = arr3[i] * a;
    printf("\nE : %0.4f\n", E);

    G = b + E;
    printf("G = %0.4f + %0.4f = %0.4f\n",b, E, G);

    H = arr3[i] * G;
    printf("H : %0.4f\n", H);

    I = c + H;
    printf("I : %0.4f\n", I);

    J = arr3[i] * I;
    printf("J : %0.4f\n", J);

    K = d +J;
    printf("K : %0.4f\n", K);

    printf("\n------------------\n");

    if (K == 0.000000)
        break;

}

if (K == 0.000000)
{
        printf("\n\n%0.4f, %0.4f, %0.4f, %0.4f", a, G, I, K);
        printf("\n\nroot1 =  %0.4f\n", value_x);

//-----------------------------------------------------------------
        float root2, root3;
        float delta = (G*G) - (4 * a * I);
        //printf("delta = %f", delta);


        if (delta < 0)
        {
            float real = -G /(2 * a);
            float imagine = sqrt(delta) / (2 * a);
            printf("root2 = (%0.4f + %0.4f) \n", real, imagine);
            printf("root3 = (%0.4f - %0.4f) \n", real, imagine);
        }


        else if(delta == 0)
        {
            root2 = root3 = -G / (2 * a);

            printf("root2 = %0.4f", root2);
            printf("root3 = %0.4f", root3);
        }

        else
        {
            root2 = (-G + sqrt(delta)) / (2 * a);
            root3 = (-G - sqrt(delta)) / (2 * a);
            printf("root2 = %0.4f\n", root2);
            printf("root3 =  %0.4f\n", root3);
        }

}
else
{
    printf("\nthere is might be mistake\n");
    printf("\nlet me try again...\n");
    //---------------------------------------
    for (int i = 0; i < size3; i++)
    {
        arr3[i] = - arr3[i];       // negative numbers
    }
    //-----------------------------------------

        printf("array3 = [ ");
    for (int i = 0; i < (size3); i++)
    {
        printf (" %0.2f, ", arr3[i]);          // print the array 3
    }printf("]");
    //-----------------------------------------

    for (int i =0 ; i < (size3 * 2) ; i++)
    {
        printf("\na :%0.4f, b :%0.4f, c :%0.4f, d :%0.4f,",a, b, c ,d);
        value_x = arr3[i];
        printf("\n Value : %0.4f", arr3[i]);

        E = arr3[i] * a;
        printf("\nE : %0.4f\n", E);

        G = b + E;
        printf("G = %0.4f + %0.4f = %0.4f\n",b, E, G);

        H = arr3[i] * G;
        printf("H : %0.4f\n", H);

        I = c + H;
        printf("I : %0.4f\n", I);

        J = arr3[i] * I;
        printf("J : %0.4f\n", J);

        K = d +J;
        printf("K : %0.4f\n", K);

        printf("\n------------------\n");

        if (K == 0.000000)
            break;
    }
        printf("\n\n%0.4f, %0.4f, %0.4f, %0.4f", a, G, I, K);
        printf("\n\nroot1 =  %0.4f\n", value_x);

//-----------------------------------------------------------------
        float root2, root3;
        float delta = (G*G) - (4 * a * I);
        //printf("delta = %f", delta);


        if (delta < 0)
        {
            float real = -G /(2 * a);
            float imagine = sqrt(delta) / (2 * a);
            printf("root2 = (%0.4f + %0.4f) \n", real, imagine);
            printf("root3 = (%0.4f - %0.4f) \n", real, imagine);
        }


        else if(delta == 0)
        {
            root2 = root3 = -G / (2 * a);

            printf("root2 = %0.4f", root2);
            printf("root3 = %0.4f", root3);
        }

        else
        {
            root2 = (-G + sqrt(delta)) / (2 * a);
            root3 = (-G - sqrt(delta)) / (2 * a);
            printf("root2 = %0.4f\n", root2);
            printf("root3 =  %0.4f\n", root3);
        }

}


    return (0);
}


