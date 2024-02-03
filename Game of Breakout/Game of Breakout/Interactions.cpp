#include"Interactions.h"

bool is_interacting(const entity& e1, const entity& e2) {

	auto box1 = e1.get_bounding_box();
	auto box2 = e2.get_bounding_box();
	return box1.intersects(box2);

}

void handle_collision(ball& b, const Paddle& p) {

	if (is_interacting(p, b)) {

		b.move_up();


		if (b.x() < p.x()) {

			b.move_left();
		}
		else {
			b.move_right();
		}



	}


}


void handle_collision(ball& b, brick& br) {
	if (is_interacting(b, br)) {

		br.set_destroyed(true);


		float left_overlap = b.right() - br.left();
		float right_overlap = br.right() - b.left();
		float top_overlap = b.bottom() - br.top();
		float bottom_overlap = br.bottom() - b.top();

		bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
		bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

		float min_x_overlap = from_left ? left_overlap : right_overlap;
		float min_y_overlap = from_top ? top_overlap : bottom_overlap;

		if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
			if (from_left) {
				b.move_left();
			}
			else {
				b.move_right();
			}

		}
		else {
			if (from_top) {
				b.move_up();
			}
			else {
				b.move_down();
			}

		}

	}


}