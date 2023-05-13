/* 班级 学号 姓名 */

#pragma once

/* 根据需要加入自己的定义 */

class bitmap_image
{
protected:
    /* 根据需要加入自己的定义 */

public:
    int width() const;	//返回图片的宽度
    int height() const; //返回图片的高度
    unsigned int get_pixel(int row, int col) const; //返回指定点的RGB颜色

    /* 根据需要加入自己的定义 */

};