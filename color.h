#include <string>
#include <iostream>
#ifndef COLOR_H
#define COLOR_H

enum color_t 
{	
	brown, 
	light_blue, 
	purple, 
	orange, 
	red, 
	yellow, 
	green, 
	blue,
	railroad,
	utility
};

class ColorGroup
{
private:
	const int building_cost;
	const int group_size;
	const color_t color;
public:
	color_t get_color_type() const {	return color;};
	int get_building_cost() const {	return building_cost;};
	int get_group_size() const {	return group_size;};
	ColorGroup(int b_c, int n_p, color_t col) : 
		building_cost(b_c),	 	//how much does it cost to build on this group?
		group_size(n_p),	//how many properties in the group?
		color(col)				//what color_t (enum) is the group?
	{};
};


#endif