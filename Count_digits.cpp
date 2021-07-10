#include<iostream>
int main(){
	int n,s=0,temp,c=0,r;
	std::cout<<"Enter an integer"<<std::endl;
	std::cin>>n;
	temp=n;
	while(n!=0){
		n/=10;
		c+=1;
	}
	std::cout<<"Count is "<<c;
	return 0;
}