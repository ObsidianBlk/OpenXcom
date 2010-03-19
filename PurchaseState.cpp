/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "PurchaseState.h"

PurchaseState::PurchaseState(Game *game) : State(game)
{
	// Create objects
	_window = new Window(320, 200, 0, 0);
	_btnOk = new Button(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 148, 16, 8, 176);
	_btnCancel = new Button(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 148, 16, 164, 176);
	_txtTitle = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 310, 13, 5, 8);
	_txtFunds = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 10, 24);
	_txtPurchases = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 150, 9, 160, 24);
	_txtItem = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 140, 9, 10, 32);
	_txtCost = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 102, 9, 152, 32);
	_txtQuantity = new Text(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 60, 9, 256, 32);
	_lstItems = new TextList(game->getFont("BIGLETS.DAT"), game->getFont("SMALLSET.DAT"), 300, 128, 10, 40);
	
	// Set palette
	_game->setPalette(_game->getPalette("BACKPALS.DAT")->getColors(Palette::blockOffset(0)), Palette::backPos, 16);

	add(_window);
	add(_btnOk);
	add(_btnCancel);
	add(_txtTitle);
	add(_txtFunds);
	add(_txtPurchases);
	add(_txtItem);
	add(_txtCost);
	add(_txtQuantity);
	add(_lstItems);

	// Set up objects
	_window->setColor(Palette::blockOffset(13)+13);
	_window->setBg(game->getSurface("BACK13.SCR"));

	_btnOk->setColor(Palette::blockOffset(13)+13);
	_btnOk->setText(_game->getLanguage()->getString(76));
	_btnOk->onMouseClick((EventHandler)&PurchaseState::btnOkClick);

	_btnCancel->setColor(Palette::blockOffset(13)+13);
	_btnCancel->setText(_game->getLanguage()->getString(71));
	_btnCancel->onMouseClick((EventHandler)&PurchaseState::btnCancelClick);

	_txtTitle->setColor(Palette::blockOffset(13)+10);
	_txtTitle->setBig();
	_txtTitle->setAlign(ALIGN_CENTER);
	_txtTitle->setText(_game->getLanguage()->getString(123));

	_txtFunds->setColor(Palette::blockOffset(13)+10);
	_txtFunds->setText(_game->getLanguage()->getString(124));

	_txtPurchases->setColor(Palette::blockOffset(13)+10);
	_txtPurchases->setText(_game->getLanguage()->getString(125));

	_txtItem->setColor(Palette::blockOffset(13)+10);
	_txtItem->setText(_game->getLanguage()->getString(97));

	_txtCost->setColor(Palette::blockOffset(13)+10);
	_txtCost->setText(_game->getLanguage()->getString(126));

	_txtQuantity->setColor(Palette::blockOffset(13)+10);
	_txtQuantity->setText(_game->getLanguage()->getString(127));

	_lstItems->setColor(Palette::blockOffset(13)+10);
	_lstItems->setColumns(3, 162, 92, 40);
	_lstItems->addRow(3, "Soldier", "40 000", "0");
}

PurchaseState::~PurchaseState()
{
	
}

void PurchaseState::think()
{
}

void PurchaseState::btnOkClick(SDL_Event *ev, int scale)
{
	_game->setState(new BasescapeState(_game));
}

void PurchaseState::btnCancelClick(SDL_Event *ev, int scale)
{
	_game->setState(new BasescapeState(_game));
}