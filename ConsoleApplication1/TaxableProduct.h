#pragma once
class Product;

class TaxableProduct : public Product {
	char tax_status;
	enum tax_codes {HST = 13, PST = 8};

public:
	TaxableProduct(long ui_num, double ui_cost, char ui_tax) : Product(ui_num, ui_cost)
	{
		tax_status = ui_tax;
	}

	double getPrice() const {
		return Product::getPrice() * ( ((double)tax_codes::HST/100) +1);
	}

	void display(std::ostream& os) const {
		Product::display(os);
		if (tax_status == 'H')
			os << " HST";
		else
		{
			os << " PST";
		}
	}

};