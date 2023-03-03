#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main(int argc, char **argv)
{ 
   unsigned int i; // counter to loop from 1-10
   int item; // variable to hold random values
   BST b;

   
	b.root= NULL;  b.size=0;// tree initially empty
  for(i=1;i<argc;i++) { 
      insertNode( &b, atoi(argv[i]));
   //  insertNode_R(&b.root,atoi(argv[i]) );
  } // end for
   // traverse the tree preOrder
   /* printf("\nThe preOrder traversal is:\n" );
   preOrder( rootPtr );*/

   // traverse the tree inOrder
   printf("\nThe inOrder traversal is:\n" );
   inOrder(b.root);
   printf("\nThe preOrder traversal is:\n");
   preOrder(b.root);
   printf("\nThe postOrder traversal is:\n"); 
   postOrder(b.root); 
   //4 2 9 8 6 1 3
   //7 3 1 10 6 4 7 14 13
/*
   // traverse the tree postOrder
 printf("\nThe postnOrder traversal is:\n" );   postOrder( rootPtr );
*/
    printf("\n");
} // end main

