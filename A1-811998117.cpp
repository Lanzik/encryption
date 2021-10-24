#include <iostream>
#include <fstream>
#include <vector>

#define START_KEY -1
#define NEXT_KEY_CHARACTER 1
#define ZERO 0
#define SIMPLE "simple"
#define COMPLICATED "complicated"
#define ENCRYPT "encrypt"
#define DECRYPT "decrypt"
#define END_OF_STRING '\0'

using namespace std;

struct Files
{
  string input_file;
  string output_file;
};
bool end_key(int& counter);
void simple_cryption(Files io_file, string key, string crypt);
void complicated_cryption(Files io_file, string key, string crypt);
void cryption();

int main()
{
  cryption();
}

bool end_key(int counter,string key)
{
  if((counter + NEXT_KEY_CHARACTER) == key.size())
  {
    return true;
  }
  return false;
}

void simple_cryption(Files io_file, string key, string crypt)
{
  ifstream input_file(io_file.input_file);
  ofstream output_file(io_file.output_file);
  char temp_character;
  int code;
  if (crypt == ENCRYPT)
  {
    for(int i=0; (input_file.get(temp_character))
    && (!input_file.eof()); i++)
    {
      code = (int)temp_character + (int)key[i];
      output_file << code << endl;
      if(end_key(i, key))
      i = START_KEY;
    }
  }
  else if(crypt == DECRYPT)
  {
    for(int i = 0; input_file >> code; i++)
    {
      code = code - (int)key[i];
      output_file << (char)code;
      if(end_key(i, key))
      i = START_KEY;
    }
  }

}

void complicated_cryption(Files io_file, string key, string crypt)
{
  ifstream input_file(io_file.input_file);
  ofstream output_file(io_file.output_file);
  int key_random = ZERO;
  char temp_character;
  int code;
  for(int i = 0; key[i] != END_OF_STRING; i++)
  {
    key_random += (int)key[i];
  }
  srand(key_random);
  if(crypt == DECRYPT)
  {
    for(int i=0; (input_file >> code) && (!input_file.eof()); i++)
    {
      code = code - (rand() % 11);
      output_file << (char)code;
    }
  }
  else if(crypt == ENCRYPT)
  {
    for(int i=0;(input_file.get(temp_character)) && (!input_file.eof());i++)
    {
      code = (int)temp_character + (rand() % 11);
      output_file << code << endl;
    }
  }
}

void cryption()
{
  string crypt, type, key, input, output;
  cin >> crypt >> type >> key >> input >> output;
  Files io_file;
  io_file.input_file = input;
  io_file.output_file = output;
  if(type == SIMPLE)
  {
    simple_cryption(io_file, key, crypt);
  }
  else if(type == COMPLICATED)
  {
    complicated_cryption(io_file, key, crypt);
  }
}
