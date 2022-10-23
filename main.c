#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct tree* root = NULL;
    for (;;)
    {
        int data;
        int m;
        menu();
        scanf_s("%d", &m);

        switch (m)
        {
        case 1:


            printf("Enter integer value\n");
            scanf_s("%d", &data);
            add(data, root);
            break;

        case 2:

            print(root);
            break;


        case 3:

            printf("What value you want to delete?\n");
            int z;
            scanf_s("%d", &z);
            DeleteNode(root, z);
            break;
        case 4:
            printf("What value you want to search?\n");
            int l;
            scanf_s("%d", &l);
            search(root, l);
            break;
        case 5:
            deleting(root);
            printf("Tree was succesfull deleted!\n");
            break;

        case 6:

            return 0;
        }
    }

}