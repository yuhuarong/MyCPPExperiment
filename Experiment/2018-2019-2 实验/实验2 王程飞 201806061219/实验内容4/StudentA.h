class StudentA{
public:
	StudentA();//��������Ϊʲô��ȱʡ�޲ι���?
	StudentA(char * n);
//	StudentA(const Student & stu);
//	void operator=(const Student& stu);
	char *getName();
	void changeName(char *n);
private:
	char name[20];
};
