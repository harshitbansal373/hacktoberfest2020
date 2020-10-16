#include <iostream>
using namespace std;

int main() {


	int a = 1;

	while(a <= 10){

		// controlflow agar looping berhenti di looping ke-
		if(a > 5)
			break;
			cout << "%i" << a << endl;
			a++;
	}

	cin.get();
	return 0;
}
