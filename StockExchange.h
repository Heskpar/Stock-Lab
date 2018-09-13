#ifndef STOCK_EXCHANGE_H
# define STOCK_EXCHANGE_H

class	StockExchange
{
	public:
		StockExchange(void) {}
		StockExchange(int size);
		~StockExchange(void);

		void	populate(std::string symbol);
		bool	saveSeller(std::string file);
		bool	saveBuyer(std::string file);
		bool	loadSeller(std::string file);
		bool	loadBuyer(std::string file);

		bool	saveLog(std::string file);
		bool	loadLog(std::string file);

		int		getSize(void) { return _size; }
		double	getTotal(void) { return _total; }
		void	setTotal(double total) { _total = total; }
		void	addTotal(double price) { _total += price; }
		void	subTotal(double price) { _total -= price; }

		int		getSellernNodes(void) { return _seller->getnNodes(); }
		bool	insertSeller(Order item) { return _seller->insert(item); }
		bool	removeSeller(Order &item) { return _seller->remove(item); }
		bool	peekSeller(Order &item);

		int		getBuyernNodes(void) { return _buyer->getnNodes(); }
		bool	insertBuyer(Order item) { return _buyer->insert(item); }
		bool	removeBuyer(Order &item) { return _buyer->remove(item); }
		bool	peekBuyer(Order &item);

	private:
		MinHeap<Order>		*_seller;
		MaxHeap<Order>		*_buyer;
		std::vector<Log>	_log;
		int					_size;
		double				_total;
};

#endif
