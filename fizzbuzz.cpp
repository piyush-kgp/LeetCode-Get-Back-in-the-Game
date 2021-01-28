#include <iostream>
#include <string>
using namespace std;

// Baseline
void good(){
	for (int i=1; i<=100; i++){
		if (i%15==0) cout << "fizzbuzz" << endl;
		else if (i%5==0) cout << "buzz" << endl;
		else if (i%3==0) cout << "fizz" << endl;
		else cout << i << endl;	
	}
}

// Better
void better(){
	for (int i=1; i<=100; i++){
		string s="";
		bool b = 0;
		if (i%3==0) {b=1; s+= "fizz";} 
		if (i%5==0) {b=1; s+= "buzz";}
		// if (s.length()==0) cout << i << endl;
		// else cout << s << endl;
		if (b) cout << s << endl;
		else cout << i << endl;
	}
}

// Best
void best(){
	int c3=0, c5=0;
	for (int i=1; i<=100; i++){
		c3++; c5++;
		string s="";
		bool b=0;
		if (c3==3){s+="fizz"; c3=0; b=1;}
		if (c5==5){s+="buzz"; c5=0; b=1;}
		if (b) cout << s << endl;
		else cout << i << endl;
	}
}

int main(){
	cout << "Baseline Solution:" << endl;
	good();
	cout << "Better Solution:" << endl;
	better();
	cout << "Best Solution:" << endl;
	best();
	return 0;
}	
