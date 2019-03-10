class Clock{
	public:
		double diff(const Clock &clock);
		void init(int, int, int);
		void init();
		void toString();
	private:
		int h;
		int m;
		int s;
		long normlize() const;
};
