#include<iostream>
int main(){
	
	int y;
	std::cout<<"Enter a year"<<std::endl;
	std::cin>>y;
	
	if(y%4==0 && y%100 != 0 || y%400==0 )
		std::cout<<"Leap";
	else
		std::cout<<"Not a Leap year";
	
	return 0;
}