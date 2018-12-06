#include <string>
#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"
namespace w6 {
	std::ostream & operator<<(std::ostream & os, const iProduct & p)
	{
	
			p.display(os);
			return os;
		
	}
	iProduct * readProduct(std::ifstream & ifs)
	{
		std::string line;
		iProduct* ptr;
		std::getline(ifs, line, '\n');
		long p_id = std::stol(line.substr(0, line.find(' ')));
		line = line.substr(line.substr(0, line.find(' ')).length() + 1); //Cutting until cost

		double cost = std::stod(line.substr(0, line.find(' ')));
		line = line.substr(line.substr(0, line.find(' ')).length()); //Cutting till end or tax status

		if (line.length() == 0)
		{
			
			ptr = new Product(p_id,cost);
		}
		else
		{
			const char c = line[1];
			if (c == 'H' || c == 'P')
				ptr = new TaxableProduct(p_id, cost, c);
			else
				throw "Tax Code not acceptable";
		}
		return ptr;
	}
}
