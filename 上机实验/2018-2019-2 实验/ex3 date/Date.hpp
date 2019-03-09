/*
日期类(Date)，包含年月日的信息
1）日期信息设置
2）显示日期
3）计算该日是星期几
4）提供该月的月历显示
5）计算与其他日期相差几天
设计一个主函数演示这个类的操作
思考：你设计的类还有什么不足之处？ -->不如Java 
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
