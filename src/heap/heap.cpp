#include <algorithm>
#include <iostream>
#include <vector>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>

//https://www.youtube.com/watch?v=t0Cq6tVNRBA
template
<typename T>
class heap
{
private:
	size_t IntegerLogarithm2(size_t arg) {
		size_t logarithm = 0;
		while (arg >>= 1) ++logarithm;
		return logarithm;
	}

	// will be used to compute number of elements at the level i
	size_t IntegerPower2(size_t arg) {
		if (arg)
			return (size_t)2 << (arg - 1);
		else
			return 1;
	}

	// returns total line length for the level
	size_t LineLength(size_t level, size_t item_width, size_t spaces_between) {
		return IntegerPower2(level) * (item_width + spaces_between) - spaces_between;
	}

	std::string do_padding(size_t index, size_t mlength) {
		std::string padding;
		if (int((index - 1) / 2) != 0) {
			return (int((index - 1) / 2) % 2 == 0) ?
				(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
				(do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
		}
		return padding;
	}

	void printer(std::vector<int> const& tree, size_t index, size_t mlength) {
		auto last = tree.size() - 1;
		auto  left = 2 * index + 1;
		auto  right = 2 * index + 2;
		std::cout << " " << tree[index] << " ";
		if (left <= last) {
			auto llength = std::to_string(tree[left]).size();
			std::cout << "---" << std::string(mlength - llength, '-');
			printer(tree, left, mlength);
			if (right <= last) {
				auto rlength = std::to_string(tree[right]).size();
				std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
				std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " L" <<
					std::string(mlength - rlength, '-');
				printer(tree, right, mlength);
			}
		}
	}


public:
    std::vector<T> heap_data;
    void creatHeap(T * data, size_t n)
    {
        heap_data.reserve(n);
        for (size_t i = 0; i < n; i++) 
        {
            insetElement(data[i]);
        }
    }

    void insetElement(T element)
    {
        
        heap_data.push_back(element);
        size_t element_index=heap_data.size()-1;

        size_t parent_index = element_index / 2;
        while (heap_data[parent_index] < heap_data[element_index])
        {
            std::swap(heap_data[parent_index] , heap_data[element_index]);
            element_index = parent_index;
            parent_index = element_index / 2;
        }
    }

    void deleteTopElement()
    {
		//heap_data.erase[heap_data.begin()];
		std::swap(heap_data[0], heap_data[heap_data.size() - 1]);
		heap_data.pop_back();
		size_t left_child_index, right_child_index, max_child_element_index;
		size_t element_index = 0;
		left_child_index= 2* element_index+1;
		right_child_index= 2* element_index+2;

		T max_child = std::max(heap_data[left_child_index], heap_data[right_child_index]);


		if (max_child==heap_data[right_child_index])
			max_child_element_index = right_child_index;
		else
			max_child_element_index = left_child_index;
		
		while (max_child> heap_data[element_index])
		{
			std::swap(heap_data[element_index], heap_data[max_child_element_index]);

			element_index = max_child_element_index;
			left_child_index = 2 * element_index + 1;
			right_child_index = 2 * element_index + 2;

			if (left_child_index < heap_data.size() && right_child_index < heap_data.size()) 
			{
				max_child = std::max(heap_data[left_child_index], heap_data[right_child_index]);
				if (max_child == heap_data[right_child_index])
					max_child_element_index = right_child_index;
				else
					max_child_element_index = left_child_index;
			}
			else
				break;

		}
    }
	
	//credit https://stackoverflow.com/questions/20922755/print-heap-array-in-tree-format
    int display() 
    {
		std::vector<std::vector<int> > levels;

		// Height of the heap
		size_t levels_number = IntegerLogarithm2(heap_data.size() + 1);
		levels.resize(levels_number);

		// Now fill the levels
		for (size_t i = 0; i < levels.size(); ++i) {
			size_t elements_number = IntegerPower2(i);
			levels[i].resize(elements_number);
			for (size_t j = elements_number - 1, p = 0; p < elements_number; ++j, ++p)
				levels[i][p] = heap_data[j];
		}

		if (levels_number < 1) return 0;

		int magnitude = (abs(heap_data[0]) <= 1 ? 1 : abs(heap_data[0]));
		size_t tab_width = (size_t)floor(log(double(magnitude)) / log(10.0)) + 1;
		// size_t longest_line = LineLength(levels_number - 1, tab_width, tab_width);
		std::vector<std::string> text;
		text.reserve(levels_number * 2 - 1);

		// Do the aligned output to the strings array
		for (size_t i = 0; i < levels_number; ++i) {
			size_t outer_space_width = IntegerPower2(levels_number - 1 - i) - 1;
			size_t inner_space_width = outer_space_width * 2 + 1;
			std::string outer_space(outer_space_width * tab_width, ' ');
			std::string inner_space(inner_space_width * tab_width, ' ');

			std::ostringstream line;
			line << outer_space;

			if (i > 0) {
				std::ostringstream branchline;
				std::string joint(tab_width, '|');
				std::string branch(inner_space_width * tab_width, '-');

				branchline << outer_space;

				if (levels[i].size() > 0) {
					branchline << joint;
				}

				bool isline = true;
				for (size_t j = 1; j < levels[i].size(); ++j, isline = !isline) {
					if (isline)
						branchline << branch << joint;
					else
						branchline << inner_space << std::setfill(' ') <<
						std::setw(tab_width) << joint;
				}

				branchline << outer_space;
				text.push_back(branchline.str());
			}

			if (levels[i].size() > 0) {
				line << std::setfill(' ') << std::setw(tab_width) << levels[i][0];
			}

			for (size_t j = 1; j < levels[i].size(); ++j) {
				line << inner_space << std::setfill(' ') <<
					std::setw(tab_width) << levels[i][j];
			}

			line << outer_space;
			text.push_back(line.str());
		}

		// Output the text
		for (auto& i : text)
			std::cout << i << std::endl;


        /*for(T i:heap_data)
            std::cout<<i << " ";*/
    }
	
	void printTree() {
		size_t mlength = 0;
		for (int& element : heap_data) {
			auto clength = std::to_string(element).size();
			if (clength > mlength) {
				mlength = std::to_string(element).size();
			}
		}
		std::cout << std::string(mlength - std::to_string(heap_data[0]).size(), ' ');
		printer(heap_data, 0, mlength);
		std::cout << "\n";
	}

	void printElements() 
	{
		for (T i : heap_data)
			std::cout << i << " ";
		std::cout << "\n";
	}

};

void stdHeap()
{


    std::vector<int> v={ 6, 6, 8, 2, 10, 0, 2, 2, 1, 0 };


    std::cout << "initially, v: ";
    for (auto i : v) 
		std::cout << i << ' ';
	std::cout << '\n';

    if (!std::is_heap(v.begin(), v.end()))
    {
        std::cout << "making heap...\n";
        std::make_heap(v.begin(), v.end());
    }

    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

    std::cout << "The maximum element of heap is : ";
    std::cout << v.front() << std::endl;





    //Adding a new element
    v.push_back(9);
    std::cout<< (std::is_heap(v.begin(),v.end()) ? "it is a heap" : "it is not a heap" )   <<std::endl;
    std::push_heap(v.begin(),v.end());
    std::cout<< (std::is_heap(v.begin(),v.end()) ? "it is a heap" : "it is not a heap" )   <<std::endl;


	//Adding a new element
	v.push_back(15);
	std::cout << (std::is_heap(v.begin(), v.end()) ? "it is a heap" : "it is not a heap") << std::endl;
	std::push_heap(v.begin(), v.end());
	std::cout << (std::is_heap(v.begin(), v.end()) ? "it is a heap" : "it is not a heap") << std::endl;

    //sorting a heap -> it only works on a heap, so you should first turn your vetor into a heap
    std::sort_heap(v.begin(),v.end());


	//remove the largest element
	std::pop_heap(v.begin(), v.end());
	v.pop_back();
}



int main()
{
    std::vector<int> data = { 6, 8, 2, 10, 0, 2, 2, 1, 0 };

	std::cout << "Input data:" << "\n";
	for (auto i : data)
		std::cout << i << " ";
	std::cout << "\n";

    heap<int> max_heap;
    max_heap.creatHeap(&data[0], data.size());
	std::cout << "created heap:" << "\n";
	max_heap.printElements();
	std::cout << "heap tree:" << "\n";
    max_heap.printTree();
	

	std::cout <<"\n";
	std::cout << "inserting 9 into the heap:" << "\n";
	max_heap.insetElement(9);
	std::cout << "heap data:" << "\n";
	max_heap.printElements();
	max_heap.printTree();

	std::cout << "\n";
	std::cout << "inserting 15 into the heap:" << "\n";
	max_heap.insetElement(15);
	std::cout << "heap data:" << "\n";
	max_heap.printElements();
	max_heap.printTree();

	std::cout << "\n";
	std::cout << "deleting top element from heap:" << "\n";
	max_heap.deleteTopElement();
	std::cout << "heap data:" << "\n";
	max_heap.printElements();
	max_heap.printTree();


	stdHeap();

    
}
