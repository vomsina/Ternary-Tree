//
// Created by dasha on 01.10.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <Windows.h>

#include "Header.h"



void menu()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("1 Add integer value \n" );
    printf("2 Display tree\n" );
    printf("3 Delete selected item\n" );
    printf("4 Search for the selected item\n" );
    printf("5 Delete the whole tree\n" );
    printf("6 Exit the program\n" );
}
void deleting(struct tree* node)
{
    if (node)
    {
        deleting(node->left);
        deleting(node->right);
        deleting(node->middle);
        free(node);
        node = NULL;
    }
}
void search(struct tree* node, int key)
{
    if (node == NULL) return;
    if (key == node->data)
    {
        printf("Root%d\t" , node->data ,"\n");
        if (node->middle)
        {
            printf("Middle node\t\n");
            return;
        }
        if (node->left)
        {
            printf("Left node%d\t" , node->left->data , "\n");
        }
        else
            printf("Non left child\n");
        if (node->right)
        {
            printf("Right node%d\t " , node->right->data , "\n");
        }
        else
            printf("Non right child \n");

    }
    search(node->left, key);
    search(node->right, key);

}
void print(struct tree* node)
{
if (!node)
{
    printf("poshla nahui");
    return;
}
    printf("%d", &node->left);
    printf("%d", &node->data , ",");
    printf("%d", &node->middle);
    printf("%d", &node->right);
}
void add(int data, struct tree* node)
{
    if (node == NULL)
    {
        printf("posla");
        node = malloc(sizeof(struct tree*));
        node->data = data;
        node->right = NULL;
        node->left = NULL;
        node->middle = NULL;
        return;
    }

    if (data < node->data)
    {

        add(data, node->left);
    }
    else if (data > node->data)
    {

        add(data, node->right);
    }
    else
    {
        add(data, node->middle);
    }

}


struct tree* DeleteNode(struct tree* node, int val) {
    if (node == NULL)
        return node;

    if (val == node->data) {

        struct tree* tmp;
        if (node->right == NULL)
            tmp = node->left;
        else {

            struct tree* ptr = node->right;
            if (ptr->left == NULL) {
                ptr->left = node->left;
                tmp = ptr;
            }
            else {

                struct tree* pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = node->left;
                pmin->right = node->right;
                tmp = pmin;
            }
        }

        free(node);
        return tmp;
    }
    else if (val < node->data)
        node->left = DeleteNode(node->left, val);
    else
        node->right = DeleteNode(node->right, val);
    return node;
}