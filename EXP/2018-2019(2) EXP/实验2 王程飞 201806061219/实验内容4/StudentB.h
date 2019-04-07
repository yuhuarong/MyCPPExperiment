class StudentB {
public:
	StudentB();
	StudentB(const char n[]);
	StudentB(const StudentB& stu);
	void operator=(const StudentB& stu);
	~StudentB();
	char *getName() const;
	void changeName(const char n[]);
private:
	char *name;
};
