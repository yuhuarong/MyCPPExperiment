class Circum{
	public:
		void setMode(int max,int min);
		void setMode();
		
		void init(int now);
		void init();
		
		int next();
		int last();
		int next(int);
		int last(int);
		
		void toString();
		int getNow() const;
		
	private:
		int min;
		int max;
		int now;
};
