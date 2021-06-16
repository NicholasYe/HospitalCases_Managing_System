#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int Max = 1000;	//医院住院最大人数

//病历信息
class Patient_Cases_Database
{
public:
	string Name;		//患者姓名
	int Gender = 1;		//患者性别(默认为男)
	int Age = 0;		//患者年龄
	string Phone;		//患者电话号码
	string Location;	//患者病床
	string Sympyom;		//患者症状
};

//医院病历库
class Hospital_Cases
{
public:
	Patient_Cases_Database Patient_case[Max];		//医院病历库数组
	int Cases_Count = 0;							//医院病历库中病历的个数
};

//检测患者是否存在
int Test_Cases(Hospital_Cases* your_case, string name);

//将患者信息存在本地
void Write_Cases(Hospital_Cases* your_case);

//添加患者病历
void Add_Cases(Hospital_Cases* your_case);

//显示患者病历
void Show_Cases(Hospital_Cases* your_case);

//删除患者病历
void Delete_Cases(Hospital_Cases* your_case);

//查找患者
void Find_Cases(Hospital_Cases* your_case);

//修改患者信息
void Change_Cases(Hospital_Cases* your_case);

//清空患者
void Clear(Hospital_Cases* your_case);

//添加患者病历
void Add_Cases(Hospital_Cases* your_case)
{
	//判断病例库是否已满
	if (your_case->Cases_Count == Max)
	{
		cout << "病历库已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入患者姓名： " << endl;
		cin >> name;
		your_case->Patient_case[your_case->Cases_Count].Name = name;

		//性别
		int gender;
		cout << "请输入患者性别： " << endl;
		cout << "1 ---- 男 " << endl;
		cout << "2 ---- 女 " << endl;

		//判断是否正确输入，正确则记录，否则重新输入
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				your_case->Patient_case[your_case->Cases_Count].Gender = gender;
				break;
			}
			cout << "输入有误请重新输入！" << endl;
		}

		//年龄
		int age;
		cout << "请输入患者年龄： " << endl;
		cin >> age;
		your_case->Patient_case[your_case->Cases_Count].Age = age;

		//电话
		string phone;
		cout << "请输入患者电话： " << endl;
		cin >> phone;
		your_case->Patient_case[your_case->Cases_Count].Phone = phone;

		//病房
		string location;
		cout << "请输入患者病房： " << endl;
		cin >> location;
		your_case->Patient_case[your_case->Cases_Count].Location = location;

		//症状
		string sympyom;
		cout << "请输入患者症状：" << endl;
		cin >> sympyom;
		your_case->Patient_case[your_case->Cases_Count].Sympyom = sympyom;

		//个数加一
		your_case->Cases_Count += 1;
		cout << "添加成功！" << endl;
		system("pause");
		//清屏
		system("cls");
	}
}

//显示患者病历
void Show_Cases(Hospital_Cases* your_case)
{
	//判断有无患者
	if (your_case->Cases_Count == 0)
	{
		cout << "暂无患者，请先添加患者病历!" << endl;
	}
	else
	{
		//显示所有患者
		for (int i = 0; i < your_case->Cases_Count; i++)
		{
			cout << "患者姓名：" << your_case->Patient_case[i].Name;
			cout << " 患者性别：" << (your_case->Patient_case[i].Gender != 2 ? "男" : "女");
			cout << " 患者年龄：" << your_case->Patient_case[i].Age;
			cout << " 患者电话：" << your_case->Patient_case[i].Phone;
			cout << " 患者病房：" << your_case->Patient_case[i].Location;
			cout << " 患者症状：" << your_case->Patient_case[i].Sympyom;
			cout << endl;
		}
		Write_Cases(your_case);
	}

	system("pause");
	system("cls");
}

//删除患者病历
void Delete_Cases(Hospital_Cases* your_case)
{
	//判断有无患者
	if (your_case->Cases_Count == 0)
	{
		cout << "暂无患者，请先添加患者病历!" << endl;
	}
	else
	{
		//记录用户输入的患者姓名
		string name;
		cout << "请输入您要删除的患者姓名：" << endl;
		cin >> name;
		//判断患者是否存在
		int index = Test_Cases(your_case, name);
		//存在
		if (index > -1)
		{
			for (int i = index; i < your_case->Cases_Count - 1; i++)
			{
				//往前移位操作
				Patient_Cases_Database temp = your_case->Patient_case[i];
				your_case->Patient_case[i] = your_case->Patient_case[i + 1];
				your_case->Patient_case[i + 1] = temp;
			}
			//减少一个记录
			your_case->Cases_Count--;

			cout << "删除成功！" << endl;

			//更改本地文档
			Write_Cases(your_case);
		}
		else//不存在
		{
			cout << "未查到此患者，请确认后重新输入!" << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找患者
void Find_Cases(Hospital_Cases* your_case)
{
	//判断有无患者
	if (your_case->Cases_Count == 0)
	{
		cout << "暂无患者，请先添加患者病历!" << endl;
	}
	else
	{
		//记录用户输入的患者姓名
		string name;
		cout << "请输入您要查找的患者姓名" << endl;
		cin >> name;
		//判断患者是否存在
		int index = Test_Cases(your_case, name);
		if (index > -1)
		{
			//存在
			cout << " 患者姓名：" << your_case->Patient_case[index].Name << endl;
			cout << " 患者性别：" << your_case->Patient_case[index].Gender << endl;
			cout << " 患者年龄：" << your_case->Patient_case[index].Age << endl;
			cout << " 患者电话：" << your_case->Patient_case[index].Phone << endl;
			cout << " 患者病房：" << your_case->Patient_case[index].Location << endl;
			cout << " 患者症状：" << your_case->Patient_case[index].Sympyom << endl;
		}
		else
		{
			//不存在
			cout << "未查到该患者信息！" << endl;
		}
	}

	system("pause");
	system("cls");
}

//修改患者信息
void Change_Cases(Hospital_Cases* your_case)
{
	//判断有无患者
	if (your_case->Cases_Count == 0)
	{
		cout << "暂无患者，请先添加患者病历!" << endl;
	}
	else
	{
		//记录用户输入的患者姓名
		string name;
		cout << "请输入您要修改的患者姓名" << endl;
		cin >> name;
		//判断患者是否存在
		int index = Test_Cases(your_case, name);
		//存在
		if (index > -1)
		{
			//姓名
			string name;
			cout << "请输入修改后的姓名： " << endl;
			cin >> name;
			your_case->Patient_case[index].Name = name;

			//性别
			int gender;
			cout << "请输入修改后的性别： " << endl;
			cout << "1 ---- 男 " << endl;
			cout << "2 ---- 女 " << endl;

			while (true)
			{
				cin >> gender;
				if (gender == 1 || gender == 2)
				{
					your_case->Patient_case[index].Gender = gender;
					break;
				}
				cout << "输入有误请重新输入！" << endl;
			}

			//年龄
			int age;
			cout << "请输入修改后的年龄： " << endl;
			cin >> age;
			your_case->Patient_case[index].Age = age;

			//电话
			string phone;
			cout << "请输入修改后的电话： " << endl;
			cin >> phone;
			your_case->Patient_case[index].Phone = phone;

			//病房
			string location;
			cout << "请输入修改后的病房： " << endl;
			cin >> location;
			your_case->Patient_case[index].Location = location;
			cout << "修改成功!" << endl;

			//症状
			string sympyom;
			cout << " 请输入修改后的症状：" << endl;
			cin >> sympyom;
			your_case->Patient_case[index].Sympyom = sympyom;

			//更改本地文档
			Write_Cases(your_case);
		}
		else
		{
			//不存在
			cout << "未查到此患者，请确认后重新输入!" << endl;
		}
	}

	system("pause");
	system("cls");
}


//清空患者
void Clear(Hospital_Cases* your_case)
{
	string choose = "N";
	cout << "您确定要清空病例库吗？(Y 确认/N 取消)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "输入有误请重新输入!!" << endl;
		}
	}

	if (choose == "Y")
	{
		your_case->Cases_Count = 0;
		cout << "清空成功!!" << endl;

		//清空E盘中data.txt文件
		ofstream Delete;
		Delete.open("E:\\data.txt");
		Delete.close();
	}
	else
	{
		cout << "清空操作已取消!!" << endl;
	}

	system("pause");
	system("cls");
}

//检测患者是否存在
int Test_Cases(Hospital_Cases* your_case, string name)
{
	for (int i = 0; i < your_case->Cases_Count; i++)
	{
		if (your_case->Patient_case[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}

//将患者信息存在本地
void Write_Cases(Hospital_Cases* your_case)
{
	//在data.txt中写入所有的患者
	ofstream Write;
	//在E盘中自动生成data.txt文件储存患者信息
	Write.open("E:\\data.txt");
	for (int i = 0; i < your_case->Cases_Count; i++)
	{
		Write << " 患者姓名：" << your_case->Patient_case[i].Name;
		Write << " 患者性别：" << (your_case->Patient_case[i].Gender != 2 ? "男" : "女");
		Write << " 患者年龄：" << your_case->Patient_case[i].Age;
		Write << " 患者电话：" << your_case->Patient_case[i].Phone;
		Write << " 患者病房：" << your_case->Patient_case[i].Location;
		Write << " 患者症状：" << your_case->Patient_case[i].Sympyom;
		Write << endl;
	}
	Write.close();
}

//显示主菜单
void Show_Menu()
{
	cout << "医院病历管理系统" << endl;
	cout << "1、添加患者信息" << endl;
	cout << "2、显示患者信息" << endl;
	cout << "3、删除患者信息" << endl;
	cout << "4、查找患者信息" << endl;
	cout << "5、修改患者信息" << endl;
	cout << "6、清空患者信息" << endl;
	cout << "0、退出病历管理系统" << endl;
	cout << "______________________________________________________________________________" << endl;
	cout << "______________________________________________________________________________" << endl;
}

int main()
{
	//记录用户输入的信息
	int select = 0;
	//定义一个病例库类
	Hospital_Cases your_Case;
	//设置当前人数为零
	your_Case.Cases_Count = 0;

	while (true)
	{
		//显示主菜单
		Show_Menu();

		cin >> select;
		switch (select)
		{
		case 1://添加患者信息
			Add_Cases(&your_Case);
			break;
		case 2://显示患者信息
			Show_Cases(&your_Case);
			break;
		case 3://删除患者信息
			Delete_Cases(&your_Case);
			break;
		case 4://查找患者信息
			Find_Cases(&your_Case);
			break;
		case 5://修改患者信息
			Change_Cases(&your_Case);
			break;
		case 6://清空患者信息
			Clear(&your_Case);
			break;
		case 0://退出病历管理系统
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");//按任意键继续
	return 0;
}

