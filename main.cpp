/*
* File: main.cpp
* Developer: Angel Acosta
* Email: acostaa126247@student.vvc.edu
* Description: Counting words in a story while converting uppercase letters to lower case.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctype.h>
#include <sstream>

int main()
{

     char file[2000];
     //int lines[100][2];

     int i = 0, j = 0, k = 0;
     double line = 0;

     std::string lines[1000];
     std::string word;
     std::string concord[1000];

     int count[1000] = {0};
     int index = 0;
     std::cout << "Enter the text file name: " << std::endl;
     //read file name

     std::cin.get(file, 100);
     std::ifstream ifs;
     //open text file
     ifs.open("alice.txt");

     if(!ifs.is_open())
     {
          std::cout << "Unable to open file" << std::endl;
          return 0;

     }

     std::string w;
    //temporary string

     //read all lines
     while(ifs.good())
     {
          getline(ifs, word);//read line by line
          //removing punctations and converting upper case letters to lower case
          for(int i = 0; i < word.length(); i++)
          {
              if(!isalpha(word.at(i)))
              {
                   if(word.at(i) != ' ')

                   for(int j = i; j < word.length() - 1; j++)
                   {
                        word.at(j) = word.at(j + 1);
                   }
                   
                   if(i == word.length() - 1)
                        word.at(i) = ' ';
              }
              
              if(!islower(word.at(i)))
              {
                   word.at(i) = tolower(word.at(i));

              }

          }

          std::istringstream iss(word);
          while(iss >> w) //read each word in each line
          {
              bool flag = false;
              int matchedAt = -1;

              for(int k = 0; k < index; k++)
              {
                   if(concord[k] == w)
                   {
                        flag = true;
                        matchedAt = k;

                   }

              }
              if(flag != true)
              {
                   concord[index] = w;
                   count[index] = 1;

                   std::stringstream num;
                   num << line + 1;

                   lines[index] = num.str();
                   index++;

              }
              else
              {
                   count[matchedAt]++;

                   std::stringstream numb;
                   numb << line + 1; //numb!!
                   lines[matchedAt] = lines[matchedAt] + "," + numb.str();//numb??

              }

          }
          line = line + 1;

     }
        //print concord
     std::cout << std::left << std::setw(15) << "Word" << std::setw(3) << " : " << "count" << std::setw(3) << " : " << "Occurences" << std::endl;
     std::cout << "----------------------------------------------------------------------------" << std::endl;

     for(int l = 0; l < index; l++)
          std::cout << std::left << std::setw(15) << concord[l] << std::setw(5) << " : " << count[l] << std::setw(3) << " : " << lines[l] << std::endl;

     return 0;

}




