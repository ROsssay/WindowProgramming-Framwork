#pragma once
#include "GameObject.h"
#include "Food.h"

class Enemy : public GameObject
{
public:
	Enemy();
	void Update(std::vector<Food>& foods);
	void LateUpdate() override;
	void Render(HDC hdc) override;

	
	void SetPosition(float x, float y) override
	{
		mX = x;
		mY = y;
	}
	void Setradius(float r) override
	{
		float oldRadius = radius;
		float deltaRadius = r - oldRadius; // ��Ÿ �� ���

		if (deltaRadius < 0) // �������� �۾�����
		{
			speed += 2.5f; // ���� ���� ����
		}
		else if (deltaRadius > 0) // �������� Ŀ����
		{
			// ��Ÿ ���� ����Ͽ� �ӵ� ���� (���� �������� ���������� ���)
			float speedReduction = deltaRadius * 1.1f; // ��Ÿ ���� 2��� ����
			speed -= speedReduction;

			// �ּ� �ӵ� ����
			if (speed < 20.0f)
			{
				speed = 20.0f;
			}
		}

		// ������ ������Ʈ
		radius = r;
	}
	void SetSpeed(float s) override
	{
		speed = s;
	}
	void SetColor(COLORREF c) override
	{
		color = c;
	}
	float GetPositionX() override;
	float GetPositionY() override;
	float GetSpeed() override;
	COLORREF GetColor() override;
	float GetRadius() override;
	RECT GetRect() override;
private:
	float mX;
	float mY;
	float radius;
	float speed;
	RECT rect;
	COLORREF color;


};

