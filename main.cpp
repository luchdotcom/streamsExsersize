#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//print array
int printArr(int *,unsigned );

//function for array elements sum
int sumArr(int *,unsigned );
//avg of the array
double agvArr(int *,unsigned );
//min
int minArr (int*,unsigned );
//max
int maxArr (int*,unsigned );
int main( ) {
    //variable for elements count
    unsigned sz;
    //reade from file
    ifstream fin("input.txt");
    if (!fin){
        cerr<<"File input.txt couldn't be opened!\n";
        return 1;
    }
    fin>>sz;
    cout<<"number elements in the array "<<sz<<"\n";
    //array -what type of array?
    int* arr = new int[sz];
    //reade array from file input.txt
    for ( int i = 0; i < sz; ++ i ) {
        fin>>arr[i];
    }
    printArr(arr,sz);
    //char array variable first name and second name
    char firstName[15];
    char lastName[15];

    //reade name from file
    fin>>firstName>>lastName;
    fin.ignore();
    cout<<"My name is "<<firstName<<" "<<lastName<<endl;

    //one variable for where we study
    string info;
    getline(fin,info);
    cout<<"My info is :"<<info<<endl;
    //char and read it from file
    char var;
    fin>>var;
    fin.close();
    cout <<"Character is: "<<var<<endl;
    ofstream out("output.txt");
    if (!out){
        cerr<<"File output.txt couldn't not be created/opened!\n";
        return 2;
    }
    out<<"Array elements number: "<<sz<<endl;
    out <<"Array elements : ";
    out<<arr[0];
    for ( int j = 1; j < sz; ++ j ) {
        out<<" "<<arr[j];
    }
    out<<endl;
    out<<"min is: "<< minArr(arr,sz) << endl;
    out<<"Max is: "<< maxArr(arr,sz) << endl;
    out<<"Sum is: "<< sumArr(arr,sz) << endl;
    out<<"Agv is: "<< agvArr(arr,sz) << endl;
    out.close();

    fin.open("output.txt");
    if (!fin){
        cerr<<"File output.txt couldn't be opened!\n";
        return 3;
    }
    const unsigned Len=100;
    char line[Len+1];
    cout<<"============================================\n";
    cout<<"Reade file output.txt content "<<endl;
    while (fin.getline(line,Len)){
        cout<<line<<endl;
    }
    fin.close();
    cout<<"============================================\n";
    cout<<"Reade file main.cpp content "<<endl;
    fin.open("main.cpp");
    if(!fin){
        cerr<<"File main.cpp couldn't ne opened! \n"<<endl;
        return 4;
    }
    while (fin.getline(line,Len)){
        cout<<line<<endl;
    }
    fin.close();




if (arr!= nullptr){
    delete [] arr;
    arr= nullptr;
}
    return 0;
}
int printArr(int *arr,unsigned sz ){
    cout<<arr[0];
    for ( int i = 1; i < sz; ++ i ) {
        cout<<" "<<arr[i];
    }
    cout<<endl;
    return 0;
}
int sumArr(int *arr ,unsigned sz){
    int sum=0;
    for ( int i = 0; i < sz; ++ i ) {
        sum+=arr[i];
    }
    return sum;
}
double agvArr(int *arr,unsigned sz ){

    return (double )sumArr(arr,sz)/sz;

}int minArr (int*arr,unsigned sz ){
    int min=arr[0];
    for ( int i = 1; i < sz; ++ i ) {
        if(min>arr[i]){
            min=arr[i];
        }
    }
return min;
}
int maxArr (int*arr,unsigned sz){
    int max=arr[0];
    for ( int i = 1; i < sz; ++ i ) {
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}