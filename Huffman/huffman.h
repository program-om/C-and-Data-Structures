#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include<iostream>
#include<string>

struct TreeNode;

class HuffmanTree
{
  
 public:
  // Default constructor
  HuffmanTree();
  // Explicit constructor
  HuffmanTree(const HuffmanTree &source);
  // Destructor
  ~HuffmanTree();
  
  void Load(std::istream &codefile);

  void MakeEmpty();

  HuffmanTree & operator=(HuffmanTree source);

  void Write(std::ostream out);

  void Encode(std::istream &messageFile, std::ostream &out);

  void Decode(std::istream &messageFile, std::ostream &out);

  /* Non-member functions:
      -CopyTree  -Destroy  -WriteTree  -CharToCode*/

   private:
     TreeNode* root;
  
};

#endif

