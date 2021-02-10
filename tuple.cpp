#include<iostream>
#include<tuple>

void main()
{
// Creating a tuple

std::tuple<int, char> foo (20,'g); // Constructor
auto bar = std::make_tuple("Test", 3.1, 100, 'b'); // Make Tuple

std::string s;
double d;

std::tie(s,d,std::ignore,std::ignore) = bar;

// Checking tie
std::cout<<"Tie is for extracting the tuple\n";
std::cout<<" String "<<s<<" Double "<<d<<"\n";
std::cout<<" While extracting the elements using tie, std::ignore is used to fill out elements when you don't need it. \n";

auto a = std::get<2> bar;
set::get<3> bar = 150; // Returns by reference.

// decltype vs typeid. compile vs runtime.
// Tuple Size -> std::tuple_size<decltype(bar)>::value;

// Single element extraction --> std::tuple_element<0,decltype(bar)>::type a = std::get<0>(bar);

// Concatinating tuples
auto tupl1 = std::tuple_cat(tuple1, std::make_tuple<int, char>(pair1));



}
