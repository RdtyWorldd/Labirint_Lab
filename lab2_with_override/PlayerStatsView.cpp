#include "PlayerStatsView.h"

void PlayerStatsView::event(Game& model) {
	Player& player = model.getPlayer();
	out << "HP: " << player.getHP() << " Treasure " << player.getTreasures() << endl;
}