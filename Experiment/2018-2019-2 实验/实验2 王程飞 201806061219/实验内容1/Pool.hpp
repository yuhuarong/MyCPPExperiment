class Pool{
	public:
		Pool(double, double);
		void toString();
		double getPrice();
		~Pool(); 
		
		
	private:
		const double pRoad=167.5;
		const double pR=36.4;
		double r;//°ë¾¶ 
		double roadWidth;//×ßµÀ¿í
		double getRoadPrice();
		double getRPrice();
};
