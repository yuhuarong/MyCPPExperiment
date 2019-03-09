class Pool{
	public:
		void init(double, double);
		void toString();
		double getPrice(); 
		
	private:
		const double pRoad=167.5;
		const double pR=36.4;
		double r;//°ë¾¶ 
		double roadWidth;//×ßµÀ¿í
		double getRoadPrice();
		double getRPrice();
};
