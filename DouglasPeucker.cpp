#include "DouglasPeucker.h"

double DouglasPeucker::PerpendicularDistance(MyPointStruct &point1, MyPointStruct &point2, MyPointStruct &point3)
{
  // 点到直线的距离公式法
	double A, B, C, maxDist = 0;
	A = point2.Y - point1.Y;
	B = point1.X - point2.X;
	C = point2.X * point1.Y - point1.X * point2.Y;
	maxDist = fabs((A * point3.X + B * point3.Y + C) / sqrt(A * A + B * B));
	return maxDist;
}

MyPointStruct DouglasPeucker::myConvert(int index)
{
	return PointStruct[index];
}

void DouglasPeucker::DouglasPeuckerReduction(int firstPoint, int lastPoint, double tolerance)
{
	double maxDistance = 0;
	int indexFarthest = 0;  // 记录最大值时点元素在数组中的下标

	for (int index = firstPoint; index < lastPoint; index++)
	{
		double distance = PerpendicularDistance(myConvert(firstPoint), myConvert(lastPoint), myConvert(index));

		if (distance > maxDistance)
		{
			maxDistance = distance;
			indexFarthest = index;
		}
	}
	if (maxDistance > tolerance && indexFarthest != 0) 
	{
		myTag[indexFarthest] = true; // 记录特征点的索引信息

		DouglasPeuckerReduction(firstPoint, indexFarthest, tolerance);
		DouglasPeuckerReduction(indexFarthest, lastPoint, tolerance);
	}
}

DouglasPeucker::DouglasPeucker(vector<MyPointStruct> &Points,int tolerance)
{
	PointStruct = Points;
	int totalPointNum =Points.size();

	myTag.resize(totalPointNum,0);

	DouglasPeuckerReduction(0, totalPointNum-1, tolerance);

	for (int index = 0; index<totalPointNum; index++)
	{
		if(myTag[index])PointNum.push_back(index);
	}
}
void DouglasPeucker::WriteData(const char *filename)
{
	FILE *fp = fopen(filename,"w");
	int pSize = PointNum.size();
	for(int index=0;index<pSize;index++)
	{
		fprintf(fp,"%lf\t%lf\n",PointStruct[PointNum[index]].X,PointStruct[PointNum[index]].Y);
	}
}
