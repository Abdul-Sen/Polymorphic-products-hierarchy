 // Workshop 6 - STL Containers
 // w6.cpp

 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include "iProduct.h"

 int main(int argc, char** argv) {

	 std::ofstream ofs("Lab6Output.txt");

     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 2) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }
     std::ifstream productList(argv[1]);
     if (!productList) {
         std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
         return 2;
     }
     ofs << std::fixed << std::setprecision(2);

	//Add your code here
	 std::vector<w6::iProduct*> vec_iProduct;
	 while (!productList.eof())
	 {
		 vec_iProduct.push_back(w6::readProduct(productList));
	 }
	 std::vector<w6::iProduct*>::iterator i;
	 double total = 0;

	 ofs << "Product No\tPrice Taxable\n";
	 for (i = vec_iProduct.begin(); i != vec_iProduct.end(); i++) //Or use auto range-based loop if your feeling heroic since its shorter
	 {
		 (*i)->display(ofs);
		 ofs << std::endl;
		 total +=(*i)->getPrice();
	 }
	 ofs << "\nTotal:\t\t" << total;



     std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
     std::cin.get();

	 ofs.close();
 }

