#include<iostream>
#include<conio.h>
#include<vector>

/*
	Counting-Sort
	
	Requires extra space [two vectors allocated, for keeping count (counter) and for sorted output (out)]

	Counting_Sort(array,maxval){
		loop...and set counter to zero, each maxval places.

		loop...over array(i=0){
			count[array[i]]++;
		}
		loop...over count(j=1){
			count[j]=count[j]+count[j-1];
		}
		loop...over array(i=array.length-1){
			out[count[array[i]]]=array[i];
			count[array[i]]--
		}
	}

*/
class Container {
private:
	std::vector<int> container;
	int maxvalue;
	std::vector<int> counter;
	
	int size = container.size();
public:
	Container(std::vector<int> vec, int val) :container{ vec }, maxvalue{ val } {};
	
	std::vector<int> sorted_con;

	void Countingsort(std::vector<int>& vec);
	
	void setnull();
};

int main() {
	int count;
	int value;
	int highestnum;
	std::vector<int> vec;
	std::cout << "Enter count of numbers you want to sort : ";
	std::cin >> count;
	std::cout << "Enter the highest number in the array : ";
	std::cin >> highestnum;
	std::cout << "\n\nEnter list of numbers to be sorted : Algorithm - Heapsort Ascending "<<std::endl;
	for (int i = 0; i < count; i++) {
		std::cin >> value;
		vec.push_back(value);
	}
	std::cout << "\n\n";
	Container* data = new Container(vec, highestnum); //Calling the constructor of the class
	data->Countingsort(vec);	//Call to the Sorting function
	for (int i = 0; i < count;i++) {
		std::cout << data->sorted_con[i] << " ";
	}
	data->~Container();
	_getch();
}

void Container::Countingsort(std::vector<int>& vec){
	
		//loop...and set counter to zero, each maxval places.
		setnull();

		//	loop...over array(i = 0) {
		//	count[array[i]]++;
		//}
		for (int i = 0; i < size; i++) {
			counter[vec[i]]++;
		}
		//loop...over count(j = 1) {
		//	count[j] = count[j] + count[j - 1];
		//}
		for (int i = 1; i <= maxvalue; i++) {
			counter[i] = counter[i] + counter[i - 1];
		}
		//loop...over array(i = array.length - 1) {
		//	out[count[array[i]]] = array[i];
		//	count[array[i]]--
		//}
		for (int i = size-1; i >= 0; i--) {
			sorted_con[counter[vec[i]] - 1] = vec[i];
			counter[vec[i]]--;
		}
	
}

void Container::setnull(){
	for (int i = 0; i <= maxvalue; i++) {
			counter.push_back(0);
		}
	for (int i = 0; i < size; i++) {
			sorted_con.push_back(0);

	}
}
