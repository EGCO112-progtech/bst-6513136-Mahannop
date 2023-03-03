// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
    int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode *TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
  int size;
	TreeNodePtr root;
}BST;

// prototypes



void insertNode_R(TreeNodePtr *t,int value) {
  if((*t)==NULL) {
     *t = (TreeNodePtr)malloc(sizeof(struct TreeNode)); 
  if(*t) {
     (*t)->leftPtr = NULL;
		 (*t)->rightPtr = NULL;
		 (*t)->data = value;
     }
    else printf("It's not inserted, No memory allocate !");
  }
  else { if((*t)->data >= value) insertNode_R(&(*t)->leftPtr,value);
       //left
    else insertNode_R(&(*t)->rightPtr,value);
       //right
    }
}

void insertNode(BST *b, int value) {
	 TreeNodePtr t = b->root , new_node;
	 int inserted = 0;
	 new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	 if(new_node){
		new_node->leftPtr = NULL;
		new_node->rightPtr = NULL;
		new_node->data = value;
		/*First Node*/
		if(!b->root) {
      b->root=new_node; }
		else {
     while(!inserted) {
        if(t->data >= value) { 
          if(t->leftPtr == NULL) { 
          t->leftPtr = new_node;
          inserted = 1; //success inserted break loop
        }
          else t = t->leftPtr;

         /* move/insert to the left*/
      }
        else { 
          if(t->rightPtr == NULL) { 
          t->rightPtr = new_node;
          inserted = 1; //success inserted break loop 
        } 
          else t = t->rightPtr;
        }
         /* move/insert to the right*/
    } //end while		
  } //end else;
  
     b->size++;
  }
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if (treePtr!=NULL) {        
        
      inOrder(treePtr->leftPtr); //Recursion to the left call until find NULL in left side ! 
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder(treePtr->rightPtr); //Recursion to the right call until find NULL in right side !
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr) {
    if(treePtr != NULL) {
       printf("%3d",treePtr->data); 
       preOrder(treePtr->leftPtr);
       preOrder(treePtr->rightPtr); 
    }
}

void postOrder( TreeNodePtr treePtr) {
    if(treePtr != NULL) {
       postOrder(treePtr->leftPtr);
       postOrder(treePtr->rightPtr);
       printf("%3d",treePtr->data);
    }
}
