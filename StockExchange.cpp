#include "lab.h"
StockExchange::StockExchange(int size)
{
	_seller = new MinHeap<Order>(size);
	_buyer = new MaxHeap<Order>(size);
	_size = size;
	_total = 0;
}

StockExchange::~StockExchange(void)
{
	delete _seller;
	delete _buyer;
}

bool	StockExchange::peekSeller(Order &item)
{
	if (_seller->peek(item))
		return true;
	else
		return false;
}
bool	StockExchange::peekBuyer(Order &item)
{
	if (_buyer->peek(item))
		return true;
	else
		return false;
}
//We created the populate function to randomly fill the heaps with data
void	StockExchange::populate(std::string symbol)
{
	for (int i = 0; i < _size; i++)
	{
		_buyer->insert(Order("Buyer", symbol, BUY, rand() % 3000,
					  static_cast<double>(rand() % 10000) / 100));
		_seller->insert(Order("Seller", symbol, SELL, rand() % 3000,
					  static_cast<double>(rand() % 10000) / 100));
	}
}
bool	StockExchange::saveSeller(std::string file)
{
	std::fstream	f(file.c_str());
	Order	tmp;

	if (!f)
		return false;
	f << _seller->getnNodes() << std::endl;
	while (_seller->remove(tmp))
	{
		f <<
		tmp.getCustomer() << "\t" <<
		tmp.getSymbol() << "\t" <<
		(tmp.getIndicator()) ? "SELL\t" : "BUY\t";
		f << tmp.getShare();
		f << "\t";
		f << tmp.getPrice() << std::endl;
	}
	return true;
}

bool	StockExchange::saveBuyer(std::string file)
{
	std::fstream	f(file.c_str());
	Order	tmp;

	if (!f)
		return false;
	f << _buyer->getSize() << std::endl;
	while (_buyer->remove(tmp))
	{
		f <<
		tmp.getCustomer() << "\t" <<
		tmp.getSymbol() << "\t" <<
		(tmp.getIndicator()) ? "SELL\t" : "BUY\t";
		f << tmp.getShare();
		f << "\t";
		f << tmp.getPrice() << std::endl;
	}
	return true;
}

bool	StockExchange::loadSeller(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;
	int	size;
	f >> size;
	if (!(_seller = new MinHeap<Order> (size)))
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_seller->insert(Order(name, symbol, ind, share, price));
	}
}

bool	StockExchange::loadBuyer(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;
	int	size;
	f >> size;
	if (!(_buyer = new MaxHeap<Order> (size)))
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_buyer->insert(Order(name, symbol, ind, share, price));
	}
}

bool	StockExchange::saveLog(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;

	for (size_t i = 0; i < _log.size(); i++)
	{
		f <<
		_log[i].getName() << "\t" <<
		_log[i].getSymbol() << "\t" <<
		(_log[i].getIndicator() == SELL) ? "SELL\t" : "BUY\t";
		f << _log[i].getShare();
		f << "\t" <<
		_log[i].getPrice() << "\t" << std::endl;
	}
}

bool	StockExchange::loadLog(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_log.push_back(Log(name, symbol, ind, share, price));
		_total += price;
	}
	return true;
}

