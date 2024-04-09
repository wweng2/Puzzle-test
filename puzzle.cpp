#include "puzzle.h"
Puzzle::Puzzle(int size){
    // *************************************
    // Implement the alternative constructor
    // *************************************
  if(size > 0 ){
    m_size = size;// Turn m_size into the size the user want in order to be use on thr construction of the array
  }
  else if (size < 0){
    cout<<"Size was negative and such is turned into 0"<<endl;
    m_size = 0;

  }

  else{
    m_size = 0;
  }
  makeMem();
  fill();

}
Puzzle::~Puzzle(){
    clear();
  }
void Puzzle::clear(){
    // ***************************
    // Implement clear() function
    // ***************************
  int i = 0;
  if(m_size > 0){// If m_size if not 0 and such the array is not empty then delte everything
    for (i = 0 ; i < m_size ; i++){
      delete []m_table[i];// Starts by deleting the the rows first
    }
    delete []m_table;// Then the entire thing to make sure everything is delocated
    m_size = 0;
  }
  else{
    cout<<"There is nothing to delete as nothing is in m_table"<<endl;

  }
}
void Puzzle::makeMem(){
    // ****************************
    // Implement makeMem() function
    // ****************************
  int i = 0;
  if(m_size > 0){
    m_table = new char* [m_size];// Make the array the size the user want but is also a pointer so i can store dynaically allocated array
    
    for ( i = 0 ; i < m_size; i++){
      m_table[i] = new char [m_size]; // Put each index a new array to create columns
  }
  }
  else{
    cout<<"Size is zero, so no array is made"<<endl;
  }
  }
Puzzle::Puzzle(const Puzzle& rhs){
    // ***************************
    // Implement copy constructor
    // ***************************

  if(m_size > 0){
    m_size = rhs.m_size;// Copy the size over to be used in the creation of the array

   int i = 0;
   int a = 0; 
   m_table = new char* [m_size];
  
     
    for ( i = 0 ; i < rhs.m_size; i++){// Just put evertyhing in the array on to the m_table
      m_table[i] = rhs.m_table[i];
      }

    for( i = 0; i < rhs.m_size; i++){

      for( a = 0; a < rhs.m_size; a++){
	m_table[i][a] = rhs.m_table[i][a];
      }
    }
  }
     

  else{
    cout<<"There is nothing to copy as the array is empty"<<endl;
    
  
 
  }
}
const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    // *****************************
    // Implement assignment operator
    // *****************************

  if (this != &rhs){// To protect agianst self assignmwent
    if(m_size > 0){
      clear();// dletes everything then put in the new data
    }
    m_size = rhs.m_size;
    
    
    int i = 0;
    
    m_table = new char *[m_size];
    
    
    for ( i = 0 ; i < m_size; i++){
      m_table[i] = rhs.m_table[i];
    }

    
    
  }
  else{

    cout<<"This is a self assigment and not allowed"<<endl;
  }


    return *this;
}
void Puzzle::dump(){
  if (m_size > 0){
        int i=0;
        int j=0;
        while(i<m_size){
	  while(j<m_size){
	    cout << m_table[i][j] << " ";
                j++;
	  }
	  cout << endl;
	  j=0;
	  i++;
        }
        cout << endl;
  }
}
void Puzzle::fill(){
    srand(time(NULL));//create the seed value using the current time
    int i=0;
    int j=0;
    while(i<m_size){
        while(j<m_size){
            m_table[i][j] = ALPHA[rand() % MAX];//find a random char from the chars list
            j++;
        }
        j=0;
        i++;
    }
}
