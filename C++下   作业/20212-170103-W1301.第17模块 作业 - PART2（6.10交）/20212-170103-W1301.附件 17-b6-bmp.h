/* �༶ ѧ�� ���� */

#pragma once

/* ������Ҫ�����Լ��Ķ��� */

class bitmap_image
{
protected:
    /* ������Ҫ�����Լ��Ķ��� */

public:
    int width() const;	//����ͼƬ�Ŀ��
    int height() const; //����ͼƬ�ĸ߶�
    unsigned int get_pixel(int row, int col) const; //����ָ�����RGB��ɫ

    /* ������Ҫ�����Լ��Ķ��� */

};