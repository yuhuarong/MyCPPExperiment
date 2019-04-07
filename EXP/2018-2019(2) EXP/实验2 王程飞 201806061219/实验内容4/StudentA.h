class StudentA{
public:
	StudentA();//考虑这里为什么不缺省无参构造?
	StudentA(char * n);
//	StudentA(const Student & stu);
//	void operator=(const Student& stu);
	char *getName();
	void changeName(char *n);
private:
	char name[20];
};
