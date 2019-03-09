/*
������(Date)�����������յ���Ϣ
1��������Ϣ����
2����ʾ����
3��������������ڼ�
4���ṩ���µ�������ʾ
5��������������������
���һ����������ʾ�����Ĳ���
˼��������Ƶ��໹��ʲô����֮���� -->����Java 
*/

class Date{
	public:
		void init();
		void init(int, int, int);
		void toString();
		int diff(const Date& date);
		void showMonthTable();
		
		void setYear(int);
		void setMonth(int);
		int setDay(int);
		
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getWeek() const;
		
	private:
		int year;
		int month;
		int day;
		
		int isLeap();
		
		Date next(const Date&);
		
}; 
