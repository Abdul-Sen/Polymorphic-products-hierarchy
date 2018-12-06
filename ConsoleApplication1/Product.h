#pragma once
class iProduct;

class Product : public w6::iProduct
{
	long p_num;
	double p_cost;
public:
	Product(long ui_num, double ui_cost) {
		p_num = ui_num;
		p_cost = ui_cost;
	}
	double getPrice() const {
		return p_cost;
	}
	void display(std::ostream& os) const {
		os << this->p_num;
		os.width(17);
		os << this->p_cost;
	}
};