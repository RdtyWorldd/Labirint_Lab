#include "PlayerStepsView.h"

void PlayerStepsView::event(Game& model)
{
	out << "Steps: " << model.getPlayer().getSteps() << endl;
}
