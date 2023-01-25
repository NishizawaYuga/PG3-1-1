#pragma once

class IShape
{
public:
	//面積を求める関数
	virtual void Size() = 0;
	//求めた面積を表示する関数
	virtual void Draw() = 0;
};