#ifndef DOUGLAGPEUCKER
#define DOUGLAGPEUCKER

#include <math.h>
#include <vector>
using namespace std;

struct MyPointStruct  // 点的结构
{
public: 
  double X;
	double Y;
	double Z;
	MyPointStruct()
	{
		this->X = 0;
		this->Y = 0;
		this->Z = 0;
	};

	MyPointStruct(double x, double y, double z)  // 点的构造函数
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
	};
	~MyPointStruct(){};
};

class DouglasPeucker
{
public:
	vector<MyPointStruct> PointStruct;
	vector<bool> myTag; // 标记特征点的一个bool数组
	vector<int> PointNum;//离散化得到的点号
	DouglasPeucker(void){};
	DouglasPeucker(vector<MyPointStruct> &Points,int tolerance);
	~DouglasPeucker(){};

	void WriteData(const char *filename);
private:
	void DouglasPeuckerReduction(int firstPoint, int lastPoint, double tolerance);
	double PerpendicularDistance(MyPointStruct &point1, MyPointStruct &point2, MyPointStruct &point3);
	MyPointStruct myConvert(int index);
};


#endif
