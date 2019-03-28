#include<iostream>
#include<unordered_map>
#include<map>	//	Include if you want a proper map

using namespace std;

int main()
{
	unordered_map<string,int> m;
	
	// Insert
	m["mango"]=100;
	
	// Second Way
	m.insert(make_pair("apple",120));
	
	// Search
	if(m.count("apple")==1)
	cout<<"Price of apple is "<<m["apple"]<<endl;
	
	if(m.count("guava")==0)
	cout<<"Guava does not exits"<<endl;
	
	
	m["guava"] = m["apple"] + m["mango"];
	if(m.count("guava")==1)
	cout<<"Price of guava is "<<m["guava"]<<endl;
	
	// Iterators to search
	auto f= m.find("mango");
	if(f!=m.end());
	cout<<"price of mango is "<<f->second<<endl;
	
	// For deletion we have erase function
	
	m.erase("mango");
	f= m.find("mango");
	if(f==m.end())
	cout<<"mango does not exist"<<endl;
	
	return 0;
}
