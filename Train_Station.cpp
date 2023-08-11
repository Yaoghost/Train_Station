#include <iostream>   // direct the compiler to include functions required for input output

using namespace std;  // this is a default namespace to be used

int main()   // this is our main function
{
    int size=99999;  // declare a variable to hold array size 
    cout<<"Please enter number of hour intervals: ";   // ask user for number of hour intervals 
    cin>>size;   // stores user input into variable size
    float arr[size],dep[size];  // create arrays to hold arrivals and departures 
    
    cout<<"Please enter arrival and depature times in order: "<<endl;   // ask user for input 
   
     for(int i=0;i<size;i++) 
    {
      cout<<"Arrival: ";  // which element is taken 
      cin>>arr[i];      // stores user input into corresponding index in array of arrivals 
      cout<<"Departure: ";  // which element is taken 
      cin>>dep[i]; //  stores user input into corresponding index in array of departures
    }
    
    int count;   // declare a variable to keep track of number of overlap
    int check_overl[size];  // create an array to hold corresponding overlap for each interval
    
    for(int i=0;i<size;i++)
    {   
        count=1;   // initialize count to 1 each time the outer loop iterates 
        for(int j=i+1;j<size;j++)  // starts from next element to check
        {  
            
            if(arr[j]<dep[i])  // if next arrival time is less than previous departure time it is an  overlap
            {
                count++;  // increment variable count by one 
            }
          
                
        }
         check_overl[i]=count;  // stores count into corresponding index in array check_overlap
      }
  
  int max=-9999;    // declare a very small variable to be maximum count 
  for(int i=0;i<size;i++)
  { 
        if(check_overl[i]>max)  // if count is greater than current max then max becomes count 
        {
            max=check_overl[i];
            
        }
   }
 cout<<"The minimum number of platforms is "<<max;   // prints out the result 
      return 0; // our main function requires an integer return value
}
