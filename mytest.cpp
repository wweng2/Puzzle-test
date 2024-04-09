/*
Name: wei zhang weng
Date: 1/28/2021
Section 5
Email: wweng2@umbc.edu

Description; This file contains the tester class that is used to test the puzzle class
*/

#include <iostream>
using namespace std;

#include "puzzle.h"
class Tester{//this is your tester class, you add your test functions in this class
public:
  bool testCopyConstructor(const Puzzle& puzzle);
  void measureInsertionTime(int numTrials, int N);  
  void measureCopyTime(int numTrials, int Size);  
  int GetSize(Puzzle& puzzle);
  bool testMakeMem( int num);
  bool testAssigmentConstructor(const Puzzle& puzzle);
  void testclear( Puzzle& puzzle);

};


bool Tester::testCopyConstructor(const Puzzle& puzzle){
  Puzzle copy(puzzle);
  //the case of empty object
  if (puzzle.m_size == 0 && copy.m_size == 0) return true;
  //the case that sizes are the same and the table pointers are not the same
  else if (puzzle.m_size == copy.m_size && puzzle.m_table != copy.m_table){
        for (int i=0;i<puzzle.m_size;i++){
          for (int j=0;j<puzzle.m_size;j++)
            {
              if ((puzzle.m_table[i][j] != copy.m_table[i][j]) || //check the value
                  (puzzle.m_table[i] == copy.m_table[i])){        //check the ith pointer
                return false;
              }
            }
        }
        return true;
  }
  //everthing else
  else return false;
}
void Tester::measureInsertionTime(int numTrials, int N)
{
    //Measuring the efficiency of insertion algorithm with system clock ticks
    //Clock ticks are units of time of a constant but system-specific length, as those returned by function clock().
    //Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
    const int a = 2;//scaling factor for input size
    double T = 0.0;//to store running times
    clock_t start, stop;//stores the clock ticks while running the program
    for (int k=0;k<numTrials-1;k++)
      {
        start = clock();
        Puzzle p1(N);//the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "Inserting " << N * N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        N = N * a;//increase the input size by the scaling factor
      }
}
 void Tester::measureCopyTime(int numTrials, int size){
   const int a = 2;
   double T = 0.0;
   clock_t start,stop;
   int i;
   
 

   for (i = 0; i < numTrials-1; i++){

     Puzzle copyTest(size);

     start = clock();
     

     Puzzle copy(copyTest);

     stop = clock();

     T = stop - start;

     cout<<" Copying "<< size * size <<" member tooked "<<T/CLOCKS_PER_SEC << " seconds "<<endl;

     size = size * a;
   }
 }
int Tester::GetSize(Puzzle& puzzle){
  return puzzle.m_size;
}
bool Tester::testMakeMem( int num){

  Puzzle test(num);
  int table_size = test.m_size;


      // if it's not 0 then it's going to test to see if there the size of the rows and columns as the num the user said
      // And m_size should be the same as num
    
      if(table_size != 0){
        int size = 0;
	
        int i = 0;
	
        for(i = 0 ; i < table_size ; i ++){
	  size ++;
        }

	if(size != num){
	  return false;
	}
	else{
	  return true;
      }
      }
      else{
	return true;
      }
    
      
}
bool Tester::testAssigmentConstructor(const Puzzle& puzzle){
  int normalnum = 10;
  Puzzle Assigmentcopy(normalnum);
  Assigmentcopy = puzzle;
  //the case of empty object
    if (puzzle.m_size == 0 && Assigmentcopy.m_size == 0) return true;
    //the case that sizes are the same and the table pointers are not the same
    else if (puzzle.m_size == Assigmentcopy.m_size && puzzle.m_table != Assigmentcopy.m_table){
      for (int i=0;i<puzzle.m_size;i++){
	for (int j=0;j<puzzle.m_size;j++)
	  {
	    if ((puzzle.m_table[i][j] != Assigmentcopy.m_table[i][j]) || //check the value
		(puzzle.m_table[i] == Assigmentcopy.m_table[i])){        //check the ith pointer
	      return false;
              }
	  }
      }
      return true;
    }
    //everthing else
    else return false;
}


void Tester::testclear(Puzzle& puzzle){
  puzzle.clear();
  
}


int main() {
  Tester tester;
  cout<<"This is a test"<<endl;
  int zero = 0;
  int negative_num = -45;
  int normalNum = 5;
  // Test cases for the alternate constructor
  {
    //Test 1, Edge case putting a negative in to see if m_size is 0

    

    cout<< "Expected output : negative number, and is turned into zero"<<endl;
    Puzzle test(negative_num);

    if(tester.GetSize(test) != 0){// TO make sure the number is turned into zero
      
      cout<<"Failed"<<endl;
    }
    else{
      cout<<"Passed"<<endl;
    }
          tester.testclear(test);

  }
  {
  //Test 2 edge casse to see if 0 would be 0 in m_size instead of anyother number
    Puzzle test(zero);

    if(tester.GetSize(test) != 0){
      cout<<"Failed"<<endl;
    }
    else{
      cout<<"Passed"<<endl;
    }

    

}
    // Teest 2, if the contructor has size working
  {
    Puzzle test(normalNum);
    if(tester.GetSize(test) != normalNum){
      cout<<"Failed"<<endl;
    }
    else{
      cout<<"Passed"<<endl;
    }

	
  }

  // makemem() testcases
  {//Testing to see if when 0 is putted in no array is made

   
    cout<<"Expexcted output: Size is zero, so no array is made"<<endl;

    tester.testMakeMem(0);

    // Testing to see if if a normal size is put in , will the contructor make an array
  
    if(tester.testMakeMem(normalNum)){
      cout<< "Passed, array is made and the columns and rows are the same size"<<endl;
    }
    else{
      cout<<"Failed"<<endl;
    }
    
  
  }
  // Assigment opertor testing
  /*  {
  //test deep copy, object with many members
  Puzzle test(normalNum);
    cout << "Test case, AssignemntConstructor: same members, same size, different pointers (deep copy):" << endl;
    if (tester.testAssigmentConstructor(test)) cout << "Assigment constructor passed!" << endl;
        else cout << "Assignemnt failed!" << endl;

	
  }
    //test the edge case, object with 1 member
  {
        cout << "\nTest case, Assginment Constructor: 1 member:" << endl;
        Puzzle test(1);
        if (tester.testAssigmentConstructor(test)) cout << "Assgiement constructor passed!" << endl;
        else cout << "Assignment constructor failed!" << endl;

	    
  }
        //test the edge case, 0 member, i.e. empty object
  {     cout << "\nTest case, Copy Constructor: zero members:" << endl;
        Puzzle test(zero);
        if (tester.testAssigmentConstructor(test)) cout << "Copy constructor passed!" << endl;
        else cout << "Assignment constructor failed!" << endl;


  }
  {     //test the user error case, creating object with table zise less than 0
      cout << "\nTest case, Assignment Constructor: table size less than 0:" << endl;
      Puzzle test(negative_num);
      if (tester.testAssigmentConstructor(test)) cout << "Assignment constructor passed!" << endl;
      else cout << "Assignemnt constructor failed!" << endl;


  }

  
    
  {
    Puzzle test(normalNum);
    
    
    
    // To check that self assigment doesn't work and that there shou;d be a quote printed to show that
    
    cout<< "Expected output:This is a self assigment and not allowed"<<endl;
    test = test;
  
	
  }
  */  
  {
        //test deep copy, object with many members
    Puzzle test(100);
    cout << "Test case, Copy Constructor: same members, same size, different pointers (deep copy):" << endl;
    if (tester.testCopyConstructor(test)) cout << "Copy constructor passed!" << endl;
        else cout << "Copy constructor failed!" << endl;

    
  }
  {
    //test the edge case, object with 1 member
        cout << "\nTest case, Copy Constructor: 1 member:" << endl;
        Puzzle test(1);
        if (tester.testCopyConstructor(test)) cout << "Copy constructor passed!" << endl;
        else cout << "Copy constructor failed!" << endl;


  }
    {
        //test the edge case, 0 member, i.e. empty object
        cout << "\nTest case, Copy Constructor: zero members:" << endl;
        Puzzle test(0);
        if (tester.testCopyConstructor(test)) cout << "Copy constructor passed!" << endl;
        else cout << "Copy constructor failed!" << endl;


    }
    {
        //test the user error case, creating object with table zise less than 0 
      cout << "\nTest case, Copy Constructor: table size less than 0:" << endl;
      Puzzle test(-10);
      if (tester.testCopyConstructor(test)) cout << "Copy constructor passed!" << endl;
      else cout << "Copy constructor failed!" << endl;


    }

    // test the copy speed
    /*
   {cout << "Measuring the efficiency of copy functionality:" << endl;
        int M = 5;//number of trials
        int N = 5;//input size
        tester.measureCopyTime(M, N);
    }
    {
      //Measuring the efficiency of insertion functionality
      cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
      int M = 5;//number of trials
      int N = 10;//original input size
      tester.measureInsertionTime(M, N);
    }
    {
            //an example of dump
      cout << "\nHere is an example of a table:" << endl;
      Puzzle test(10);
      test.dump();
      cout << endl;
      }


    {//Ccheck to see the array is empty and m_size should be 0
      Puzzle test(normalNum);

      tester.testclear(test);
      cout<<"EXpected number: 0"<<endl;
      cout<<tester.GetSize(test)<<endl;
    }
    {
      Puzzle test(0);

      // Test to check that clear doesn't clear an array with nothing in it
      tester.testclear(test);

	cout<<"Expected output, nothing to clear as the array is empty"<<endl;
    }
  */
    return 0;
}



