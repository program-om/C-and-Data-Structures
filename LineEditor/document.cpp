#include"document.h"
#include<vector>
#include<cstring>
#include<string> // getline()

/* Vector functions:
   - push_back()   - insert()  -begin()  -empty()  -clear()
   -size()  -erase()  -find()
*/



Document::Document()
{
  currentPos = 0;
}

//-----------------------------------------

void Document::Load(std::istream &in)
{
  std::string temp;
  //replace any lines that already exist
  MakeEmpty();
	
  while (std::getline(in, temp))
    {
      lines.push_back(temp);
    }
  currentPos = 0;
}

//-----------------------------------------

void Document::MakeEmpty()
{
  lines.clear();
  currentPos = 0;
}

//-----------------------------------------

bool Document::IsEmpty() const
{
  if (lines.empty())
    return true;
  else return false;
}

//-----------------------------------------

void Document::Insert(std::string newLine)
{
  if (lines.empty())
    lines.push_back(newLine);
  else
    {
      lines.insert(lines.begin()+currentPos, newLine); //iderator: (lines.begin() return the index
                                                       //of the first element.
    }
}

//-----------------------------------------

void Document::Append(std::string newLine)
{
  if (lines.empty())
    lines.push_back(newLine);
  else
    {
      lines.push_back(newLine);
      currentPos = lines.size() - 1;
    }
}

//-----------------------------------------

void Document::Replace(std::string newLine)
{
  if (lines.empty())
    {
      throw std::string( "ERROR: Replacment command could not be done because the document is Empty!!");
    }
  //No need for else because 'throw' works like 'return'
  lines[currentPos] = newLine;
}

//-----------------------------------------

void Document::Erase()
{
  if (lines.empty())
    throw std::string("ERROR: Deletion command could not be done because the document is Empty!!");
        
  if (currentPos == lines.size() - 1)
    {
      lines.erase(lines.begin() + currentPos);
      currentPos--;
    }
  else
    {
      lines.erase(lines.begin() + currentPos);
      //currentPos += 1;
    }

}

//-----------------------------------------

bool Document::Find(std::string target)
{
  for (int i = 0; i < lines.size(); i++)
    {
      if (lines[i].find(target) != std::string::npos)
	{
	  currentPos = i;
	  return true;
	}
    }
  return false;
}

//-----------------------------------------

void Document::SetCurrent(int n)
{
  if (n < 0 || lines.size() < n + 1)
    throw std::string("ERROR: The value of n is invalid!");
  else
    currentPos = n;
}

//-----------------------------------------

void Document::MoveCurrent(int n)
{
  if (n > 0 && (currentPos + n) < lines.size())
    currentPos += n;
  else if (n < 0 && (currentPos + n) >= 0)
    currentPos += n;
  else
    throw std::string("ERROR: The value of n in invalid!");
}

//-----------------------------------------

void Document::WriteLine(std::ostream &out) const
{
  if(!IsEmpty())
    out << lines[currentPos] << std::endl;
}

//-----------------------------------------

void Document::WriteAll(std::ostream &out) const
{
  for(int i=0; i < lines.size(); i++)
    out << lines[i] << std::endl;
}
