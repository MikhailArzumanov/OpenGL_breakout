#include "main_program_functions.hpp"
#include "the_net.hpp"

constexpr float net_width		 = 70;
constexpr float net_height		 = 23;
constexpr float upper_padding	 = 38;
constexpr float lower_padding	 = 272;
constexpr float left_padding	 = 11 + net_width/2;
constexpr float net_right_margin = 38;
constexpr float net_lower_margin = 38;

constexpr int	row_size		 = 12;
constexpr int	rows_amount		 = 7;


void init_net() {
	for (int Y = 0; Y < rows_amount; Y++) {
		for (int X = 0; X < row_size; X++) {
			the_net.push_back(new Net(
			{
				left_padding  + X*(net_width +net_right_margin),
				lower_padding + Y*(net_height+net_lower_margin)
			}
			));
		}
	}
}