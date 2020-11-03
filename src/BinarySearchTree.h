// Assignment #6
// Name:
// ASU Email Address:
// Description: To be completed

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib> //to use atoi

using namespace std;

//Project represents some project information
class Project
 {
  private: 
    string projectName;
    string region;
    int cost;
    Project * left, * right, * parent;


  public:
    //The following two functions are constructors
    Project()
     { 
      projectName = "?";
      region = "?";
      cost = 0;
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    Project(string newProjectName, string newRegion, int newCost)
     {
      projectName = newProjectName;
      region = newRegion;
      cost = newCost;
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    //The following functions are accessor functions
    Project * getLeft()
     {
      return left;
     }

    Project * getRight()
     {
      return right;
     }

    Project * getParent()
     {
      return parent;
     }
     
    string getProjectName()
     {
         return projectName;
     }
     string getRegion()
     {
         return region;
     }
     int getCost()
     {
         return cost;
     }
     

    //The following functions are mutator functions
    void setLeft(Project * other)
     {
       left = other;
     }

    void setRight(Project * other)
     {
       right = other;
     }

    void setParent(Project * other)
     {
       parent = other;
     }

    //The print method prints the project information
    void print()
     {
         cout << "Project Name: " << projectName << endl;
         cout << "Region: " << region << endl;
         cout << "Cost: " << cost << endl << endl;
     }

   //you can add more functions

 };

//class BinarySearchTree will contains projects
class BinarySearchTree
 {
  private:
     Project * root;
     int size;

  public:
     BinarySearchTree();
     ~BinarySearchTree();
     int postOrderTreeDelete(Project * x);
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(Project *);
     void preOrderTreeWalk(Project *);
     void postOrderTreeWalk(Project *);
     Project * treeSearchNode(Project *, string k);
     Project * treeSearch(string k);
     Project * treeMinimum();
     Project * treeMaximum();
     Project * treeMinimumNode(Project *);
     Project * treeMaximumNode(Project *);
     Project * treeSuccessor(string str);
     Project * treePredecessor(string str);
     bool treeInsert(string,string,int);
     bool rightRotate(string);
     bool leftRotate(string);
 };

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
 {
  root = NULL;
 }

//The descurtor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
 {
   int x = postOrderTreeDelete(root);
   cout << "The number of nodes deleted: " << x << endl;
 }

//Checks if the tree is empty
bool BinarySearchTree::isEmpty()
 {
   if (root == NULL)
    return true;
   else
    return false; 
 }

//prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint() // done
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    inOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint() // done
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    preOrderTreeWalk(root);
    cout << "\n";
   }
 }

//prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint() // done
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    postOrderTreeWalk(root);
    cout << "\n";
   }
 }

///COMPLETE THE REQUIRED FUNCTIONS
 
void BinarySearchTree::inOrderTreeWalk(Project * x) // done
{
  if(x == NULL) { return;}
  inOrderTreeWalk(x->getLeft());
  x->print();
  inOrderTreeWalk(x->getRight());
};

void BinarySearchTree::preOrderTreeWalk(Project * x) //done
{
 if(x == NULL){ return;}
 x->print();
 preOrderTreeWalk(x->getLeft());
 preOrderTreeWalk(x->getRight());
};

void BinarySearchTree::postOrderTreeWalk(Project * x) //done
{
if(x == NULL){ return;}
 postOrderTreeWalk(x->getLeft());
 postOrderTreeWalk(x->getRight());
 x->print();
};

/**
 * @brief 
 * 
 * @param x 
 * @param k 
 * @return Project * - If the return value is null the key is not found,
 *                     If a valid pointer is returned, it will point to the found node 
 */
Project * BinarySearchTree::treeSearchNode(Project * x, string k) // done
{
  if(x == NULL || k== x->getProjectName()){return x;}
  if (k.compare(x->getProjectName()) < 0)
  {
    return treeSearchNode(x->getLeft(), k);
  } else 
  {
    return treeSearchNode(x->getRight(),k);
  }
};

Project * BinarySearchTree::treeSearch(string k) // done
{
  if(root == NULL){ return 0;}
  return treeSearchNode(root, k);
};

Project * BinarySearchTree::treeMinimum() // done
{
  Project * x = root;
  if(x == NULL){ return 0;} // Tree is empty
  while(x->getLeft() != NULL)
  {
    x = x->getLeft();
  }
  return x;
};

Project * BinarySearchTree::treeMaximum() // done
{
  Project * x = root;
  if(x == NULL){ return 0;} // Tree is empty
  while(x->getRight() != NULL)
  {
    x = x->getRight();
  }
  return x;
};

Project * BinarySearchTree::treeMinimumNode(Project * x) // done
{
  Project * s = x;
  if(x == NULL){ return 0;} // Tree is empty
  while(s->getLeft() != NULL)
  {
    s = s->getLeft();
  }
  return s;
};

Project * BinarySearchTree::treeMaximumNode(Project * x) // done
{
  Project * s = x;
  if(s == NULL){ return 0;} // Tree is empty
  while(s->getRight() != NULL)
  {
    s = s->getRight();
  }
  return s;
};

Project * BinarySearchTree::treeSuccessor(string x) // done
{
  Project * s = treeSearch(x);
  if(root == NULL  || s == NULL){ return 0;}; // tree is empty or no proj existss with name x
  if(s->getRight() != NULL){ return treeMinimumNode(s->getRight()); }
  Project * y = s->getParent();
  while(y != NULL && s == y->getRight())
  {
   s = y;
   y = y->getParent();
  }
  return y;
};

Project * BinarySearchTree::treePredecessor(string x) // done
{
  Project * s = treeSearch(x);
  if(root == NULL  || s == NULL){ return 0;}; // tree is empty or no proj existss with name x
  if(s->getLeft() != NULL){ return treeMaximumNode(s->getLeft()); }
  Project * y = s->getParent();
  while(y != NULL && s == y->getLeft())
  {
   s = y;
   y = y->getParent();
  }
  return y;
};

bool BinarySearchTree::treeInsert(string name,string region,int cost) //done
{
  Project * success = new Project(name,region,cost);
  if(success == NULL) { return 0;}; // check for mem err
  
  Project * y = NULL;
  Project * x = root; 

  while(x)
  {
    y = x;
    if(name.compare(x->getProjectName()) < 0)
    {
      x = x->getLeft();
    } 
    else if (name.compare(x->getProjectName()) > 0)
    {
      x = x->getRight();
    } else 
    {
      return 0;
    }
  }

  success->setParent(y);

  if(y == NULL){root = success; }                 // tree was empty
  else if(name.compare(y->getProjectName()) < 0)
  {
    y->setLeft(success);
  }
  else { y->setRight(success);}

  return 1;
};

bool BinarySearchTree::leftRotate(string s)
{
  Project * x = treeSearch(s);
  if(x == NULL){return 0;} // no proj found with name s

  Project * y = x->getRight();
  x->setRight(y->getLeft());

  if(y->getLeft() != NULL)
  {
    (y->getLeft())->setParent(x);
  }
  
  y->setParent(x->getParent());

  if(x->getParent() == NULL)
  {
    root = y;
  } else 
  {
    if(x == (x->getParent())->getLeft())
    {
      (x->getParent())->setLeft(y);
    } else
    {
      (x->getParent())->setRight(y);
    }
  }

y->setLeft(x);
x->setParent(y);
return 1;
};

bool BinarySearchTree::rightRotate(string s)
{
  Project * y = treeSearch(s);
  if(y == NULL){return 0;} // no proj found with name s

  Project * x = y->getLeft();
  y->setLeft(x->getRight());

  if(x->getRight() != NULL)
  {
    (x->getRight())->setParent(y);
  }
  x->setParent(y->getParent());
  if( y-> getParent() == NULL)
  {
    root = x;
  } else if(y==(y->getParent())->getRight()){
    (y->getParent())->setRight(x);
  } else
  {
    (y->getParent())->setLeft(x);
  }
  x->setRight(y);
  y->setParent(x);
  return 1;
};


int BinarySearchTree::postOrderTreeDelete(Project * x){
  if(x == NULL){ return 0;}
    int l = postOrderTreeDelete(x->getLeft());
    int r = postOrderTreeDelete(x->getRight());
    delete x;
    return 1 + l + r;
}