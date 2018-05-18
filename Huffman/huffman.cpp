// File: huffman.cpp
//
// This is huffman class operations. This file construce huffman tree
//
// ------------------------------------------------------------------------

#include<iostream>
#include<string> // c++ string
#include"huffman.h"


struct TreeNode{
  char letter;
  TreeNode* left;   // when new node is created, by the default left and right pointers will
  TreeNode* right;  // point to NULL
};

void CopyTree(TreeNode* &copyRoot, TreeNode* localRoot); //non-member function

void Destroy(TreeNode* &localRoot); //non-member function

void WriteTree(std::ostream &out, TreeNode* localRoot, int level); //non-member function

std::string CharToCode(char ch, TreeNode* localRoot, std::string pathSoFar); //non-member function

//------------------------------------------------
void HuffmanTree::Load(std::istream &codefile)
{
  // n is the number of the lines
  int n, k=0;
  std::string code;
  char letter;
  root = new TreeNode;
  TreeNode* localRoot = root;
  
  // getting the number of letters
  codefile >> n;
  
  while(k < n){ // while NOT the end of the file
    
    //recieve the letter
    std::cout << "input" << std::endl;
    codefile >> letter;
    //codefile.ignore();
    //recieve the code
    codefile >> code;
    std::cout << letter << " " << code << std::endl;
    //Iteriate 
    for(int i=0; i < code.length(); i++){
      
      if(code[i] == '0'){ // go left
        
        // If the node does not exist, then create it and continue
        if(localRoot->left == NULL){
          localRoot->left = new TreeNode;
        }
        localRoot = localRoot->left; 
        
      } else if(code[i] == '1'){ // go right
        
        if(localRoot->right == NULL){
          localRoot->right = new TreeNode;
        }
        localRoot = localRoot->right;
        
      } else{
        std::cout << "ERROR: INVALID CODE!" << std::endl;
        //exit
      }
      //localRoot->letter = '*';
      //if the letter is $ or %
    }
    
    localRoot->letter = letter;//source of the seg fault for n 10
    
    k++;
  }
  
}


//------------------------------------------------
 // Default constructor
HuffmanTree::HuffmanTree()
  {
    root = NULL;
  }

//------------------------------------------------
// copy constructor
HuffmanTree::HuffmanTree(const HuffmanTree &source)
  {
    CopyTree(root, source.root);
  }

  void CopyTree(TreeNode* &copyRoot, TreeNode* localRoot) //non-member function
  {
    //Base Case
    if(localRoot == NULL)
      copyRoot = NULL;
    else
      {
	// creating a new node
	copyRoot = new TreeNode;
	
	copyRoot->letter = localRoot->letter;
	// copying the left sub-tree                  
	CopyTree(copyRoot->left, localRoot->left);   //            
	// copying the right sub-tree                        <<  Recursive Cases
	CopyTree(copyRoot->right, localRoot->right); //
      }
  }

//------------------------------------------------
// Destructor
HuffmanTree::~HuffmanTree()
  {
    Destroy(root);
  }

  void Destroy(TreeNode* &localRoot)  //non-member function
  {
 
    if(localRoot != NULL)
      {
	Destroy(localRoot->left);
	Destroy(localRoot->right);
	delete localRoot;
      }
  }

//------------------------------------------------
void HuffmanTree::MakeEmpty()
  {
     Destroy(root);
     root = NULL;
  }

//------------------------------------------------
HuffmanTree & HuffmanTree::operator=(HuffmanTree source)
  {
    HuffmanTree CopyTree(source);
    std::swap(root, CopyTree.root);

    return *this;
  }

//------------------------------------------------
void HuffmanTree::Write(std::ostream out)
  {
    WriteTree(out, root, 0);
  }

//------------------------------------------------
void WriteTree(std::ostream &out, TreeNode* localRoot, int level)  //non-member function
  {
    if(localRoot != NULL)
      {
	WriteTree(out, localRoot->right, (level+1));
	for(int i=0; i < 8*level; i++) // spaces in front of the data
	  out << " ";
	out << localRoot->letter << std::endl;
	WriteTree(out, localRoot->left, level);
      }
  }

//------------------------------------------------
void HuffmanTree::Encode(std::istream &messageFile, std::ostream &out)
  {
    char ch;
    
    while(messageFile.get(ch))
      {
	out << CharToCode(ch, root, "");
      }
    std::cout << "2- i was here" << std::endl;
    out << std::endl;
  }

//---------------------------------------------------
std::string CharToCode(char ch, TreeNode* localRoot, std::string pathSoFar) //non-member function
  // recursive helper function
  {
    std::string code; // code for the letter that is being encoded
    
    // when a leaf node is reached
    if(localRoot->left == NULL && localRoot->right == NULL)
      {
    // if (leaf value = ch)
    //  - return the path(code)
      if(localRoot->letter == ch)
	{
	code = pathSoFar;
	return code;
	}
    // else      // this is not the correct path
    //  - return empty string
      else
	return code;
      }
    else // if this is not the leaf
         // then continue transvesing
      {
	CharToCode(ch, localRoot->left, (pathSoFar+'0'));
	CharToCode(ch, localRoot->right, (pathSoFar+'1'));
      }

    //this line added to avoid the console warning
    return code;
  }

//---------------------------------------------------
void HuffmanTree::Decode(std::istream &messageFile, std::ostream &out)
  {
    std::string code;
    TreeNode* localRoot = root;
    messageFile >> code;

    for(int i=0; i < code.length(); i++)
      {
	if(code[i] == '0')
	  {
	    localRoot = localRoot->left;
	  }
	else if(code[i] == '1')
	  {
	    localRoot = localRoot->right;
	  }
	else
	  std::cout << "Warning: There are some characters which are ignored!" << std::endl;

	if(localRoot->right == NULL && localRoot->left == NULL)
	  out << localRoot->letter;
      }
  }

