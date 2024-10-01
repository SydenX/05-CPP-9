#ifndef PMERGE
# define PMERGE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>
#include <ctime>

class Pmerge {
	private:
		std::vector<int> _v;
		std::deque<int> _d;
		Pmerge();
		
		int isInt(std::string const &s);

		template < typename T >
		T mergeSort(T left, T right){
			T largest;
			unsigned int i = 0, j = 0;
			while(i < left.size() && j < right.size()){
				if (left[i] <= right[j]){
					largest.push_back(left[i]);
					++i;
				} else {
					largest.push_back(right[j]);
					++j;
				}
			}
			while(i < left.size())
				largest.push_back(left[i++]);
			while(j < right.size())
				largest.push_back(right[j++]);
			return largest;
		}

		template < typename T >
		T insertSort(T largest){
			for (unsigned int i = 0; i < largest.size(); i++){
				int j = i;
				int K = largest[i];
				while(j > 0 && (largest[j - 1] > K)){
					largest[j] = largest[j - 1];
					j--;
				}
				largest[j] = K;
			}
			return largest;
		}

	public:
		Pmerge(int argc, char **argv);
		~Pmerge();

		template < typename T >
		void printList(T& v){
			typename T::const_iterator it;
			for(it = v.begin(); it != v.end(); ++it){
				if (it + 1 == v.end())
					std::cout << *it << std::endl;
				else std::cout << *it << " ";
			}
		}

		template < typename T >
		T mergeInsertSort(T largest){
			if(largest.size() < 8)
				return insertSort(largest);
			T left;
			T right;
			for(unsigned int i = 0; i < largest.size(); i++){
				if (i < (largest.size() / 2))
					left.push_back(largest[i]);
				else right.push_back(largest[i]);
			}

			T sortedLeft = mergeInsertSort(left);
			T sortedRight = mergeInsertSort(right);

			return mergeSort(sortedLeft, sortedRight);
		}
};

#endif