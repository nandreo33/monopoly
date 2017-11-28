#include <string>
#include <iostream>

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
	const int purchase_cost;
	const int building_cost;
	const int num_properties;
	const color_t color;
public:
	color_t get_color_type() const {	return color;};
	int get_building_cost() const {	return building_cost;};
	int get_purchase_cost() const {	return purchase_cost;};
	ColorGroup(int p_c, int b_c, int n_p, color_t col) : 
		purchase_cost(p_c),		//how much does it cost to buy a prop of this group?
		building_cost(b_c),	 	//how much does it cost to build on this group?
		num_properties(n_p),	//how many properties in the group?
		color(col)				//what color_t (enum) is the group?
	{};
};