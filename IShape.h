#pragma once

class IShape
{
public:
	//�ʐς����߂�֐�
	virtual void Size() = 0;
	//���߂��ʐς�\������֐�
	virtual void Draw() = 0;
};