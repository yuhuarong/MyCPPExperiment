class Pool{
	public:
		Pool(double, double);
		void toString();
		double getPrice();
		~Pool(); 
		
		
	private:
		const double pRoad=167.5;
		const double pR=36.4;
		double r;//�뾶 
		double roadWidth;//�ߵ���
		double getRoadPrice();
		double getRPrice();
};
